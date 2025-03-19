#pragma once
#include <iostream>
#include <vector>

class Game
{
    private:
        enum class Token { EMPTY, PLAYER_1, PLAYER_2 };
        Token currentToken;
        std::vector<std::vector<Token>> board;
        bool userOne = true;
    public:
        /*I had to use ChatGPT to figure out to make Status enum public
        Before this, I was getting errors when validating that the game was ongoing in Main
        By putting this as public, main can now check if the game is still going*/
        enum class Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
        //Constructs the class and initializes the game board
        Game(Token currentToken=Token::EMPTY, bool userOne = true)
        : currentToken(currentToken),  userOne(userOne), board(6, std::vector<Token>(7))
        {
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[i].size(); j++)
                {
                    board[i][j] = Token::EMPTY;
                }
            }
        }
        void play(int move);
        /*
            I had to use ChatGPT to figure this out, as I did not want my user to be able to access the "userOne" boolean
            This returns the userOne boolean, which allows it to remain private while being accessible in code
        */
        bool getUserOne() const;
        bool checkWin(Token player) const;
        /*
            I had to use ChatGPT for the "isColumnEmpty" function
            Prior to this, I could not determine if the column was empty from "main"
            I will explain more what about what this does in Game.cpp
        */
        bool columnEmpty(int columnIndex) const;
        Status gameStatus() const;
        void reset();
        friend std::ostream& operator<<(std::ostream& os, const Game& conFour);
};
