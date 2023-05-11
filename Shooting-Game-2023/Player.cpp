//
// Created by khaled saleh on 2023-05-10.
//

#include "Player.h"
Player::Player() {
    this->movementSpeed = 2.f;
    this->initTexture();
    this->initSprite();

}

Player::~Player() {

}
void Player::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed * dirX,this->movementSpeed * dirY);
}
void Player::update() {


}
//& is the address operator
void Player::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Player::initTexture() {
    //Load the texture from file here
    if (!this->texture.loadFromFile("Textures/ship.png")) {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
    }
}

void Player::initSprite() {
    // set the texture to the sprite
    this->sprite.setTexture(this->texture);
    // resize sprite
    this->sprite.scale(0.1f, 0.1f);
}


