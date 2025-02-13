#include <iostream>
#include <vector>
#include <limits>
#include <random>

/*I had to use ChatGPT for this part
 My code was not properly translating from CodeBin to XCode
 Therefore, using all of these takes the aspects that I need for the code to runs and makes them usable in XCode*/
using std::cout;
using std::endl;
using std::vector;
using std::uniform_int_distribution;
using std::numeric_limits;

enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class Token { EMPTY, PLAYER_1, PLAYER_2 };

/*This function contains a loop that iterates through the 2 Dimensional array to create a valid board
 Every spot is initially set to empty because the connect four board is initially empty*/
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

/*This function checks every spot in the board to see what needs to be printed
 If the token at the specific board coordinate is empty, print a "." for it
 If the token at the specific board coordinate belongs to the first player, print a "O" for it
 If the token at the specific board coordinate belongs to the second player, print a "X" for it*/
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

/*
    This function is used to prompt the user to play
    Here, we use a boolean to figure out which player is playing
    If "playerOne" is true, then it asks the first player where they wanna put their token
    Then, it codes their token onto that specific location
     If "playerOne" is false, then it asks the second player where they wanna put their token
     Then, it codes their token onto that specific location
 */
void play(std::vector<std::vector<Token>>& board, bool playerOne)
{
    int columnPlacing;
    if(playerOne)
    {
        std::cout << "Player one: What column are you placing on (1-7): ";
    }
    else if(!playerOne)
    {
        std::cout << "Player two: What column are you placing on (1-7): ";
    }
    std::cin >> columnPlacing;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Ignore bad input
    /*
        I had to use ChatGPT for this
        Before I did, I saw various issues in my code regarding segmentation faults and issues with invalid inputs
        After using ChatGPT, I figured out that it was as simple as ensuring a valid input and that the user did not try to place a token on a filled column
        If this happens, the user is made to enter a token on a partially empty column or is made to enter a number between 1 and 7
     */
    while (columnPlacing < 1 || columnPlacing > 7 || board[0][columnPlacing - 1] != Token::EMPTY)
    {
        std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input or column full. Choose a column (1-7): ";
        std::cin >> columnPlacing;
    }
    /*
     The for loops here starts at the bottom of the board and goes all the way to the top
     After finding the first empty space, if thefirst user is playing, place the first user's coin there
     Otherwise, if player 2 is playing, place the second user's coin at the first empty spot
     */
    if(playerOne)
    {
        for (int i = board.size() - 1; i >= 0; i--)
        {
            if (board[i][columnPlacing - 1] == Token::EMPTY)
            {
                board[i][columnPlacing - 1] = Token::PLAYER_1;
                break;
            }
        }
    }
    else if(!playerOne)
    {
        for (int i = board.size() - 1; i >= 0; i--)
        {
            if (board[i][columnPlacing - 1] == Token::EMPTY)
            {
                board[i][columnPlacing - 1] = Token::PLAYER_2;
                break;
            }
        }
    }
    std::cout << std::endl;
}

/*
    checkWin is given a specific player's token and the board
    Them, it checks every way the specific user could have four in a row and returns "true" if any player had four in a row
 */
bool checkWin(const std::vector<std::vector<Token>>& board, Token player)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            /*
             This first if statement checks for the side by side of the code
             If there are four in a row, return "true" stating the specific user won
             */
            if (j <= 3 && board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
            {
                return true;
            }
            /*
             This second if statement checks for the up by down of the code
             If there are four in a row, return "true" stating the specific user won
             */
            if (i <= 2 && board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
            {
                return true;
            }

            /*I had to use ChatGPT for both diagonal checks
             I figured out the logic behind the diagonal check very quickly. However, I could not get it to properly implement without throwing a segmentation fault
             What this does is if it is checking from the bottom left, it looks at the one above and goes in diagonals. This has a greater I limit since it is checking from the bottom, and it is having to subtract i instead of adding
             It has to set limits for I and J to avoid segmentation fault
             When it checks from the top left, it sets a lesser I limit since it is having to look below. This means it is having to add i while checking instead of subtracting*/
            if (i <= 2 && j <= 3 && board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
                return true;

            if (i >= 3 && j <= 3 && board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player)
                return true;
        }
    }
    return false;
}

/*
    This function checks and returns the status of the game
    If the first player won, return the GameState:PLAYER_1_WINS enum
    If the second player won, return the GameState:PLAYER_2_WINS enum
    I had to use ChatGPT to check if the game is ongoing
    If neither user has won and if there is an empty column, return the enum GameState::ONGOING
    If none of these are true, the default return is a draw
 */
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

    
    for (int i = 0; i < board[0].size(); i++)
    {
        if (board[0][i] == Token::EMPTY)
        {
            return GameState::ONGOING;
        }
    }

    return GameState::DRAW;
}

//This prints and explains the rules
void rulesExplanation()
{
    std::cout << "Welcome to Connect Four!" << std::endl;
    std::cout << "Player 1 is O, Player 2 is X." << std::endl;
    std::cout << "In order to win, you must get four of your tokens in a row." << std::endl;
    std::cout << "Your tokens can be diagonal, horizontal, or vertical." << std::endl;
}

int main()
{
    //Tracking variables
    bool playerOne = true;
    int playing = 0;
    GameState currentState = GameState::ONGOING;//Game initially set to ongoing
    std::vector<std::vector<Token>> gameBoard(6, std::vector<Token>(7));
    rulesExplanation();

    makeBoard(gameBoard);//Uses the makeBoard function with a reference to make the board
    
    //While the user is playing
    while(playing == 0)
    {
        printBoard(gameBoard);//Print the initial board

        //While the game is ongoing
        while (currentState == GameState::ONGOING)
        {
            //Plays using a reference to the board and the boolean to see if the first user is playing
            play(gameBoard, playerOne);
            currentState = gameStatus(gameBoard);//Checks to see if someone has won
            printBoard(gameBoard);//Prints the board
            //If someone has won or there is a draw, break
            if (currentState != GameState::ONGOING)
            {
                break;
            }
            /*If user one is playing, make user two play
             If user two is playing, make user one play*/
            playerOne = !playerOne;
        }

        /*These check to see who has won
         Depending on if player one won, player two won or if there was a draw, a different error message is printed*/
        if (currentState == GameState::PLAYER_1_WINS)
        {
            printBoard(gameBoard);
            std::cout << "Player one wins!" << std::endl;
        }
        else if (currentState == GameState::PLAYER_2_WINS)
        {
            std::cout << "Player two wins!" << std::endl;
        }
        else
        {
            std::cout << "Draw!" << std::endl;
        }

        //Asks the user if they wanna play again
        std::cout << "Play again? (0 for Yes, 1 for No): ";
        std::cin >> playing;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //If there is an invalid input, print it to the user and make them enter a new input
        while(playing != 0 && playing != 1)
        {
            std::cin.clear();
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
            std::cout << "Play again? (0 for Yes, 1 for No): ";
            std::cin >> playing;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        //If the user doesn't wanna play anymore, break out of the loop
        if (playing == 1)
        {
            break;
        }
        //Resets all game aspects to restart the game if the user chooses to play again
        makeBoard(gameBoard);
        playerOne = true;
        currentState = GameState::ONGOING;
    }
    std::cout << "Exiting game..." << std::endl;
    return 0;
}

