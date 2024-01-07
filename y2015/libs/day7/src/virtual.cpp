#include "virtual.hpp"

namespace d7v {
void OneInput::setA() {
  try {
    this->a = (valType)std::stoi(this->a_name);
    this->a_set = true;
  } catch (...) {
    this->a_set = false;
  }
}

std::string Gate::getOut() const {
  return out;
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
}
