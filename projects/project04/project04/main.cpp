#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2_gfxPrimitives.h>

#include "Game.h"
#include "Engine.h"

void drawWinScreen(Game& game, Engine& engine)
{
    auto status = game.gameStatus();
    std::string msg;
    SDL_Color bgColor;
    SDL_Color textColor;
    if (status == Game::PLAYER_1_WINS)
    {
        msg = "X WON IN "+std::to_string(game.moveCount()) + " MOVES!!!";
        bgColor = { 0,0,0,200 };
        textColor = { 255,255,255,255 };
    }

    else if (status == Game::O_WON)
    {
        msg = "O WON IN " + std::to_string(game.moveCount()) + " MOVES!!!";
        bgColor = { 255,255,255,200 };
        textColor = { 0,0,0,255 };
    }
    else
    {
        msg = "DRAW";
        bgColor = { 128,128,128,200 };
        textColor = { 255,255,255,255 };
    }
    engine.drawRectangle(350, 350, 700, 700, bgColor);
    engine.drawText(msg, 350, 350, textColor);
    engine.drawText("Press space to play again.", 350, 650, textColor);
}

int main() {

    Engine engine;
   /* while (true)
    {
        engine.clear();
        engine.drawCircle(300, 300, 100);
        engine.drawRectangle(300, 300);
        engine.drawText("Hello, SDL2!", 300, 300);
        engine.flip();
    }*/






    Game game;
    bool running = true;
    SDL_Event event;
    int row = 0;
    int col = 0;

    while (running)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                if (event.key.keysym.sym == SDLK_SPACE)
                {

                    if (game.getStatus() != Game::ONGOING) game=Game();
                }
            }

            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int col = event.button.x / 100;
                int row = event.button.y / 100;
                if (game.getStatus() == Game::ONGOING)
                {
                    game.play(row, col);
                    engine.playSound();
                }
                
                //x = event.motion.x;
            }

            else if (event.type == SDL_MOUSEMOTION)
            {
                col = event.motion.x / 100;
                row = event.motion.y / 100;
                if (game.getStatus() != Game::ONGOING)
                {
                    col = -1;
                    row = -1;
                }
                //x = event.motion.x;
            }
        }


        

        engine.clear();
        game.draw(&engine,row,col);

        if (game.getStatus() != Game::ONGOING) drawWinScreen(game, engine);


        engine.flip();
    }
        


    return 0;
}
