/*
    Elisha Dollinger
    Practice04 - Problem 1A
    CPSC2376
    Spring 2025
 */

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

/*If the user wants to convert from fahrenheit to celsius, return the degree in the formula
 Otherwise, defaulty convert from celsius to fahrenheit*/

/*
double convertTemperature(double temp, char scale = 'F')
{
    if(scale == 'F')
    {
        return (temp-32) * 5/9;
    }
    return (temp*9/5)+32;
}
*/
/*Prompt the user for if they want to convert from celsius to fahrenheit or vice versa
Then, return this as an "int"*/

/*
int promptTypeOfTemperature()
{
    int typeOfConversion;
    std::cout << "1: Convert Celsius to Fahrenheit.\n2: Convert Fahrenheit to Celsius." << std::endl;
    std::cout << "Your choice: ";
    std::cin >> typeOfConversion;
    
    //If they do not enter 1, 2, or if they enter a string, give them an error and make them enter a valid input
    while(std::cin.fail() || typeOfConversion < 1 || typeOfConversion > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid option." << std::endl;
        std::cout << "1: Convert Celsius to Fahrenheit.\n2: Convert Fahrenheit to Celsius." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> typeOfConversion;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//ignore bad input
    return typeOfConversion;
}

//Prompt the user for a temperature and make them enter a valid double
double promptTemperature()
{
    int temp;
    std::cout << "Enter temperature: ";
    std::cin >> temp;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input." << std::endl;
        std::cout << "Enter temperature: ";
        std::cin >> temp;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return temp;
}

int main()
{
    int temperature;
    int typeBeingConverted = promptTypeOfTemperature();
    temperature = promptTemperature();
    
    //If the user wants to convert from Celsius to Fahrenheit, convert using that formula
    if(typeBeingConverted == 1)
    {
        std::cout << "Converted: " << fixed << std::setprecision(2) << convertTemperature(temperature, 'C') << "°F" << std::endl;
    }
    else//If the user wants to convert from Fahrenheit to Celsius, convert using that formula
    {
        std::cout << "Converted: " << fixed << std::setprecision(2) << convertTemperature(temperature, 'F') << "°C" << std::endl;
    }
    return 0;
}
*/
