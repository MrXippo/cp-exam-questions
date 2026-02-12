#include <iostream>

double computeDiscriminant(double a, double b, double c);
double applyQuadraticFormula(double a, double b, double c, int sign);
int numberOfSolutions(double discriminant);
double readDoubleFromStream(std::istream &stream);

int solveQuadraticFormula(std::istream &input) {
  const int POSITIVE = 1, NEGATIVE = -1;

  double a, b, c;

  std::cout << "Please enter the values of a, b, and c: ";
  a = readDoubleFromStream(input);
  b = readDoubleFromStream(input);
  c = readDoubleFromStream(input);

  const double discriminant = computeDiscriminant(a, b, c);

  switch (numberOfSolutions(discriminant)) {
  case 2: {
    double first_solution = applyQuadraticFormula(a, b, c, POSITIVE);
    double second_solution = applyQuadraticFormula(a, b, c, NEGATIVE);
    std::cout << "There are 2 solutions." << std::endl;
    std::cout << "The solutions are: " << first_solution << " and "
              << second_solution << std::endl;
    break;
  }
  case 1: {
    double the_solution = applyQuadraticFormula(a, b, c, POSITIVE);
    std::cout << "There is 1 solution." << std::endl;
    std::cout << "The solution is: " << the_solution << std::endl;
    break;
  }
  case 0:
    std::cout << "There is no solution." << std::endl;
    break;
  }
  
  return 0;
}