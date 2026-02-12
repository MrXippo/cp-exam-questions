#include "reverse.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> revVector;

  std::cout << "Please enter some integer values:\n";
  bool ok = true;
  do {
    int nextValue;
    std::cin >> nextValue;
    ok = std::cin.good();
    if (ok) {
      revVector.push_back(nextValue);
    }
  } while (ok);

  // Reverse
  reverse(revVector);

  // Print values
  std::cout << std::endl << "Reversed values: ";
  for (int i = 0; i < revVector.size(); ++i) {
    std::cout << " " << revVector.at(i);
  }
  std::cout << std::endl;

  return 0;
}