//
//  practice03_test.cpp
//  practice03_test
//
//  Created by Eli Dollinger on 2/9/25.
//

// practice03.cpp (Buggy Code to be tested)
#include <iostream>
#include <vector>
#include "practice03_test.hpp"

class MathUtils
{
public:
  static int sumRange(int start, int end)
    {
    int sum = 0;
    for (int i = start; i <= end; i++) { // Bug: Off-by-one error
      sum += i;
    }
    return sum;
  }
   
  static bool containsNegative(const std::vector<int>& numbers)
    {
    for (size_t i = 0; i < numbers.size(); i++)
    { // Bug
      if (numbers[i] < 0)
      { // Bug
        return true;
      }
    }
    return false;
  }
   
  static int findMax(const std::vector<int>& numbers)
    {
    if (numbers.empty())
    {
        return 0; // Bug
    }
    int maxVal = numbers[0];
    for (size_t i = 0; i < numbers.size(); i++)
    { // Bug
      if (numbers[i] > maxVal)
      { // Bug
        maxVal = numbers[i];
      }
    }
    return maxVal;
  }
};
