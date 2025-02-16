/*
    Elisha Dollinger
    Practice04 - Problem 2B
    CPSC2376
    Spring 2025
 */


#include <iostream>
#include <iomanip>
#include <string>

//Check if the user enters an invalid double in this function to make code operation easier
void validateInput(double& input)
{
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input." << std::endl;
        std::cout << "Enter a number: ";
        std::cin >> input;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*This template takes the variable of each input
 Then, a list of "if" statements are used to check for the biggest input, inpus that are equal, etc*/
template <typename T>
T findMax(T a, T b, T c)
{
    if(a > b && a > c)
    {
        return a;
    }
    else if (b > a && b > c)
    {
        return b;
    }
    else if(c > a && c > b)
    {
        return c;
    }
    else if(a == b && a > c)
    {
        std::cout << "The first two values are the same, but are bigger than the third." << std::endl;
        return a;
    }
    else if(a == c && a > b)
    {
        std::cout << "The first and third values are the same, but are bigger than the second." << std::endl;
        return a;
    }
    else if(b == c && b > a)
    {
        std::cout << "The last two values are the same, but are greater than the first." << std::endl;
        return b;
    }
    else
    {
        std::cout << "All values are the same." << std::endl;
    }
    return a;
}

/*
    This function prompts the user for if they want to compare numbers or strings
    If they want to compare numbers, make them enter three numbers, validate each number and then put them through the "findMax" function
    If they want to compare strings, make them enter three strings and put the strings through the "findMax" function
 */

void startMaxFinder()
{
    int numsOrStrs;
    std::cout << "Would you like to compare numbers(1) or strings(2): ";
    std::cin >> numsOrStrs;
    while(std::cin.fail() || numsOrStrs<1 || numsOrStrs > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input." << std::endl;
        std::cout << "Would you like to compare numbers(1) or strings(2): ";
        std::cin >> numsOrStrs;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if(numsOrStrs == 1)
    {
        double num1 = 0.0;
        double num2 = 0.0;
        double num3 = 0.0;
        double maxValue = 0.0;
        std::cout << "Enter a number: ";
        std::cin >> num1;
        validateInput(num1);
        
        std::cout << "Enter a number: ";
        std::cin >> num2;
        validateInput(num2);
        
        std::cout << "Enter a number: ";
        std::cin >> num3;
        validateInput(num3);
        maxValue = findMax(num1, num2, num3);
        std::cout << "Max value: " << maxValue << std::endl;
    }
    else if(numsOrStrs == 2)
    {
        std::string str1 = "";
        std::string str2 = "";
        std::string str3 = "";
        std::string maxVal = "";
        
        std::cout << "Enter a string: ";
        std::getline(std::cin, str1);
        
        std::cout << "Enter a string: ";
        std::getline(std::cin, str2);
        
        std::cout << "Enter a string: ";
        std::getline(std::cin, str3);
        maxVal = findMax(str1, str2, str3);
        std::cout << "Max value: " << maxVal << std::endl;
    }
}



int main()
{
    startMaxFinder();
    return 0;
}

