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
    //This takes integers from the user and pushes them into the loop until a string is entered
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
    //Clears buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    /*
     I had to use ChatGPT for this
     These are algorithms that calculate the sum and product of the vector
     To find out the sum, we start at the beginning, go to the end and use the type "0" to declare that we are finding the sum
     To find the product, we do the same as the sum except we use the type "1" to declare that we are finding the product and we have to use the "std::multiplies<int>()" function to actually multiply all products
     */
    std::cout << "Sum: " << std::accumulate(userInts.begin(), userInts.end(), 0) << std::endl;
    std::cout << "Product: " << std::accumulate(userInts.begin(), userInts.end(), 1, std::multiplies<int>()) << std::endl;
    return 0;
}
