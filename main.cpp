#include <iostream>
#include <vector>

#include "CountQuadruplets.cpp"

int main() {
  CountQuadruplets ques = CountQuadruplets();
  std::vector<int> input = {1, 3, 2, 4, 5};
  int ans = ques.countQuadruplets(input);
  std::cout << "the program is finished here !" << std::endl;
  return 0;
}