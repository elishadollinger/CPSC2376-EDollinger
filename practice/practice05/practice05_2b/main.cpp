/*
    Elisha Dollinger
    Practice05 - 2B
    CPSC2376
    Spring 2025
*/

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm>

int main()
{
    std::vector<int> userInts;
    int userInput;
    std::cout << "Enter a string input to stop the loop." << std::endl;
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
    std::cout << "Smallest in the vector: " << *std::min_element(userInts.begin(), userInts.end()) << std::endl;
    std::cout << "Biggest in the vector: " << *std::max_element(userInts.begin(), userInts.end()) << std::endl;
    return 0;
}
