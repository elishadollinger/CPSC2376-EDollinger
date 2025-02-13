//
//  problem1a.cpp
//  practice04
//
//  Created by Eli Dollinger on 2/12/25.
//
#include <iostream>
#include <limits>

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
        std::cout << "Invalid option." << std::endl;
        std::cout << "1: Convert Celsius to Fahrenheit.\n2: Convert Fahrenheit to Celsius." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> typeOfConversion;
    }
    return typeOfConversion;
}

int main()
{
    int temperature;
    int typeBeingConverted = promptTypeOfTemperature();
    std::cout << "Enter temperature: ";
    std::cin >> temperature;
    if(typeBeingConverted == 1)
    {
        std::cout << "Converted: " << convertTemperature(temperature, 'F') << "°F" << std::endl;
    }
    else
    {
        std::cout << "Converted: " << convertTemperature(temperature, 'C') << "°C" << std::endl;
    }
    return 0;
}
