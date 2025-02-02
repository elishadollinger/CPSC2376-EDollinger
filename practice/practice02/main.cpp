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
    //Tracking variables
    double balanceInFile = readBalanceFromFile();
    double amountDeposited;
    
    //Prompts the user for the amount being deposited and stores this amount
    std::cout << "Enter the amount being deposited: $";
    std::cin >> amountDeposited;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Ignore bad input
    
    //Makes the user deposit at least one cent
    while(amountDeposited < 0.01)
    {
        std::cout << "Error: Deposit value must be over $0.01 or over." << std::endl;
        std::cout << "Enter the amount being deposited: $";
        std::cin >> amountDeposited;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    //If the user tries to withdraw more than they have, make them withdraw a number that is either the same or less than the value in their account
    while(amountWithdrawn > balanceInFile)
    {
        std::cout << "Error: Cannot withdraw more than you have." << std::endl;
        std::cout << "Enter the amount being withdrawn: $";
        std::cin >> amountWithdrawn;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    //If the menu choice is invalid, make the user enter a valid choice
    while(choice < 1 || choice > 4)
    {
        std::cout << "Invalid choice." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choice;//Return the choice
}

int main()
{
    int userChoice;
    std::string userName;
    
    //Asks the user for their name and gets their full name using "getline"
    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);
    
    //Greeting
    std::cout << "Welcome to " << userName << "'s Bank Account!" << std::endl;
    std::cout << "Initializing " << userName << "'s bank account to $100.00...";
    writeBalanceToFile(readBalanceFromFile());//Initializes the user's bank acount, which will come out to $100.00
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
    /*
     I had to use ChatGPT for this
     This prevents the file from reading an existing value from the previous code
    */
    remove("account_balance.txt");
    std::cout << "Exiting program..." << std::endl;
    return 0;
}
