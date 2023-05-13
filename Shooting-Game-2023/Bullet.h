//
// Created by khaled saleh on 2023-05-11.
//

#ifndef SHOOTING_GAME_BULLET_H
#define SHOOTING_GAME_BULLET_H
#include "SFML/Graphics.hpp"
#include "iostream"
class Bullet {
private:
    sf::Sprite shape;

    sf::Vector2f direction;
    float movementSpeed;




public:
    Bullet();
    Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
    virtual ~Bullet();
    //Access to get the position
    const sf::FloatRect getBounds() const;

    void update();
    void render(sf::RenderTarget* target);



};











#endif //SHOOTING_GAME_BULLET_H
