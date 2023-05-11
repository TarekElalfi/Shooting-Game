//
// Created by khaled saleh on 2023-05-11.
//

#include "Bullet.h"

Bullet::Bullet() {

}

Bullet::~Bullet() {

}

Bullet::Bullet(sf::Texture &texture, float dir_x, float dir_y, float movement_speed)
{
    this->shape.setTexture(texture);
    this-direction.x=dir_x;
    this->direction.y=dir_y;
    this->movementSpeed= movement_speed;
}

void Bullet::update()
{ //movement of the bullet
    this->shape.move(this->movementSpeed* this->direction);
}

void Bullet::render(sf::RenderTarget *target) {
    target->draw(this->shape);

}
