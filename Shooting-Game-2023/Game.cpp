//
// Created by khaled saleh on 2023-05-09.
//

#include "Game.h"
//here we gonna have our private functions
void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Shooting Game", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
    ;
}
void Game::initPlayer()
{
    this->player = new Player();
}
// CONS
Game::Game()
{
    this->initWindow();
    this->initPlayer();

}

Game::~Game() {
    delete this->window;
    delete this->player;

}
//Functions


void Game::run()
{
    while (this->window->isOpen()) //to keep updating and rendering while playing
    {
        this->update();
        this->render();
    }

}
void Game::update()
{
    this->updatePollEvents();
    this->updateInput();

}
void Game::render()
{
    this->window->clear(); // to clear the old frame
    //Draw all the stuff we gonna build
    this->player->render(*this->window);

    this->window->display();


}

void Game::updatePollEvents() {
    sf::Event e; //to close the game window
    while (this->window->pollEvent(e)) {
        if (e.Event::type == sf::Event::Closed)
            this->window->close();
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}

void Game::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f, 1.f);

}

void Game::initTextures() {

}


