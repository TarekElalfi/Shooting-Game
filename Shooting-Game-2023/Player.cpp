//
// Created by khaled saleh on 2023-05-10.
//

#include "Player.h"
Player::Player() {
    this->initTexture();
    this->initSprite();

}

Player::~Player() {

}
void Player::update() {


}
//& is the address operator
void Player::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Player::initTexture() {
    //Load the texture from file here
}

void Player::initSprite() {
    // set the texture to the sprite
    this->sprite.setTexture(this->texture);
}


