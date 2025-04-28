#include "Game.h"
#include <SDL2_gfxPrimitives.h>

Game::Game(Token currentToken, bool userOne)
    : currentToken(currentToken), userOne(userOne), board(6, std::vector<Token>(7, Token::EMPTY))
{
}

void Game::play(int row, int col)
{
    if (row < 0 || row >= 6 || col < 0 || col >= 7)
        return; // out of bounds
    if (board[row][col] != Token::EMPTY)
        return; // already filled

    board[row][col] = userOne ? Token::PLAYER_1 : Token::PLAYER_2;
    userOne = !userOne; // Switch player
}


bool Game::getUserOne() const
{
    return userOne;
}

bool Game::checkWin(Token player) const
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (j <= 3 && board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player)
                return true;
            if (i <= 2 && board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player)
                return true;
            if (i <= 2 && j <= 3 && board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player)
                return true;
            if (i >= 3 && j <= 3 && board[i][j] == player && board[i-1][j+1] == player && board[i-2][j+2] == player && board[i-3][j+3] == player)
                return true;
        }
    }
    return false;
}

bool Game::columnEmpty(int columnIndex) const
{
    return board[0][columnIndex] != Token::EMPTY;
}

Game::Status Game::gameStatus() const
{
    if (checkWin(Token::PLAYER_1)) return Status::PLAYER_1_WINS;
    if (checkWin(Token::PLAYER_2)) return Status::PLAYER_2_WINS;
    for (int i = 0; i < board[0].size(); i++)
    {
        if (board[0][i] == Token::EMPTY) return Status::ONGOING;
    }
    return Status::DRAW;
}

void Game::reset()
{
    for (auto& row : board)
        for (auto& cell : row)
            cell = Token::EMPTY;
    userOne = true;
}

void Game::draw(SDL_Renderer* renderer) const
{
    const int CELL_SIZE = 100;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            SDL_Rect rect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderDrawRect(renderer, &rect);

            if (board[i][j] == Token::PLAYER_1)
            {
                filledCircleRGBA(renderer, j * CELL_SIZE + CELL_SIZE/2, i * CELL_SIZE + CELL_SIZE/2, CELL_SIZE/2 - 10, 0, 0, 255, 255);
            }
            else if (board[i][j] == Token::PLAYER_2)
            {
                filledCircleRGBA(renderer, j * CELL_SIZE + CELL_SIZE/2, i * CELL_SIZE + CELL_SIZE/2, CELL_SIZE/2 - 10, 255, 0, 0, 255);
            }
        }
    }
}

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
        os << "\n";
    }
    os << "\n";
    return os;
}
