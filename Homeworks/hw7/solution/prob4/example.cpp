#include "expr.hpp"
#include <iostream>

int main() {
  auto &x = Expr::x;
  Expr f = 1;
  std::cout << f.rep() << std::endl;
  std::cout << f.eval(0) << std::endl;
  std::cout << f.derivative(1) << std::endl;
  auto g = f / x;
  std::cout << g.rep() << std::endl;
  std::cout << g.eval(3) << std::endl;
  std::cout << g.derivative(3) << std::endl;
  auto h = 2 * x + 3;
  std::cout << h.rep() << std::endl;
  std::cout << h.derivative(3) << std::endl;
  return 0;
}