
#ifndef SHOOTING_GAME_GAME_H
#define SHOOTING_GAME_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/Window/ContextSettings.hpp"
#include "Player.h"

//#include <tkDecls.h>


class Game
{
private:
    sf::RenderWindow* window;
    void initWindow();
public:
    Game();


    virtual ~Game();
    // Functions
    void run();
    void update();
    void render();

};




#endif //SHOOTING_GAME_GAME_H

