/*
    Elisha Dollinger
    Practice04 - Problem 1A
    CPSC2376
    Spring 2025
 */
/*#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

double convertTemperature(double temp, char scale = 'F')
{
    if(scale != 'F')
    {
        return (temp-32) * 5/9;
    }
    return (temp*9/5)+32;
}

int promptTypeOfTemperature()
{
    int typeOfConversion;
    std::cout << "1: Convert Celsius to Fahrenheit.\n2: Convert Fahrenheit to Celsius." << std::endl;
    std::cout << "Your choice: ";
    std::cin >> typeOfConversion;
    while(std::cin.fail() || typeOfConversion < 1 || typeOfConversion > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid option." << std::endl;
        std::cout << "1: Convert Celsius to Fahrenheit.\n2: Convert Fahrenheit to Celsius." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> typeOfConversion;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return typeOfConversion;
}

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
    if(typeBeingConverted == 1)
    {
        std::cout << "Converted: " << fixed << std::setprecision(2) << convertTemperature(temperature, 'F') << "°F" << std::endl;
    }
    else
    {
        std::cout << "Converted: " << fixed << std::setprecision(2) << convertTemperature(temperature, 'C') << "°C" << std::endl;
    }
    return 0;
}
*/
