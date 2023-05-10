//
// Created by khaled saleh on 2023-05-10.
//

#ifndef SHOOTING_GAME_PLAYER_H
#define SHOOTING_GAME_PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/Window/ContextSettings.hpp"
#include "SFML/System.hpp"
class Player {
private:
 sf::Sprite sprite;
 sf::Texture texture;

 // private functions
 void initTexture();
void initSprite();

public:
    Player();
    virtual~Player();


//    Functions

void update();
void render( sf::RenderTarget& target);


};
#endif //SHOOTING_GAME_PLAYER_H
