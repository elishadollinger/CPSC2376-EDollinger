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

//This shows all the choices for the user, prompts them for the choice and returns the choice as an int
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
    std::vector<int> userVec;//Empty vector
    
    //Sets the user choice to 0 to make the user pick a number 1-6
    int userChoice = 0;
    
    //User iterates through this at least once, if they do not enter a number that is 1-6 they go through it again
    while(userChoice < 1 || userChoice > 6)
    {
        userChoice = promptChoice();
    }
    
    //While the user has not chosen to exit the program
    while(userChoice != 6)
    {
        //If the user chooses to add a number to the vector, prompt them for a number using a function and push that number back
        if(userChoice == 1)
        {
	        userVec.push_back(numAddedToVec());
        }
        //If the user chooses to print the vector, print the vector using a function that passes the user's vector
        else if(userChoice == 2)
        {
            printVector(userVec);
        }
        //If the user chooses to double the vector, pass the vector through reference to directly double the vector through the function
        else if(userChoice == 3)
        {
            doubleVector(userVec);
        }
        //If the user chooses to sum the vector, pass the vector to the "sumVector" function to add all the numbers in the vector together
        else if(userChoice == 4)
        {
            sumVector(userVec);
        }
        //If the user chooses to find a multiple, prompt the user for a multiple and find the valus in the function that are multiples of the aforementioned multiple using the "printMultiples" function
        else if(userChoice == 5)
        {
            int userMultiple;
            std::cout << "Enter your multiple: ";
            std::cin >> userMultiple;
            printMultiples(userVec, userMultiple);
        }
        //Prompts the user for their choice
        userChoice = promptChoice();
        
        //If the user enters an invalid choice, make them enter a valid one
        while(userChoice < 1 || userChoice > 6)
        {
            userChoice = promptChoice();
        }
    }
    std::cout << "Exiting program..." << std::endl;
	return 0;
}
