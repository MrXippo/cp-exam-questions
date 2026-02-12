#include <iostream>
#include <sstream>

int solveQuadraticFormula(std::istream &input);

int main() {
  try {
    int result;
    std::istringstream is1("1.0 2.0 3.0");
    result = solveQuadraticFormula(is1);
    std::istringstream is2("0.0 2.0 3.0");
    result = solveQuadraticFormula(is2);
    std::istringstream is3("");
    result = solveQuadraticFormula(is3);
  } catch (...) {
    std::cout << "solveQuadraticFormula() must not throw any exceptions\n";
    return 1;
  }
  std::cout << "solveQuadraticFormula() tested successfully!\n";
  return 0;
}