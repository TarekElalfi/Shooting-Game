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
    float attackCooldown;
    float attackCooldownMax;

    // private functions
    void initVariables();
    void initTexture();
    void initSprite();

public:
    Player();
    virtual~Player();

    //Accessor
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;
    //    Functions
    void move(const float dirX, const float dirY);

    const bool canAttcak();
    void updateAttack();
    void update();
    void render(sf::RenderTarget& target);


};
#endif //SHOOTING_GAME_PLAYER_H
