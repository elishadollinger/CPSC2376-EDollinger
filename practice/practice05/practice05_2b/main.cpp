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
    //This prompts the user to enter an int and pushes the int back until the user enters a string
    std::cout << "Enter a string input to stop the loop." << std::endl;
    while(!std::cin.fail())
    {
        std::cout << "Enter an int: ";
        std::cin >> userInput;
        if(std::cin.fail())
        {
            break;
        }]
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        userInts.push_back(userInput);
    }
    //Clear buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /*This uses a pointer to the vector to find both the minimum and maximum in the vector
     I had to use ChatGPT to figure out that I had to use a reference to find each element
     After this, I learned that the pointer allows us to successfully use this function without error*/
    std::cout << "Smallest in the vector: " << *std::min_element(userInts.begin(), userInts.end()) << std::endl;
    std::cout << "Biggest in the vector: " << *std::max_element(userInts.begin(), userInts.end()) << std::endl;
    return 0;
}
