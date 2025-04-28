/*
    Elisha Dollinger
    Project04
    CPSC2376
    Spring 2025
 */

#define SDL_MAIN_HANDLED
/*
    The SDL headers can't have SDL2/ in front of them in XCode. Please do not count off for that. This code is running in XCODE
    In VSCode, just include "SDL2" before each SDL header and it will operate
 */
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL2_gfxPrimitives.h>

#include "Game.h"
#include "Engine.h"


const int cellSize = 100;
const int width = 700;
const int height = 600;

/*
    Centers the text for who wins and prints it when a winner is determined
 */
void drawWinScreen(Game& game, Engine& engine)
{
    auto status = game.gameStatus();
    std::string msg;
    SDL_Color bgColor;
    SDL_Color textColor;

    if (status == Game::Status::PLAYER_1_WINS)
    {
        msg = "Player 1 wins!";
        bgColor = { 0, 0, 0, 200 };
        textColor = { 255, 255, 255, 255 };
    }
    else if (status == Game::Status::PLAYER_2_WINS)
    {
        msg = "Player 2 wins!";
        bgColor = { 255, 255, 255, 200 };
        textColor = { 0, 0, 0, 255 };
    }
    else
    {
        msg = "Draw!";
        bgColor = { 128, 128, 128, 200 };
        textColor = { 255, 255, 255, 255 };
    }

    engine.drawRectangle(width/2, height/2, 600, 200, bgColor);

    engine.drawText(msg, width/2, height/2 - 30, textColor);
    engine.drawText("Press SPACE to restart", width/2, height/2 + 30, textColor);
}


int main()
{
    //Include font and sound
    Engine engine("My Game", width, height, "/System/Library/Fonts/Supplemental/Arial.ttf", 24, "sound.wav");

    Game game;
    bool running = true;
    SDL_Event event;

    /*
        This happens while the game is running
        Operates the code by checking mouse clicked, key down, etc
    */
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
                else if (event.key.keysym.sym == SDLK_SPACE)
                {
                    if (game.gameStatus() != Game::Status::ONGOING)
                    {
                        game = Game();
                    }
                }
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (game.gameStatus() == Game::Status::ONGOING)
                {
                    int mouseX = event.button.x;
                    int clickedCol = mouseX / cellSize;

                    //Only allow clicking inside board
                    if (clickedCol >= 0 && clickedCol < 7)
                    {
                        game.play(clickedCol);
                        engine.playSound();
                    }
                }
            }

        }

        //Clears the engine after the game is over
        engine.clear();
        game.draw(engine.getRenderer());

        //If the game is still going, draw the win screen
        if (game.gameStatus() != Game::Status::ONGOING)
        {
            drawWinScreen(game, engine);
        }

        //Show the renderer
        engine.flip();
    }

    return 0;
}
