/*
    Elisha Dollinger
    practice03.cpp
    CPSC2376
    Spring 2025
 */
#include <iostream>
#include <vector>

class MathUtils
{
public:
  static int sumRange(int start, int end)
    {
    int sum = 0;
    //This was a bug, but I resolved it by implementing "i <= end" in place of "i < end"
    for (int i = start; i <= end; i++)
    {
      sum += i;
    }
    return sum;
  }
   
  static bool containsNegative(const std::vector<int>& numbers)
    {
    //I fixed this out of bounds exception by changing the condition to "i<numbers.size()"
    for (size_t i = 0; i < numbers.size(); i++)
    {
      //I fixed this bug by changing the code from "numbers[i]<0" to "numbers[i]>0"
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
        return INT_MIN; // Bug
    }
    int maxVal = numbers[0];
    //I fixed this bug by changing the for loop to "size_i=0; i<numbers.size(); i++" to ensure that the for loop went through numbers.at(0) to numbers.at(numbers.size()-1)
    for (size_t i = 0; i < numbers.size(); i++)
    {
      //I fixed this by changing the code from "if(numbers[i]>=maxVal" to "if(numbers[i]>maxVal"
      if (numbers[i] > maxVal)
      {
        maxVal = numbers[i];
      }
    }
    return maxVal;
  }
};

int main()
{
    //Tests to show everything is working
    std::vector<int> intsVec = {59, 58, -5, -38};
    std::cout << "Sum of numbers 1-5: " << MathUtils::sumRange(1, 5) << std::endl;
    bool containsNeg = MathUtils::containsNegative(intsVec);
    std::cout << "The vector contains a negative: " << std::boolalpha << containsNeg << std::endl;
    std::cout << "The max number in the vector: " << MathUtils::findMax(intsVec) << std::endl;
    return 0;
}
