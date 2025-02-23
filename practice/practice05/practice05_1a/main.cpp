/*
    Elisha Dollinger
    Practice05 - 1A
    CPSC 2376
    Spring 2025
 */

#include <iostream>
#include <vector>
#include <limits>
#include <iterator>

int main()
{
    std::vector<int> userInts;
    std::cout << "At any point to stop adding integers to the vector, enter a string input." << std::endl;
    int userInput;
    int evenSum;
    //If the user has not entered a string, keep going in the loop
    while(!std::cin.fail())
    {
        std::cout << "Enter an integer to store in your vector: ";
        std::cin >> userInput;
        if(std::cin.fail())
        {
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        userInts.push_back(userInput);
    }
    std::cin.clear();
    
    /*
        Prints the numbers in the order the user entered them in
        If the user's int is even, add it to "evenSum" to get the sum of all even nums
    */
    std::cout << "Numbers in the order that you entered them in: ";
    for(auto it = userInts.begin(); it != userInts.end(); ++it)
    {
        std::cout << *it << ' ';
        if(*it%2==0)
        {
            evenSum += *it;
        }
    }
    std::cout << "\n";
    
    //Prints the number in the order the user entered them in
    std::cout << "The sum of even numbers: " << evenSum << std::endl;
    return 0;
}
