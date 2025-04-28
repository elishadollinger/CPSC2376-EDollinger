#pragma once


#include <vector>
#include <iostream>
#include "Engine.h"

class Game {
public:
    // Simple (unscoped) enums now, scoped inside Game.
    enum Cell { BLANK, X, O };
    enum GameStatus { ONGOING, X_WON, O_WON, DRAW };

    // Constructor that sets up the board.
    Game(int boardSize = 7);

    // Prints the board to the console.
    void printBoard() const;

    // Attempts to play a move at (row, col). Returns false if move is illegal.
    bool play(int row, int col);

    // Returns the current status of the game.
    GameStatus getStatus() const;

    // Returns the current player's token.
    Cell getCurrentToken() const;

    void draw(Engine* e, int row = -1, int col = -1);

    int moveCount();

private:
    std::vector<std::vector<Cell>> board;
    int boardSize;

    // Helper functions.
    bool isFull() const;
    void horizontalBar() const;
};
