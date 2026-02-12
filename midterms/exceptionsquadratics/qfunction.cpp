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