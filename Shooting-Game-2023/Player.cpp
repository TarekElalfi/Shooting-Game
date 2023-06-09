//
// Created by khaled saleh on 2023-05-10.
//

#include "Player.h"
Player::Player() {
    this->initVariables();
    this->initTexture();
    this->initSprite();

}

Player::~Player() {

}
void Player::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}
const bool Player::canAttcak()
{
    if (this->attackCooldown >= this->attackCooldownMax) {
        this->attackCooldown = 0.f;
        return true;
    }

    return false;

}
void Player::updateAttack()
{
    if (this->attackCooldown < this->attackCooldownMax) {
        this->attackCooldown += 0.5f;
    }

}
void Player::update() {
    this->updateAttack();

}
//& is the address operator
void Player::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Player::initVariables()
{
    this->movementSpeed = 3.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;
    
    this->hpMax = 100;
    
    this->hp = this->hpMax;

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



const sf::Vector2f& Player::getPos() const {
    return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
    return this->hp;

}

const int& Player::getHpMax() const
{
    return this->hpMax;
}


void Player::setPosition(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

void Player::loseHp(const int value)
{
    this->hp -= value;
    if (this->hp < 0) {
        this->hp = 0;
    }
}

void Player::setHp(const int hp)
{
    this->hp = hp;
}


