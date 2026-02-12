#include <iostream>

double computeDiscriminant(double a, double b, double c);
double applyQuadraticFormula(double a, double b, double c, int sign);
int numberOfSolutions(double discriminant);
double readDoubleFromStream(std::istream &stream);

const std::string MSG = "a must not be zero";

int main() {

  try {
    double r = applyQuadraticFormula(1.0, 2.0, 3.0, 1);
  } catch (...) {
    std::cout << "applyQuadraticFormula() must not throw exception in normal "
                 "operation\n";
    return 1;
  }

  bool gotRuntimeErr = false;
  try {
    double r = applyQuadraticFormula(0.0, 2.0, 3.0, 1);
  } catch (std::runtime_error &err) {
    gotRuntimeErr = true;
    if (MSG.compare(err.what())) {
      std::cout << "applyQuadraticFormula() threw exception with incorrect "
                   "error message\n";
      return 1;
    }
  } catch (...) {
    std::cout << "applyQuadraticFormula() threw wrong kind of exception\n";
    return 1;
  }

  if (gotRuntimeErr) {
    std::cout << "applyQuadraticFormula() tested successfully!\n";
    return 0;
  } else {
    std::cout << "applyQuadraticFormula() should have thrown exception with a "
                 "== 0.0\n";
  }

  return 1;
}