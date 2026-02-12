#include <iostream>
#include <sstream>

double computeDiscriminant(double a, double b, double c);
double applyQuadraticFormula(double a, double b, double c, int sign);
int numberOfSolutions(double discriminant);
double readDoubleFromStream(std::istream &stream);

const std::string MSG = "malformed user input";

int main() {

  std::istringstream is("42.0");

  try {
    double r = readDoubleFromStream(is);
  } catch (...) {
    std::cout << "readDoubleFromStream() must not throw exception in normal "
                 "operation\n";
    return 1;
  }

  std::istringstream iserr("fourty two");
  bool gotRuntimeErr = false;
  try {
    double r = readDoubleFromStream(iserr);
  } catch (std::runtime_error &err) {
    gotRuntimeErr = true;
    if (MSG.compare(err.what())) {
      std::cout << "readDoubleFromStream() threw exception with incorrect "
                   "error message\n";
      return 1;
    }
  } catch (...) {
    std::cout << "readDoubleFromStream() threw wrong kind of exception\n";
    return 1;
  }

  if (gotRuntimeErr) {
    std::cout << "readDoubleFromStream() tested successfully!\n";
    return 0;
  } else {
    std::cout << "readDoubleFromStream() should have thrown exception with "
                 "invalid input\n"; // CHANGED FOR DEBUG; ADDED r
  }

  return 1;
}