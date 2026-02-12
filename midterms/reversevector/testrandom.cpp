#include "reverse.h"
#include <iostream>
#include <vector>

int random(int low, int high) {
  int diff = high - low;
  int result = rand() % diff;
  result += low;
  return result;
}

void printVector(std::vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    std::cout << " " << v.at(i);
  }
  std::cout << std::endl;
}

int main() {
  srand(time(0));

  const int SIZE = 17;
  std::vector<int> revVector(SIZE);

  for (int i = 0; i < SIZE; i++) {
    revVector.at(i) = random(-100, 100);
  }

  std::cout << "Randomly generated values:\n";
  printVector(revVector);

  std::vector<int> duplicate;
  duplicate = revVector;

  // Reverse
  reverse(revVector);

  for (int i = 0; i < SIZE; i++) {
    if (duplicate.at(i) != revVector.at(SIZE - i - 1)) {
      std::cout << "item at original index " << i << " (" << duplicate.at(i)
                << ") not properly placed in reversed vector\n";
      printVector(revVector);
      return 1;
    }
  }

  std::cout << "random vector reversed properly!\n";
  return 0;
}