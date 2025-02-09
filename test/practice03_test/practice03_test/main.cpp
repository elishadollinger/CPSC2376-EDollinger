//
//  main.cpp
//  practice03_test
//
//  Created by Eli Dollinger on 2/9/25.
//

#include <iostream>
#include "practice03_test.cpp"
#include <vector>

int main()
{
  std::cout << "Sum from 1 to 5: " << MathUtils::sumRange(1, 5) << std::endl;
  std::vector<int> values = {3, -1, 5, 7};
  std::cout << "Contains negative? " << MathUtils::containsNegative(values) << std::endl;
  std::cout << "Max value: " << MathUtils::findMax(values) << std::endl;
  return 0;
}
