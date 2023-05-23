
#ifndef SHOOTING_GAME_GAME_H
#define SHOOTING_GAME_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/Window/ContextSettings.hpp"
#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "SFML/Graphics/Texture.hpp"

//#include <tkDecls.h>


class Game
{
private:
    //Window
    sf::RenderWindow* window;

    //Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;


    //GUI
    sf::Font font;
    sf::Text pointText;
    sf::Texture worldBackgroundTexture;
    sf::Sprite worldBackground;

    //Player
    Player* player;
    float spawnTimer;
    float timerMax;
    std::vector<Enemy*> enemies;
   

    void initWindow();
    void initTextures();
    void initGUI();
    void initWorld();
    void initPlayer();
    void initEnemies();
public:
    Game();


    virtual ~Game();
    // Functions
    void run();

    void updatePollEvents();
    void updateInput();
    void update();
    void updateGUI();
    void renderGUI();
    void render();
    void updateworld();
    void updateCollosions();
    void renderWorld();
    void updateBullets();
    void updateEnemies();
    void updateCombat();

};




#endif //SHOOTING_GAME_GAME_H

