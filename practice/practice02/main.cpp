/*
    Elisha Dollinger
    project02
    CPSC2376
    Spring 2025
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>

/*
    I had to use ChatGPT for this
    This reads the balance from the file
 */
double readBalanceFromFile()
{
    //Initializes the file
    std::ifstream file("account_balance.txt");
    double balance;
    
    //If the file exists, read the balance to the file and close the file
    if(file)
    {
        file >> balance;
        file.close();
    }
    //If the file does not exist, set the initial balance to $100
    else
    {
        std::cout << "Initializing balance with $100..." << std::endl;
        balance = 100.00;
    }
    return balance;//Returns the balance after it is read out
}

/*
    I had to use ChatGPT for this
    This writes the balance to the file
 */
void writeBalanceToFile(double balance)
{
    //Initializes the file
    std::ofstream file("account_balance.txt");
    
    //If there is no file, print out an error message and exit the function
    if (!file)
    {
        std::cout << "Error: Could not open file to write balance." << std::endl;
        exit(1);
    }
    
    //Prints the balance formatted to two decimals and then closes the file
    file << std::fixed << std::setprecision(2) << balance;
    file.close();
}

//Reads the balance from the file and prints it to the user
void checkBalance()
{
    std::cout << "Your current balance: $";
    std::cout << std::fixed << std::setprecision(2) << readBalanceFromFile() << std::endl;
}

//Deposits money into the user's account
void deposit()
{
    double balanceInFile = readBalanceFromFile();
    double amountDeposited;
    
    //Prompts the user for the amount being deposited and stores this amount
    std::cout << "Enter the amount being deposited: $";
    std::cin >> amountDeposited;

    //This checks for invalid input(string input, too low of value, etc)
    while(std::cin.fail() || amountDeposited < 0.01)
    {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Error: Either string input or a numerical value below $0.01." << std::endl;
        std::cout << "Enter the amount being deposited: $";
        std::cin >> amountDeposited; // Try again for a valid amount
    }
    
    //Adds the amount deposited to the initial balance and writes this new balance to the file
    writeBalanceToFile(balanceInFile + amountDeposited);
    std::cout << "Success! Your new balance is $" << readBalanceFromFile() << '.' << std::endl;//Reads the new balance to the user
}

void withdraw()
{
    double balanceInFile = readBalanceFromFile();
    double amountWithdrawn;
    
    //Asks for the amount being withdrawn and stores this value
    std::cout << "Enter the amount being withdrawn: $";
    std::cin >> amountWithdrawn;

    //This checks for invalid input(string input, too high amount being withdrawn)
    while(std::cin.fail() || amountWithdrawn > balanceInFile || amountWithdrawn <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        
        std::cout << "Error: Either string input or an invalid numerical balance." << std::endl;
        std::cout << "Enter the amount being withdrawn: $";
        std::cin >> amountWithdrawn;
    }
    
    //Subtracts the amount withdrawn from the initial balance and writes this new balance to the file
    writeBalanceToFile(balanceInFile - amountWithdrawn);
    std::cout << "Success! Your new balance is $" << readBalanceFromFile() << '.' << std::endl;//Reads the new balance to the user
}

//Prompts the user for their menu choice
int promptUserOptions()
{
    int choice;
    std::cout << "Menu options:" << std::endl;
    std::cout << "\t1: Check balance." << std::endl;
    std::cout << "\t2: Deposit money." << std::endl;
    std::cout << "\t3: Withdraw money." << std::endl;
    std::cout << "\t4: Exit the program." << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    //If the menu choice is invalid, make the user enter a valid choice(includes string input)
    while(std::cin.fail() || choice < 1 || choice > 4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
        std::cout << "Invalid choice." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
    return choice;//Return the choice
}

int main()
{
    std::string userName;
    int userChoice;
    
    //Asks the user for their name and gets their full name using "getline"
    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);
    
    //Greeting
    std::cout << "Welcome to " << userName << "'s Bank Account!" << std::endl;
    writeBalanceToFile(readBalanceFromFile());//Initializes the user's bank acount
    
    std::cout << " " << std::endl;
    
    userChoice = promptUserOptions();
    
    /*
        Happens while the user does not choose 4
        If the user chooses 1, check their balance
        If the user chooses 2, deposit an amount specified by them
        If the user chooses 3, withdraw an amount specified by them
    */
    while(userChoice != 4)
    {
        if(userChoice == 1)
        {
            checkBalance();
        }
        else if(userChoice == 2)
        {
            deposit();
        }
        else if(userChoice == 3)
        {
            withdraw();
        }
        userChoice = promptUserOptions();
    }
    
    std::cout << "Exiting program..." << std::endl;
    return 0;
}

