#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

using std::cout;
using std::endl;
using std::vector;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::numeric_limits;

enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class Token { EMPTY, PLAYER_1, PLAYER_2 };

void makeBoard(std::vector<std::vector<Token>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            board[i][j] = Token::EMPTY;
        }
    }
}

void printBoard(const std::vector<std::vector<Token>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == Token::EMPTY)
                std::cout << ".";
            else if (board[i][j] == Token::PLAYER_1)
                std::cout << "O";
            else if (board[i][j] == Token::PLAYER_2)
                std::cout << "X";
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void userPlay(std::vector<std::vector<Token>>& board)
{
    int columnPlacing;
    std::cout << "What column are you placing on (1-7): ";
    std::cin >> columnPlacing;
    while (columnPlacing < 1 || columnPlacing > 7 || board[0][columnPlacing - 1] != Token::EMPTY)
    {
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Invalid input or column full. Choose a column (1-7): ";
        std::cin >> columnPlacing;
    }
    for (int i = board.size() - 1; i >= 0; --i)
    {
        if (board[i][columnPlacing - 1] == Token::EMPTY)
        {
            board[i][columnPlacing - 1] = Token::PLAYER_1;
            break;
        }
    }
    std::cout << std::endl;
}

void aiPlay(std::vector<std::vector<Token>>& board)
{
    int aiPlacing;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 7);

    aiPlacing = dis(gen);

    while (board[0][aiPlacing - 1] != Token::EMPTY)
    {
        aiPlacing = dis(gen);
    }
    std::cout << "The AI is placing on column: " << aiPlacing << std::endl;
    for (int i = board.size() - 1; i >= 0; --i)
    {
        if (board[i][aiPlacing - 1] == Token::EMPTY) {
            board[i][aiPlacing - 1] = Token::PLAYER_2;
            break;
        }
    }
    std::cout << std::endl;
}

bool checkWin(const std::vector<std::vector<Token>>& board, Token player)
{
    // Check all horizontal, vertical, and diagonal win conditions.
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            // Check horizontal
            if (j <= 3 && board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
                return true;

            // Check vertical
            if (i <= 2 && board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
                return true;

            // Check diagonal (bottom-left to top-right)
            if (i <= 2 && j <= 3 && board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
                return true;

            // Check diagonal (top-left to bottom-right)
            if (i >= 3 && j <= 3 && board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player)
                return true;
        }
    }
    return false;
}

GameState gameStatus(const std::vector<std::vector<Token>>& board)
{
    if (checkWin(board, Token::PLAYER_1))
    {
        return GameState::PLAYER_1_WINS;
    }
    else if (checkWin(board, Token::PLAYER_2))
    {
        return GameState::PLAYER_2_WINS;
    }

    // Check for draw (if all columns are filled)
    for (int i = 0; i < board[0].size(); i++)
    {
        if (board[0][i] == Token::EMPTY)
        {
            return GameState::ONGOING;
        }
    }

    return GameState::DRAW;
}

void rulesExplanation()
{
    std::cout << "Welcome to Connect Four!" << std::endl;
    std::cout << "Player 1 is O, Player 2 is X." << std::endl;
    std::cout << "In order to win, you must get four of your tokens in a row." << std::endl;
    std::cout << "Your tokens can be diagonal, horizontal, or vertical." << std::endl;
}

int main()
{
    int playing = 0;
    GameState currentState = GameState::ONGOING;
    std::vector<std::vector<Token>> gameBoard(6, std::vector<Token>(7));
    rulesExplanation();

    while (true)
    {
        makeBoard(gameBoard);
        printBoard(gameBoard);

        while (currentState == GameState::ONGOING)
        {
            userPlay(gameBoard);
            currentState = gameStatus(gameBoard);
            if (currentState != GameState::ONGOING) break;

            aiPlay(gameBoard);
            currentState = gameStatus(gameBoard);
            printBoard(gameBoard);
        }

        if (currentState == GameState::PLAYER_1_WINS)
        {
            printBoard(gameBoard);
            std::cout << "You win!" << std::endl;
        }
        else if (currentState == GameState::PLAYER_2_WINS)
        {
            std::cout << "AI wins!" << std::endl;
        }
        else
        {
            std::cout << "Draw!" << std::endl;
        }

        std::cout << "Play again? (0 for Yes, 1 for No): ";
        std::cin >> playing;
        while(playing != 0 && playing != 1)
        {
            std::cout << "Invalid input." << std::endl;
            std::cout << "Play again? (0 for Yes, 1 for No): ";
            std::cin >> playing;
        }
        if (playing == 1)
        {
            break;
        }

        currentState = GameState::ONGOING;
    }

    return 0;
}

