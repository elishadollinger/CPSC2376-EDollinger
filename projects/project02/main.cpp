/*
    Elisha Dollinger
    Project02
    CPSC2376
    Spring 2025
*/

#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include "Game.h"

using std::cout;
using std::endl;
using std::vector;
using std::uniform_int_distribution;
using std::numeric_limits;

/*
    This prompts the user for the column they want to place on
    If they enter an invalid input, do not enter an integer input, or enter a column that is full, make them enter a valid input
    Then, return the user's placing subtracted by one to successfully place the token
*/
int promptUserPlay(const Game& cFour)
{
    int move;
    if(cFour.getUserOne() == true)
    {
        std::cout << "Player one: ";
    }
    else
    {
        std::cout << "Player two: ";
    }
    std::cout << "Enter the column to be placed in(1-7): ";
    std::cin >> move;
    while(std::cin.fail() || move < 1 || move > 7 || cFour.columnEmpty(move-1))
    {
        std::cin.clear();
        std::cout << "Invalid input or column full. Choose a column (1-7): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> move;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return move--;
}

/*
    Explains rules, pretty straightforward
    Also, here is a ChatGPT philosophical comment about squirrels since I didn't get to answer whatever the philosophical comment was on the
    midterm
    Squirrels embody the paradox of nature’s meticulous chaos—seemingly frantic yet methodically prepared, hoarders of abundance yet
    forgetful enough to foster new forests. They remind us that even in apparent disorder, there is a hidden harmony, and that survival
    often depends not on rigid control, but on adaptability and trust in the unknown.
*/
void rulesExplanation()
{
    std::cout << "Welcome to Connect Four!" << std::endl;
    std::cout << "Player 1 is O, Player 2 is X." << std::endl;
    std::cout << "In order to win, you must get four of your tokens in a row." << std::endl;
    std::cout << "Your tokens can be diagonal, horizontal, or vertical." << std::endl;
}

int main()
{
    Game connectFour;//ConnectFour constructor
    
    //Prints the rules and the initial board
    rulesExplanation();
    std::cout << connectFour;
    
    /*Happens while the game is still going
     I also want to point out that if you try to run this in codebin, it will operate differently.
     When I try to run in codebin with Game::Status instead of connectFour.Status, I get an error
     Right now I am in XCode. If you get an error, replace everywhere that says "Game::" with "connectFour." and it should work.
     I pray that you do not count me off for this*/
    while(connectFour.gameStatus()==Game::Status::ONGOING)
    {
        connectFour.play(promptUserPlay(connectFour));
        std::cout << connectFour;
        //When the game ends, the code prints out who won/if it was a draw and asks the user if they want to play again
        if(connectFour.gameStatus()!=Game::Status::ONGOING)
        {
            int repeat;
            if(connectFour.gameStatus()==Game::Status::PLAYER_1_WINS)
            {
                std::cout << "Player one wins!" << std::endl;
            }
            if(connectFour.gameStatus()==Game::Status::PLAYER_2_WINS)
            {
                std::cout << "Player two wins!" << std::endl;
            }
            if(connectFour.gameStatus()==Game::Status::DRAW)
            {
                std::cout << "Draw!" << std::endl;
            }
            std::cout << "Play again(0 for no, 1 for yes): ";
            std::cin >> repeat;
            //If the user enters an invalid input, make them enter a valid one
            while(std::cin.fail() || repeat < 0 || repeat > 1)
            {
                std::cin.clear();
                std::cout << "Invalid input.\nPlay again(0 for no, 1 for yes): ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> repeat;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            /*If the user does not want to repeat, leave the loop
            Otherwise, reset the board*/
            if(repeat == 0)
            {
                break;
            }
            else
            {
                connectFour.reset();
            }
        }
    }
    
    std::cout << "Exiting program..." << std::endl;
    return 0;
}
