#ifndef EXPR_HPP
#define EXPR_HPP

#include <memory>
#include <string>

class NodeBase {
 public:
  // Make any of these functions virtual, or pure virtual, if necessary.
  NodeBase() = default;
  virtual double eval(double x) const;
  virtual std::string rep() const;
  virtual double derivative(double ) const;
  virtual ~NodeBase() = default;
};

class Expr {
  std::shared_ptr<NodeBase> m_ptr;

 public:
  Expr(double value);

  Expr(std::shared_ptr<NodeBase> ptr) : m_ptr{ptr} {}

  Expr(const Expr& other) : Expr(other.m_ptr) {}
  Expr& operator= (const Expr& other) {
    if (m_ptr != other.m_ptr) {
      m_ptr = other.m_ptr;
    }
    return *this;
  }

  Expr(Expr &&other) noexcept: m_ptr(other.m_ptr) {
    other.m_ptr = nullptr;
  }
  Expr &operator= (Expr &&other) noexcept {
    if (m_ptr != other.m_ptr) {
      m_ptr = other.m_ptr;
      other.m_ptr = nullptr;
    }
    return *this;
  }

  virtual ~Expr() = default;

  // Add member functions if necessary.

  static const Expr x;

  virtual double eval(double x) const {
    return m_ptr->eval(x);
  }

  virtual double derivative(double x) const {
    return m_ptr->derivative(x);
  }

  virtual std::string rep() const {
    return m_ptr->rep();
  }

  // Add friend declarations if necessary.
};

class Variable : public NodeBase {
public:
  // Add functions if necessary.
    virtual double eval(double x) const override;
    virtual double derivative(double x) const override;
    virtual std::string rep() const override;
};

class Constant : public NodeBase {
  double m_value;

  // Add functions if necessary.

 public:
  Constant(double value) : m_value{value} {}

  virtual double eval(double x) const override;
  virtual double derivative(double x) const override;
  virtual std::string rep() const override;
};

class UnaryOperator : public NodeBase {
  char m_op;
  Expr m_operand;

  // Add functions if necessary.

 public:
  UnaryOperator(char op, const Expr &operand) : m_op{op}, m_operand{operand} {}

  virtual double eval(double x) const override;
  virtual double derivative(double x) const override;
  virtual std::string rep() const override;
};

class BinaryOperator : public NodeBase {
  protected:
    Expr m_left;
    Expr m_right;

  public:
    BinaryOperator(const Expr &left, const Expr &right)
        : m_left{left}, m_right{right} {}
};

class PlusOp : public BinaryOperator {
  using BinaryOperator::BinaryOperator;

  // Add functions if necessary.
  virtual double eval(double x) const override;
  virtual double derivative(double x) const override;
  virtual std::string rep() const override;
};

class MinusOp : public BinaryOperator {
  using BinaryOperator::BinaryOperator;
  
  // Add functions if necessary.
  virtual double eval(double x) const override;
  virtual double derivative(double x) const override;
  virtual std::string rep() const override;
};

class MultiplyOp : public BinaryOperator {
  using BinaryOperator::BinaryOperator;
  
  // Add functions if necessary.
  virtual double eval(double x) const override;
  virtual double derivative(double x) const override;
  virtual std::string rep() const override;
};

class DivideOp : public BinaryOperator {
  using BinaryOperator::BinaryOperator;
  
  // Add functions if necessary.
  virtual double eval(double x) const override;
  virtual double derivative(double x) const override;
  virtual std::string rep() const override;
};


const Expr Expr::x{std::make_shared<Variable>()};

Expr::Expr(double value) : m_ptr{std::make_shared<Constant>(value)} {}


std::string NodeBase::rep() const {
  return "";
}
std::string Variable::rep() const{
  return "x";
}
std::string Constant::rep() const {
  return std::to_string(m_value);
}
std::string UnaryOperator::rep() const {
  if (m_op == '+') {
    return "+(" + m_operand.rep() + ")";
  } else {
    return "-(" + m_operand.rep() + ")";
  }
}
std::string PlusOp::rep() const {
  return "(" + m_left.rep() + ") + (" + m_right.rep() + ")";
}
std::string MinusOp::rep() const {
  return "(" + m_left.rep() + ") - (" + m_right.rep() + ")";
}
std::string MultiplyOp::rep() const {
  return "(" + m_left.rep() + ") * (" + m_right.rep() + ")";
}
std::string DivideOp::rep() const {
  return "(" + m_left.rep() + ") / (" + m_right.rep() + ")";
}


double NodeBase::eval(double ) const {
  return 0.0;
}
double Variable::eval(double x) const {
  return x;
}
double Constant::eval(double ) const {
  return m_value;
}
double UnaryOperator::eval(double x) const {
  return (m_op == '+') ? m_operand.eval(x) : -m_operand.eval(x);
}
double PlusOp::eval(double x) const {
  return m_left.eval(x) + m_right.eval(x);
}
double MinusOp::eval(double x) const {
  return m_left.eval(x) - m_right.eval(x);
}
double MultiplyOp::eval(double x) const {
  return m_left.eval(x) * m_right.eval(x);
}
double DivideOp::eval(double x) const {
  return m_left.eval(x) / m_right.eval(x);
}


double NodeBase::derivative(double ) const {
  return 0.0;
}
double Variable::derivative(double ) const {
  return 1.0;
}
double Constant::derivative(double ) const {
  return 0.0;
}
double UnaryOperator::derivative(double x) const {
  return (m_op == '+') ? m_operand.derivative(x) : -m_operand.derivative(x);
}
double PlusOp::derivative(double x) const {
  double left_derivative = m_left.derivative(x);
  double right_derivative = m_right.derivative(x);
  return left_derivative + right_derivative;
}
double MinusOp::derivative(double x) const {
  double left_derivative = m_left.derivative(x);
  double right_derivative = m_right.derivative(x);
  return left_derivative - right_derivative;
}
double MultiplyOp::derivative(double x) const {
  double f = m_left.eval(x);
  double g = m_right.eval(x);
  double df = m_left.derivative(x);
  double dg = m_right.derivative(x);
  return (df * g + f * dg);
}
double DivideOp::derivative(double x) const {
  double f = m_left.eval(x);
  double g = m_right.eval(x);
  double df = m_left.derivative(x);
  double dg = m_right.derivative(x);
  return (df * g - f * dg) / (g * g);
}


Expr operator-(const Expr &operand) {
  return {std::make_shared<UnaryOperator>('-', operand)};
}

Expr operator+(const Expr &operand) {
  return {std::make_shared<UnaryOperator>('+', operand)};
}

Expr operator+(const Expr &left, const Expr &right) {
  // Your code here.
  return {std::make_shared<PlusOp>(left, right)};
}

Expr operator-(const Expr &left, const Expr &right) {
  // Your code here.
  return {std::make_shared<MinusOp>(left, right)};
}

Expr operator*(const Expr &left, const Expr &right) {
  // Your code here.
  return {std::make_shared<MultiplyOp>(left, right)};
}

Expr operator/(const Expr &left, const Expr &right) {
  // Your code here.
  return {std::make_shared<DivideOp>(left, right)};
}

#endif // EXPR_HPP