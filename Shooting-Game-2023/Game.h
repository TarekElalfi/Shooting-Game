
#ifndef SHOOTING_GAME_GAME_H
#define SHOOTING_GAME_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/Window/ContextSettings.hpp"
#include <map>
#include "Player.h"
#include "External/include/SFML/Graphics/Texture.hpp"

//#include <tkDecls.h>


class Game
{
private:
    //Window
    sf::RenderWindow* window;

    //Resources
    std::map<std::string ,sf::Texture> textures;


    //Player
    Player* player;

    void initWindow();
    void initTextures();
    void initPlayer();
public:
    Game();


    virtual ~Game();
    // Functions
    void run();

    void updatePollEvents();
    void updateInput();

    void update();
    void render();

};




#endif //SHOOTING_GAME_GAME_H

