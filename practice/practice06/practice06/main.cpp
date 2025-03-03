#include <iostream>
#include <limits>
#include <stdexcept>
#include "Fraction.h"
#include "MixedFraction.h"

//This is used to validate integer inputs, which prevents the input from failing if a string is entered
void validateIntInput(int &input)
{
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid choice." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> input;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
    This gives the user a simple interface that will print out the menu, prompt them for their choice of operation and return said choice
    If the user enters an invalid input, such as a number out of range or a string, the code makes them enter a valid input
 */
int userInterface()
{
    int choice;
    std::cout << "Options: " << std::endl;
    std::cout << "\t1. Enter a fraction manually" << std::endl;
    std::cout << "\t2. Add a fraction" << std::endl;
    std::cout << "\t3. Subtract a fraction" << std::endl;
    std::cout << "\t4. Multiply by a fraction" << std::endl;
    std::cout << "\t5. Divide by a fraction" << std::endl;
    std::cout << "\t6. Display as Mixed Fraction" << std::endl;
    std::cout << "\t7. Clear Fraction" << std::endl;
    std::cout << "\t8. Exit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    while(std::cin.fail() || choice < 1 || choice > 8)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid choice." << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

/*
    This happens as long as the user does not enter 8
    In almost all of these, a try/catch is utilized. I had to use GPT to learn how to use a try/catch
    If the user tries to set the denominator as 0, the code will explain that the denominator cannot be 0
    If the user is trying to initialize the fraction value, the fraction's value will simply be set to 0/1
    Otherwise, if the user is trying to do a math operation and enters the denominator as 0, the fraction will remain as it's initial fraction value
    Also, a fraction reference is used here so that the fraction can be altered in the "operate" function
 */
void operate(int choice, Fraction &frac)
{
    //Sets the initial fraction value
    if(choice == 1)
    {
        int n;
        int d;
        std::cout << "Enter a numerator: ";
        std::cin >> n;
        validateIntInput(n);
        std::cout << "Enter a denominator: ";
        std::cin >> d;
        validateIntInput(d);

        frac.setNum(n);
        try
        {
            frac.setDen(d);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
            std::cout << "Setting default fraction value..." << std::endl;
            frac.setNum(0);
            frac.setDen(1);
        }
        frac.simplify();
    }
    //Adds a fraction
    else if(choice == 2)
    {
        Fraction addedFrac;
        int n;
        int d;
        std::cout << "Enter a numerator: ";
        std::cin >> n;
        validateIntInput(n);
        
        std::cout << "Enter a denominator: ";
        std::cin >> d;
        validateIntInput(d);
        
        addedFrac.setNum(n);
        try
        {
            addedFrac.setDen(d);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
            std::cout << "Keeping fraction value the same..." << std::endl;
            addedFrac.setNum(0);
            addedFrac.setDen(1);
        }
        frac = frac + addedFrac;
        frac.simplify();
    }
    //Subtracts a fraction
    else if(choice == 3)
    {
        Fraction subtractedFrac;
        int n;
        int d;
        std::cout << "Enter a numerator: ";
        std::cin >> n;
        validateIntInput(n);
        
        std::cout << "Enter a denominator: ";
        std::cin >> d;
        validateIntInput(d);
        
        subtractedFrac.setNum(n);
        try
        {
            subtractedFrac.setDen(d);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
            std::cout << "Keeping fraction value the same..." << std::endl;
            subtractedFrac.setNum(0);
            subtractedFrac.setDen(1);
        }
        frac = frac - subtractedFrac;
        frac.simplify();
    }
    //Multiplies a fraction
    else if(choice == 4)
    {
        Fraction multipliedFrac;
        int n;
        int d;
        std::cout << "Enter a numerator: ";
        std::cin >> n;
        validateIntInput(n);

        std::cout << "Enter a denominator: ";
        std::cin >> d;
        validateIntInput(d);
        
        multipliedFrac.setNum(n);
        //GPT
        try
        {
            multipliedFrac.setDen(d);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
            std::cout << "Keeping fraction value the same..." << std::endl;
            multipliedFrac.setNum(1);
            multipliedFrac.setDen(1);
        }
        frac = frac * multipliedFrac;
        frac.simplify();
    }
    //Divides a fraction
    else if(choice == 5)
    {
        Fraction dividedFrac;
        int n;
        int d;
        std::cout << "Enter a numerator: ";
        std::cin >> n;
        validateIntInput(n);

        std::cout << "Enter a denominator: ";
        std::cin >> d;
        validateIntInput(d);
        
        dividedFrac.setNum(n);
        
        try
        {
            dividedFrac.setDen(d);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
            std::cout << "Keeping fraction value the same..." << std::endl;
            dividedFrac.setNum(1);
            dividedFrac.setDen(1);
        }
        frac = frac / dividedFrac;
        frac.simplify();
    }
    /*
        If the user has a numerator that is less than the denominator, claim that the user cannot print it as a mixed number
        Otherwise, this prints the fraction value as a mixed number
     */
    else if(choice == 6)
    {
        if(frac.getNum() < frac.getDen())
        {
            std::cout << "Error: Numerator must be greater than denominator to print as a mixed fraction." << std::endl;
        }
        else
        {
            std::cout << MixedFraction(frac) << std::endl;
        }
    }
    //Resets fraction value
    else if(choice == 7)
    {
        frac.setNum(0);
        frac.setDen(1);
    }
}

int main()
{
    int userChoice;
    Fraction userFrac;
    //Prints the current fraction value, which is initialized as 0/1
    std::cout << "Current fraction value: " << userFrac << std::endl;
    userChoice = userInterface();//Promts the user for a valid choice
    //As long as the user enters a number that isnt 8, keep operating
    while(userChoice != 8)
    {
        operate(userChoice, userFrac);
        std::cout << "Current fraction value: " << userFrac << std::endl;
        userChoice = userInterface();
    }
    //Prints this after the user has entered 8
    std::cout << "Exiting program..." << std::endl;
    return 0;
}
