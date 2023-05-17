//
// Created by khaled saleh on 2023-05-14.
//

#include "Enemy.h"

class FloatRect;

Enemy::Enemy(float pos_x, float pos_y) {
    this->initShape();
    this->initVariables();
    this->shape.setPosition(pos_x, pos_y);




}

Enemy::~Enemy() {

}

//Acessor
const sf::FloatRect Enemy::getBounds()  const {
    return this->shape.getGlobalBounds();
}


void Enemy::initShape() {
    this->shape.setRadius(rand() % 20 + 20);
    this->shape.setPointCount(rand() % 20 + 3);
    this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

void Enemy::initVariables() {
    this->type = 0;
    this->hpMax = 10;
    this->speed=5.f;
    this->hp = 0;
    this->damage = 1;
    this->points = 5;

}
// Functions
void Enemy::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}

void Enemy::update() {
    this->shape.move(0.f, this->speed)

}


