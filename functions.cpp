#include "header.h"

void mainMenu(bool& startGame, Game& game, Objects& Player, Objects& Background, Objects startButton, double deltaTime)
{
    while(startGame == false)
    {
        game.events();
        game.clear();
        Background.moveBackground(deltaTime, WINDOW_SIZE_X);
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }
        game.drawSprite(Player.player);
        game.drawSprite(startButton.button);
        Player.animateSprite();
        
        startButton.updateButton(game.e, game.window);

        game.display();

        if(startButton.getButtonState() == clicked)
        {
            startGame = true;
        } else {
            startGame = false;
        }
    }
}

void gameRun(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects& Player, Objects& Obstacles, Objects& Coins, double deltaTime)
{
    while(startGame == true && failedGame == false)
    {
        game.events();
        game.clear();
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }
        game.drawSprite(Player.player);
        Player.animateSprite();
        Background.moveBackground(deltaTime, WINDOW_SIZE_X);
        Player.movePlayer(game.window);
        
        

    }
}

void deathScreen()
{

}