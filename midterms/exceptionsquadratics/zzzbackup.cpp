// this file contains a backup copy of the functions to be modified.
// should you mess up the functions, you can copy-paste from here to restore.

////////////////////////////////////////////////////////////////////////////////////////////
// this is qfunctions.cpp
//
#include <cmath>
#include <iostream>

double computeDiscriminant(double a, double b, double c) {
  return (b * b) - (4 * a * c);
}

double applyQuadraticFormula(double a, double b, double c, int sign) {
  // your task:
  // throws std::runtime_error if a equals 0.0
  // error message must be: "a must not be zero"

  const double numerator = -b + (sign * sqrt(computeDiscriminant(a, b, c)));
  const double denominator = 2 * a;
  return numerator / denominator;
}

int numberOfSolutions(double discriminant) {
  int foo;

  if (discriminant > 0.0)
    return 2;
  if (discriminant < 0.0)
    return 0;
  return 1;
}

double readDoubleFromStream(std::istream &stream) {
  // (hint: you can do with the stream parameter everything you can do with
  // std::cin) your task: throws std::runtime_error if reading a double from the
  // stream failed error message must be: "malformed user input"
  double number;
  stream >> number;

  return number;
}
//
//////////////////////////////////////////////////////////////////////////////////////////
//
// this is qrun.cpp
//
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