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

  virtual void setA(){};
  virtual void setB(){};

public:
  std::string getOut() const;
  virtual void setA(valType val){};
  virtual std::string getA() const;
  virtual void setB(valType val){};
  virtual std::string getB() const;
  virtual std::optional<valType> execute();
  bool operator>(const Gate &left) const;
  bool operator>=(const Gate &left) const;
  virtual bool isOneEntry() const;
};

class OneInput : public Gate {
protected:
  std::string a_name;
  bool a_set;
  valType a;

  void setA() override;

public:
  OneInput(const std::string &a, const std::string &out);
  void setA(valType val) override;
  std::string getA() const override;
  virtual bool isOneEntry() const override;
};

class TwoInputs : public OneInput {
protected:
  std::string b_name;
  bool b_set;
  valType b;

  void setB() override;

public:
  TwoInputs(const std::string &a, const std::string &b, const std::string &out);
  void setB(valType val) override;
  std::string getB() const override;
  bool isOneEntry() const override;
};

class Set : public OneInput {
public:
  Set(const std::string &a, const std::string &out);
  std::optional<valType> execute() override;
};

class Not : public OneInput {
public:
  Not(const std::string &a, const std::string &out);
  std::optional<valType> execute() override;
};

class And : public TwoInputs {
public:
  And(const std::string &a, const std::string &b, const std::string &out);
  std::optional<valType> execute() override;
};

class Or : public TwoInputs {
public:
  Or(const std::string &a, const std::string &b, const std::string &out);
  std::optional<valType> execute() override;
};

class LShift : public TwoInputs {
public:
  LShift(const std::string &a, const std::string &b, const std::string &out);
  std::optional<valType> execute() override;
};

class RShift : public TwoInputs {
public:
  RShift(const std::string &a, const std::string &b, const std::string &out);
  std::optional<valType> execute() override;
};
} // namespace d7v
