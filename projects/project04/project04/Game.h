#include <iostream>
#include <vector>
#include <SDL.h>

class Game
{
private:
    enum class Token { EMPTY, PLAYER_1, PLAYER_2 };
    Token currentToken;
    std::vector<std::vector<Token>> board;
    bool userOne = true;

public:
    enum class Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

    Game(Token currentToken = Token::EMPTY, bool userOne = true);

    void play(int row, int col);
    bool getUserOne() const;
    bool checkWin(Token player) const;
    bool columnEmpty(int columnIndex) const;
    Status gameStatus() const;
    void reset();
    void draw(SDL_Renderer* renderer) const;

    friend std::ostream& operator<<(std::ostream& os, const Game& conFour);
};
