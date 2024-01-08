#include "virtual.hpp"

namespace d7v {
std::string Gate::getOut() const { return out; }

bool Gate::operator>(const Gate &left) const {
  return this->priority > left.priority;
}

bool Gate::operator>=(const Gate &left) const {
  return this->priority >= left.priority;
}

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
    this->b = (valType)std::stoi(this->a_name);
    this->a_set = true;
  } catch (...) {
    this->a_set = false;
  }
}

void TwoInputs::setB(valType val) {
  b_set = true;
  b = val;
}

std::string TwoInputs::getB() const { return b_name; }

bool TwoInputs::isOneEntry() const { return false; }

SetGate::SetGate(const std::string &a, const std::string &out)
    : OneInput(a, out) {
  priority = 0;
  type = gateType::SetGate;
}

std::optional<valType> SetGate::execute() {
  priority++;
  if (!a_set) {
    return {};
  }
  return a;
}

NotGate::NotGate(const std::string &a, const std::string &out)
    : OneInput(a, out) {
  priority = 5;
  type = gateType::NotGate;
}

std::optional<valType> NotGate::execute() {
  priority++;
  if (!a_set) {
    return {};
  }
  return ~a;
}

AndGate::AndGate(const std::string &a, const std::string &b,
                 const std::string &out)
    : TwoInputs(a, b, out) {
  priority = 15;
  type = gateType::AndGate;
}

std::optional<valType> AndGate::execute() {
  priority++;
  if (!(a_set && b_set)) {
    return {};
  }
  return a & b;
}

OrGate::OrGate(const std::string &a, const std::string &b,
               const std::string &out)
    : TwoInputs(a, b, out) {
  priority = 15;
  type = gateType::OrGate;
}

std::optional<valType> OrGate::execute() {
  priority++;
  if (!(a_set && b_set)) {
    return {};
  }
  return a | b;
}

LeftShift::LeftShift(const std::string &a, const std::string &b,
                     const std::string &out)
    : TwoInputs(a, b, out) {
  priority = 10;
  type = gateType::LeftShift;
}

std::optional<valType> LeftShift::execute() {
  priority++;
  if (!(a_set && b_set)) {
    return {};
  }
  return a << b;
}

RightShift::RightShift(const std::string &a, const std::string &b,
                       const std::string &out)
    : TwoInputs(a, b, out) {
  priority = 10;
  type = gateType::RightShift;
}

std::optional<valType> RightShift::execute() {
  priority++;
  if (!(a_set && b_set)) {
    return {};
  }
  return a >> b;
}
} // namespace d7v
