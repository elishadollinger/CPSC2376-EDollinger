/*
    Elisha Dollinger
    Practice04 - Problem 1B
    CPSC2376
    Spring 2025
 */
/*
#include <iostream>
#include <limits>
#include <string>

void greet(std::string name = "Guest", std::string prefix = "Hello")
{
    std::cout << prefix << ", " << name << '!' << std::endl;
}

int promptMenu()
{
    int choice = 0;
    std::cout << "Menu options:" << std::endl;
    std::cout << "\t1. Default Greeting" << std::endl;
    std::cout << "\t2. Greet by Name" << std::endl;
    std::cout << "\t3. Custom Greeting" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    while(std::cin.fail() || choice < 1 || choice > 3)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Number not in range 1-3 or string input delivered." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

std::string promptNameOfChoice()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    return name;
}

std::string promptPrefixOfChoice()
{
    std::string greeting;
    std::cout << "Enter prefix to be greeted with: ";
    std::getline(std::cin, greeting);
    return greeting;
}

int main()
{
    int userChoice = promptMenu();
    std::string nameOfChoice;
    std::string prefixOfChoice;
    if(userChoice == 1)
    {
        greet();
        
    }
    else if(userChoice == 2)
    {
        greet(nameOfChoice = promptNameOfChoice());
    }
    else if(userChoice == 3)
    {
        greet(nameOfChoice = promptNameOfChoice(), prefixOfChoice = promptPrefixOfChoice());
    }
    return 0;
}
*/
