#include <iostream>
#include <vector>
#include "Game.h"
#include <SDL2_gfxPrimitives.h>

void Game::draw(SDL_Renderer* renderer) const
{
    const int cellWidth = 100;
    const int cellHeight = 100;

    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            SDL_Rect cell;
            cell.x = j * cellWidth;
            cell.y = i * cellHeight;
            cell.w = cellWidth;
            cell.h = cellHeight;

            //This creates a blue background to simulate a ConnectFour board
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
            SDL_RenderFillRect(renderer, &cell);

            //This draws a white border around each cell for aesthetics
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderDrawRect(renderer, &cell);

            // Now draw the circle if there is a token
            int centerX = cell.x + cell.w / 2;
            int centerY = cell.y + cell.h / 2;
            int radius = 40;

            if (board[i][j] == Token::PLAYER_1)
            {
                filledCircleRGBA(renderer, centerX, centerY, radius, 255, 0, 0, 255);
            }
            else if (board[i][j] == Token::PLAYER_2)
            {
                filledCircleRGBA(renderer, centerX, centerY, radius, 255, 255, 0, 255);
            }
            else if(board[i][j] == Token::EMPTY)
            {
                filledCircleRGBA(renderer, centerX, centerY, radius, 255, 255, 255, 255);
            }
        }
    }
}


/*
    This uses a boolean to determine if user one or user two is playing
    If user one is playing, set the space on the board to user one's token
    If user two is playing, set the space on the board to user two's token
*/
void Game::play(int move)
{
    //Used to check for valid placing
    bool tokenPlaced = false;
    
    //If the user tries to go out of bounds, just end
    if (move < 0 || move >= board[0].size())
    {
        return;
    }

    //Determines if the user playing entered a valid location, and if they did, place the token in said location
    if (userOne)
    {
        for (int i = board.size() - 1; i >= 0; i--)
        {
            if (board[i][move] == Token::EMPTY)
            {
                board[i][move] = Token::PLAYER_1;
                tokenPlaced = true;
                break;
            }
        }
    }
    else
    {
        for (int i = board.size() - 1; i >= 0; i--)
        {
            if (board[i][move] == Token::EMPTY)
            {
                board[i][move] = Token::PLAYER_2;
                tokenPlaced = true;
                break;
            }
        }
    }
    if(tokenPlaced)
    {
        userOne = !userOne;
    }
}


//Returns the value for userOne
bool Game::getUserOne() const
{
    return userOne;
}

//Checks for horzontal, vertical and diagonal wins
bool Game::checkWin(Token player) const
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            // Check for horizontal win (4 in a row side by side)
            if (j <= 3 && board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
            {
                return true;
            }

            // Check for vertical win (4 in a row up and down)
            if (i <= 2 && board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
            {
                return true;
            }

            // Check for diagonal win (bottom-left to top-right)
            if (i <= 2 && j <= 3 && board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
                return true;

            // Check for diagonal win (top-left to bottom-right)
            if (i >= 3 && j <= 3 && board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player)
                return true;
        }
    }
    return false;
}

/*
    This is used to check if the column is empty
    If the column is empty(meaning that it meets the return condition), return false
    Otherwise, return true
*/
bool Game::columnEmpty(int columnIndex) const
{
    return board[0][columnIndex] != Token::EMPTY;
}

//Gets the game status
Game::Status Game::gameStatus() const
{
    if (checkWin(Token::PLAYER_1))
    {
        return Status::PLAYER_1_WINS;
    }
    else if (checkWin(Token::PLAYER_2))
    {
        return Status::PLAYER_2_WINS;
    }
    for (int i = 0; i < board[0].size(); i++)
    {
        if (board[0][i] == Token::EMPTY)
        {
            return Status::ONGOING;
            break;
        }
    }
    return Status::DRAW;
}

//This remakes the board, declaring it as empty, and sets userOne to true to successfully set up when the game is replayed
void Game::reset()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            board[i][j] = Token::EMPTY;
        }
    }
    userOne = true;
}

/*This reads in the space for each spot on the board to "os". the space is dependant on the token at the specific coordinate
Then, "os" is returned. This operator overload allows for the board to print when the program uses "std::cout<<game"
 I also want to point out that if you try to run this in codebin, it will operate differently.
 When I try to run in codebin with Game::Status instead of connectFour.Status, I get an error
 Right now I am in XCode. If you get an error, replace everywhere that says "Game::" with "conFour." and it should work.
 I pray that you do not count me off for this*/
std::ostream& operator<<(std::ostream& os, const Game& conFour)
{
    for (int i = 0; i < conFour.board.size(); i++)
    {
        for (int j = 0; j < conFour.board[i].size(); j++)
        {
            if (conFour.board[i][j] == Game::Token::EMPTY)
                os << ".";
            else if (conFour.board[i][j] == Game::Token::PLAYER_1)
                os << "O";
            else if (conFour.board[i][j] == Game::Token::PLAYER_2)
                os << "X";
            os << " ";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

