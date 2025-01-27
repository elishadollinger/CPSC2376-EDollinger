/*
    Elisha Dollinger
    CPSC 2376
    Spring 2025
    January 28, 2025
*/

#include <iostream>
#include <vector>

//Prints the vector and passes the vector
void printVector(std::vector<int> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
}
 
//Passes the vector by reference to directly alter the vector and doubles the vector
void doubleVector(std::vector<int>& numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers.at(i)*=2;
        std::cout << numbers.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
}

//Calculates and prints the sum of the vector
void sumVector(std::vector<int> numbers)
{
    int sumOfVec = 0;
    for(int i = 0; i < numbers.size(); i++)
    {
        sumOfVec += numbers.at(i);
    }
    std::cout << "Sum of all numbers in the vector: " << sumOfVec << std::endl;
    std::cout << "\n";
}

//Calculates each multiple in the vector from the user-inputted multiple, stores the multiples in a vector and prints these multiples
void printMultiples(std::vector<int> numbers, int multiple)
{
    std::vector<int> multiplesVec;
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers.at(i) % multiple == 0)
        {
            multiplesVec.push_back( numbers.at(i) );
        }
    }
    std::cout << "Multiples of " << multiple << " in your vector: " << std::endl;
    for(int i = 0; i < multiplesVec.size(); i++)
    {
        std::cout << multiplesVec.at(i) << " " << std::endl;
    }
    std::cout << "\n";
}

//Prompts for an integer, stores the integer and returns the integer
int addNumToVec()
{
    int vecNum;
	std::cout << "Enter an integer: ";
	std::cin >> vecNum;
	std::cout << "\n";
	return vecNum;
}

int promptChoice()
{
    int choice;
    std::cout << "List of Choices"<< std::endl;
    std::cout << "\tChoice 1: Add a number to the vector." << std::endl;
    std::cout << "\tChoice 2: Print the vector." << std::endl;
    std::cout << "\tChoice 3: Double the vector." << std::endl;
    std::cout << "\tChoice 4: Calculate and print the sum." << std::endl;
    std::cout << "\tChoice 5: Print multiples of a user-defined value." << std::endl;
    std::cout << "\tChoice 6: Exit the program." << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    return choice;
}

int main()
{
    std::vector<int> userVec;
    int userChoice = 0;
    while(userChoice < 1 || userChoice > 6)
    {
        userChoice = promptChoice();
    }
    while(userChoice != 6)
    {
        if(userChoice == 1)
        {
	        userVec.push_back(numAddedToVec());
        }
        else if(userChoice == 2)
        {
            printVector(userVec);
        }
        else if(userChoice == 3)
        {
            doubleVector(userVec);
        }
        else if(userChoice == 4)
        {
            sumVector(userVec);
        }
        else if(userChoice == 5)
        {
            int userMultiple;
            std::cout << "Enter your multiple: ";
            std::cin >> userMultiple;
            printMultiples(userVec, userMultiple);
        }
        userChoice = promptChoice();
        while(userChoice < 1 || userChoice > 6)
        {
            userChoice = promptChoice();
        }
    }
	return 0;
}