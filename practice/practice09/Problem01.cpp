/*
    Elisha Dollinger
    Practice09 - Problem 01
    CPSC2376
    Spring 2025
 */

#include <iostream>
#include <string>
#include <limits>
 
int main()
{
    std::string redOrBlue;
    float milliletersAdded;
    float redPotion{0.0f};    // Amount of red potion in mL
    float bluePotion{0.0f};   // Amount of blue potion in mL
    float* flask{nullptr};    // Pointer to the selected potio
    bool done = false;//This isn't actually used but it makes the loop iterate
     
    std::cout << "Enter \"Done\" to exit the program." << std::endl;
     
    //This occurs until the user enters "Done"
    while(!done)
    {
        std::cout << "Add liquid to red or blue(enter \"Red\" or \"Blue\"): ";
        std::cin >> redOrBlue;
        
        //If the user enters "Done", end the program
        if(redOrBlue == "Done")
        {
            done = true;
            std::cout << "Exiting program..." << std::endl;
            return 0;
        }
        
        //Makes the user enter "Red", "Blue" or "Done"
        while(redOrBlue != "Red" && redOrBlue != "Blue")
        {
            std::cout << "Invalid input." << std::endl;
            std::cout << "Add liquid to red or blue(enter \"Red\" or \"Blue\"): ";
            std::cin >> redOrBlue;
            
            if(redOrBlue == "Done")
            {
                std::cout << "Exiting program..." << std::endl;
                return 0;
            }
        }
        
        /*If the user enters "Red", point the flask to the red potion
        If the user enters "Blue", point the flask to the blue potion*/

        if(redOrBlue == "Red")
        {
            flask = &redPotion;
        }
        else if(redOrBlue == "Blue")
        {
            flask = &bluePotion;
        }
        
        /*Asks the user how many mL they want to add
        If they enter an invalid amount, make them enter a valid one*/

        std::cout << "How many millileters to add: ";
        std::cin >> milliletersAdded;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\nHow many millileters to add: ";
            std::cin >> milliletersAdded;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //Adds the millileters to the flask, which automatically points to the potion that was referenced earlier and adds it to said potion
        *flask += milliletersAdded;
        
        std::cout << "Millileters in red potion: " << redPotion << std::endl;
        std::cout << "Millileters in blue potion: " << bluePotion << std::endl;
    }
    return 0;
}
