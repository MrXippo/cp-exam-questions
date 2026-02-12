#include "factorise.h"
#include <iostream>
#include <vector>

int main() {

  std::vector<int> result;

  for (int n = 1; n < 100; n++) {
    result = factorise(n);
    std::cout << n << " =  ";
    for (int i = 0; i < result.size(); i++) {
      std::cout << result.at(i);
      if (i < result.size() - 1) {
        std::cout << " * ";
      }
    }
    std::cout << "\n";
  }

  return 0;
}