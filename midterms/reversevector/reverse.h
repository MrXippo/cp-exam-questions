#include <vector>

// this function is supposed to reverse the order of the elements of v
//
// unfortunately, it doesn't work.
// your task is to fix it!


void reverse(std::vector<int> &v) {
  std::vector<int> reverse_vector;
  for (int i = 1; i < reverse_vector.size(); i++) {
      reverse_vector.push_back(v.at(i));
  }
}
