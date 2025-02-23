/*
    Elisha Dollinger
    Practice05 - 3A
    CPSC2376
    Spring 2025
 */

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> userInts;
    int userInput;
    
    std::cout << "Enter a string input to stop entering ints." << std::endl;
    
    while(!std::cin.fail())
    {
        std::cout << "Enter an int: ";
        std::cin >> userInput;
        if(std::cin.fail())
        {
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        userInts.push_back(userInput);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::for_each(userInts.begin(), userInts.end(), [](int x)
    {
        std::cout << x*x << std::endl;
    });
    
    int squaresSum = std::accumulate(userInts.begin(), userInts.end(), 0, [](int sum, int x)
    {
        return sum + x*x;
    });
    std::cout << "Sum: " << squaresSum << std::endl;
    return 0;
}
