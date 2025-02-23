/*
    Elisha Dollinger
    Practice05 - 2A
    CPSC2376
    Spring 2025
 */

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

int main()
{
    std::vector<int> userInts;
    int userInput;
    std::cout << "Enter a string to stop the process." << std::endl;
    while(!std::cin.fail())
    {
        std::cout << "Enter an integer: ";
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
    
    std::cout << "Sum: " << std::accumulate(userInts.begin(), userInts.end(), 0) << std::endl;
    std::cout << "Product: " << std::accumulate(userInts.begin(), userInts.end(), 1, std::multiplies<int>()) << std::endl;
    return 0;
}
