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
    
    //This prompts the user for a string and pushes it back until the user enters a string
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
    //Clears buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Each number squared: ";
    /*I had to use GPT for this
     What this does is checks every spot in the vector using a "for_each" method
     For every number in the vector, it prints out the number squared*/
    std::for_each(userInts.begin(), userInts.end(), [](int x)
    {
        std::cout << x*x << ' ';
    });
    std::cout << "\n";
    
    /*I had to use GPT for this
     Using "std::accumulate", the function starts with a sum at 0, and adds the squared number in the vector to the sum of squares
     Then, a final value is returned to "squaresSum" */
    int squaresSum = std::accumulate(userInts.begin(), userInts.end(), 0, [](int sum, int x)
    {
        return sum + x*x;
    });
    std::cout << "Sum of squares: " << squaresSum << std::endl;
    return 0;
}
