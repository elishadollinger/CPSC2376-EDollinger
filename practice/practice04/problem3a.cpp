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

//Prompts the user for a task and adds it to the lists of tasks using a reference
void addTask(std::list<std::string>& tasks)
{
    std::string taskAdded;
    std::cout << "Enter task: ";
    std::getline(std::cin, taskAdded);
    
    tasks.push_back(taskAdded);
}

/*I had to use GPT to figure out how to iterate through a list
 To iterate through a "for" loop with a list, you have to start the index when the task starts
 Then, you have to set the limit as "it != tasks.end()"
 Finally you add 1 to continue iterating
 Additionally, we have to create our own index, initialize it at one and add one to it every time the for loop iterates so the task list will print in numerical order*/
void printTasks(const std::list<std::string>& tasks)
{
    int index = 1;
    for (std::list<std::string>::const_iterator it = tasks.begin(); it != tasks.end(); ++it)
    {
        std::cout << index << ": " << *it << "." << std::endl;  // Dereference iterator to access the value
        index++;
    }
}

/*I had to use ChatGPT to figure out how to remove an item from a list
 To do this, you make an iterator of the list called "it" and set it to the beginning of the list
 Then, you advance to the spot of the list equal to taskRemoved-1 to get the correct index
 Finally, you use tasks.erase(it) to correctly delete the task at the said index*/
void removeTask(std::list<std::string>& tasks)
{
    int taskRemoved;
    printTasks(tasks);
    std::cout << "Task you want to remove: ";
    std::cin >> taskRemoved;
    while(std::cin.fail() || taskRemoved < 1 || taskRemoved > tasks.size())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input or number not in range." << std::endl;
        std::cout << "Task you want to remove: ";
        std::cin >> taskRemoved;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::list<std::string>::iterator it = tasks.begin();
    std::advance(it, taskRemoved-1);
    tasks.erase(it);
}

//Prompts the user for their menu choice and makes them input a valid number in the range
int promptMenu()
{
    int choice;
    std::cout << "1: Add task." << std::endl;
    std::cout << "2: Remove task." << std::endl;
    std::cout << "3: Show tasks." << std::endl;
    std::cout << "4: Exit." << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    while(std::cin.fail() || choice < 1 || choice > 4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input or number not in range." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

/*Main user interface
 As long as the user's choice isn't 4, the loop keeps going
 A specific task is done based on what the user chooses according to the menu*/
int main()
{
    std::list<std::string> taskList;
    int userChoice = promptMenu();
    while(userChoice != 4)
    {
        if(userChoice == 1)
        {
            addTask(taskList);
        }
        else if(userChoice == 2)
        {
            if(taskList.empty())
            {
                std::cout << "Error: Task list is empty." << std::endl;
            }
            else
            {
                removeTask(taskList);
            }
        }
        else if(userChoice == 3)
        {
            if(taskList.empty())
            {
                std::cout << "Error: Task list is empty." << std::endl;
            }
            else
            {
                printTasks(taskList);
            }
        }
        userChoice = promptMenu();
    }
    std::cout << "Exiting program..." << std::endl;
    return 0;
}

