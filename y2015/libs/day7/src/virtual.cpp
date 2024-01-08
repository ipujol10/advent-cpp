#include "virtual.hpp"

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
} // namespace d7v
