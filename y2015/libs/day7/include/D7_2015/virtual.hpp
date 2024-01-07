#pragma once

#include <optional>
#include <string>

namespace d7v {
typedef unsigned short valType;

enum gateType {
  SetGate,
  NotGate,
  AndGate,
  OrGate,
  LeftShift,
  RightShift,
};

class Gate {
protected:
  unsigned int priority;
  std::string out;
  gateType type;

  virtual void setA();
  virtual void setB();

public:
  std::string getOut() const;
  virtual void setA(valType val);
  virtual std::string getA() const;
  virtual std::optional<valType> execute();
  bool operator>(const Gate &left) const;
  bool operator>=(const Gate &left) const;
  virtual bool isOneEntry() const;
};

class OneInput: protected Gate {
protected:
  std::string a_name;
  bool a_set;
  valType a;

  void setA() override;
  
public:
  void setA(valType val) override;
  std::string getA() const override;
  virtual bool isOneEntry() const override;
};
} // namespace d7v
