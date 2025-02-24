/*
    Elisha Dollinger
    Practice05 - 1b
    CPSC2376
    Spring 2025
*/

#include <iostream>
#include <vector>
#include <limits>
#include <iterator>

int main()
{
    
    std::vector<int> userInts;
    int userInput;
    //This takes user integers and pushes it into the vector until the user enters a string input
    std::cout << "At any point to stop adding integers to the vector, enter a string input." << std::endl;
    while(!std::cin.fail())
    {
        std::cout << "Enter an integer to store in your vector: ";
        std::cin >> userInput;
        if(std::cin.fail())
        {
            break;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            userInts.push_back(userInput);
        }
    }
    //Clears buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /*This enters the numbers in the vector in reverse order
     It starts at the very end of the loop and goes until the start of the loop
     This is done with an iterator, which is what holds the information in the loop*/
    std::cout << "Numbers that you entered in reverse order: ";
    for(auto it = userInts.end()-1; it >= userInts.begin(); --it)
    {
        std::cout << *it << ' ';
    }
    std::cout << "\n";
    return 0;
}
