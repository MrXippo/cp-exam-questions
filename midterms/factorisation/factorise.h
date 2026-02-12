#include <vector>
// #include<bits/stdc++.h>
/*
Each natural number, 1 or greater, can be written as the product of prime
numbers. (Special cases are the prime numbers themselves.)

For this assignment, write a function factorize(n) that returns a vector of
numbers that, when multiplied with each other, result in n. Examples:

2 = 1 * 2
The result vector should contain: 1, 2

12 = 1 * 2 * 2 * 3
The result vector should contain: 1, 2, 2, 3

17 = 1 * 17
The result vector should contain: 1, 17

Implement the function according to the following, simple algorithm:

given: a positive integer number n, to be factorised
result: a vector of integer factors of n, as described above

1: let result contain the number 1
2: candidate <-- 2
3: if n can be divided by candidate without remainder:
4:       add candidate at the end of result
5:       n <-- n / candidate
6: else:
7:       candidate <-- candidate + 1
8: if n is larger than 1:
9:       continue with line 3:
10: return result

HINT: The remainder of an integer division can be computed by the modulo
operator '%', example: 15 % 2 == 1
*/

std::vector<int> factorise(unsigned int n) {
  return;
}
