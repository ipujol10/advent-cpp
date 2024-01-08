#include "virtual.hpp"
#include <fstream>
#include <iostream>
#include <regex>

namespace d7v {
std::string Gate::getOut() const { return out; }

bool Gate::operator>(const Gate &left) const {
  return this->priority > left.priority;
}

bool Gate::operator>=(const Gate &left) const {
  return this->priority >= left.priority;
}

std::string Gate::getA() const { return "Gate A"; }

std::string Gate::getB() const { return "Gate B"; }

std::optional<valType> Gate::execute() { return {}; }

bool Gate::isOneEntry() const { return false; }

OneInput::OneInput(const std::string &a, const std::string &out) : a_name(a) {
  this->out = out;
  setA();
}

void OneInput::setA() {
  try {
    this->a = (valType)std::stoi(this->a_name);
    this->a_set = true;
  } catch (...) {
    this->a_set = false;
  }
}

void OneInput::setA(valType val) {
  a_set = true;
  a = val;
}

std::string OneInput::getA() const { return a_name; }

bool OneInput::isOneEntry() const { return true; }

TwoInputs::TwoInputs(const std::string &a, const std::string &b,
                     const std::string &out)
    : OneInput(a, out), b_name(b) {
  setB();
}

void TwoInputs::setB() {
  try {
    this->b = (valType)std::stoi(this->b_name);
    this->b_set = true;
  } catch (...) {
    this->b_set = false;
  }
}

void TwoInputs::setB(valType val) {
  b_set = true;
  b = val;
}

std::string TwoInputs::getB() const { return b_name; }

bool TwoInputs::isOneEntry() const { return false; }

Set::Set(const std::string &a, const std::string &out) : OneInput(a, out) {
  priority = 0;
  type = gateType::SetGate;
}

std::optional<valType> Set::execute() {
  priority++;
  if (!a_set) {
    return {};
  }
  return a;
}

Not::Not(const std::string &a, const std::string &out) : OneInput(a, out) {
  priority = 5;
  type = gateType::NotGate;
}

std::optional<valType> Not::execute() {
  priority++;
  if (!a_set) {
    return {};
  }
  return ~a;
}

And::And(const std::string &a, const std::string &b, const std::string &out)
    : TwoInputs(a, b, out) {
  priority = 15;
  type = gateType::AndGate;
}

std::optional<valType> And::execute() {
  priority++;
  if (!(a_set && b_set)) {
    return {};
  }
  return a & b;
}

Or::Or(const std::string &a, const std::string &b, const std::string &out)
    : TwoInputs(a, b, out) {
  priority = 15;
  type = gateType::OrGate;
}

std::optional<valType> Or::execute() {
  priority++;
  if (!(a_set && b_set)) {
    return {};
  }
  return a | b;
}

LShift::LShift(const std::string &a, const std::string &b,
               const std::string &out)
    : TwoInputs(a, b, out) {
  priority = 10;
  type = gateType::LeftShift;
}

std::optional<valType> LShift::execute() {
  priority++;
  if (!(a_set && b_set)) {
    return {};
  }
  return a << b;
}

RShift::RShift(const std::string &a, const std::string &b,
               const std::string &out)
    : TwoInputs(a, b, out) {
  priority = 10;
  type = gateType::RightShift;
}

std::optional<valType> RShift::execute() {
  priority++;
  if (!(a_set && b_set)) {
    return {};
  }
  return a >> b;
}

MinHeap::MinHeap() : length(0) {}

void MinHeap::insert(Gate *value) {
  data[length] = value;
  heapifyUp(length);
  length++;
}

Gate *MinHeap::pop() {
  if (length == 0) {
    throw -1;
  }
  const auto out = data[0];
  length--;
  if (length == 0) {
    return out;
  }

  data[0] = data[length];
  heapifyDown(0);

  return out;
}

void MinHeap::heapifyDown(int idx) {
  int lIdx = leftChild(idx);
  int rIdx = rightChild(idx);

  if (idx >= length || lIdx >= length) {
    return;
  }

  auto lV = data[lIdx];
  auto rV = data[rIdx];
  auto v = data[idx];

  if (*lV >= *rV && *v > *rV) {
    data[idx] = rV;
    data[rIdx] = v;
    heapifyDown(rIdx);
  } else if (*rV >= *lV && *v > *lV) {
    data[idx] = lV;
    data[lIdx] = v;
    heapifyDown(lIdx);
  }
}

void MinHeap::heapifyUp(int idx) {
  if (idx == 0) {
    return;
  }

  int p = parent(idx);
  auto parentV = data[p];
  auto v = data[idx];
  if (*parentV > *v) {
    data[idx] = parentV;
    data[p] = v;
    heapifyUp(p);
  }
}

int MinHeap::parent(int idx) const { return (idx - 1) / 2; }

int MinHeap::leftChild(int idx) const { return idx * 2 + 1; }

int MinHeap::rightChild(int idx) const { return idx * 2 + 2; }

bool MinHeap::isEmpty() const { return length == 0; }

int MinHeap::getLength() const { return length; }

void Circuit::getElements(const std::string &in) {
  std::regex set("^([0-9a-z]+) -> ([a-z]+)$");
  std::regex andR("^([a-z0-9]+) AND ([a-z0-9]+) -> ([a-z]+)$");
  std::regex orR("^([a-z0-9]+) OR ([a-z0-9]+) -> ([a-z]+)$");
  std::regex lshift("^([a-z]+) LSHIFT ([0-9]+) -> ([a-z]+)$");
  std::regex rshift("^([a-z]+) RSHIFT ([0-9]+) -> ([a-z]+)$");
  std::regex notR("^NOT ([a-z]+) -> ([a-z]+)$");
  std::smatch matches;

  if (std::regex_match(in, matches, set)) {
    heap.insert(new Set(matches[1], matches[2]));
  } else if (std::regex_match(in, matches, notR)) {
    heap.insert(new Not(matches[1], matches[2]));
  } else if (std::regex_match(in, matches, andR)) {
    heap.insert(new And(matches[1], matches[2], matches[3]));
  } else if (std::regex_match(in, matches, orR)) {
    heap.insert(new Or(matches[1], matches[2], matches[3]));
  } else if (std::regex_match(in, matches, lshift)) {
    heap.insert(new LShift(matches[1], matches[2], matches[3]));
  } else if (std::regex_match(in, matches, rshift)) {
    heap.insert(new RShift(matches[1], matches[2], matches[3]));
  } else {
    std::cout << in << std::endl;
    std::cout << "SOMETHING WENT WRONG\n";
  }
}

bool Circuit::exists(const std::string &cable) const {
  return values.find(cable) != values.end();
}

std::optional<valType> Circuit::getNumber(const std::string &cable) const {
  if (!exists(cable)) {
    return {};
  }
  return values.at(cable);
}

void Circuit::readFromFile(const std::string &file_name) {
  std::string line;
  std::ifstream file(file_name);
  if (!file.good()) {
    std::cout << "The file doesn't exists\n";
  }
  while (std::getline(file, line)) {
    getElements(line);
  }
}

void Circuit::readFromFile(const std::string &file_name, const std::string &el,
                           valType value) {
  std::string line;
  std::ostringstream ss;
  ss << value;
  std::regex rgx("^[0-9]+ -> " + el + "$");
  std::ifstream file(file_name);
  std::smatch matches;
  while (std::getline(file, line)) {
    if (std::regex_match(line, matches, rgx)) {
      getElements(ss.str() + " -> " + el);
    } else {
      getElements(line);
    }
  }
}

void Circuit::pass() {
  std::string a, b, out;
  Gate *gate;
  while (!heap.isEmpty()) {
    gate = heap.pop();
    a = gate->getA();
    if (exists(a)) {
      gate->setA(values.at(a));
    }
    if (!gate->isOneEntry()) {
      b = gate->getB();
      if (exists(b)) {
        gate->setB(values.at(b));
      }
    }
    auto number = gate->execute();
    if (number) {
      values[gate->getOut()] = number.value();
    } else {
      heap.insert(gate);
    }
  }
}

valType Circuit::get(const std::string &cable) const {
  return values.at(cable);
}

bool Circuit::isNumber(const std::string &in) const {
  try {
    (void)std::stoi(in);
    return true;
  } catch (...) {
    return false;
  }
}
} // namespace d7v
