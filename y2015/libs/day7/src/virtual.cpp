#include "virtual.hpp"

namespace d7v {
  std::string Gate::getOut() const {
    return out;
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

std::string OneInput::getA() const {
  return a_name;
}

bool OneInput::isOneEntry() const {
  return true;
}

void TwoInputs::setB() {
  try {
    this->b = (valType)std::stoi(this->a_name);
    this->a_set = true;
  } catch(...) {
    this->a_set = false;
  }
}

void TwoInputs::setB(valType val) {
  b_set = true;
  b = val;
}

std::string TwoInputs::getB() const {
  return b_name;
}

bool TwoInputs::isOneEntry() const {
  return false;
}
}
