//
// Created by khaled saleh on 2023-05-11.
//

#ifndef SHOOTING_GAME_BULLET_H
#define SHOOTING_GAME_BULLET_H
#include "External/include/SFML/Graphics.hpp"
#include "iostream"
class Bullet{
private:
    sf::Sprite shape;

    sf::Vector2f direction;
    float movementSpeed;




public:
    Bullet();
    Bullet(sf::Texture& texture, float dir_x, float dir_y, float movement_speed);
    virtual ~Bullet();

    void update();
    void render(sf::RenderTarget* target);



};











#endif //SHOOTING_GAME_BULLET_H
