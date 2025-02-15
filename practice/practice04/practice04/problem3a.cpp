/*
    Elisha Dollinger
    Practice04 - Problem 3A
    CPSC2376
    Spring 2025
 */
#include <iostream>
#include <limits>
#include <string>
#include <list>

void addTask(std::list<std::string>& tasks)
{
    std::string taskAdded;
    std::cout << "Enter task: ";
    std::getline(std::cin, taskAdded);
    
    tasks.push_back(taskAdded);
}

void printTasks(const std::list<std::string>& tasks)
{
    int index = 1;
    for (std::list<std::string>::const_iterator it = tasks.begin(); it != tasks.end(); ++it)
    {
        std::cout << index << ": " << *it << "." << std::endl;  // Dereference iterator to access the value
        index++;
    }
}

int promptMenu()
{
    int choice;
    std::cout << "1: Add task." << std::endl;
    std::cout << "2: Remove task." << std::endl;
    std::cout << "3: Show tasks." << std::endl;
    std::cout << "4: Exit." << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    return choice;
}

int main()
{
    std::list<std::string> taskList;
    int userChoice = promptMenu();
    std::cin.ignore();
    while(userChoice != 4)
    {
        if(userChoice == 1)
        {
            addTask(taskList);
        }
        else if(userChoice == 3)
        {
            printTasks(taskList);
        }
        userChoice = promptMenu();
        std::cin.ignore();
    }
    return 0;
}
