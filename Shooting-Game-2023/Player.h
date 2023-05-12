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
#include<iostream>
class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed;

    // private functions
    void initTexture();
    void initSprite();

public:
    Player();
    virtual~Player();

    //Accessor
    const sf::Vector2f&getPos() const;

    //    Functions
    void move(const float dirX, const float dirY);

    void update();
    void render(sf::RenderTarget& target);


};
#endif //SHOOTING_GAME_PLAYER_H
