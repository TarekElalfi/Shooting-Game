//
// Created by khaled saleh on 2023-05-09.
//

#include "../Header Files/Game.h"
//here we gonna have our private functions
void Game::initWindow() {
    this-> window = new sf:: RenderWindow(sf::VideoMode(800,600),"Shooting Game", sf::Style::Close |sf::Style:: Titlebar );
     this->window->setFramerateLimit(144);
     this->window->setVerticalSyncEnabled(false);
            ;}
// CONS
Game::Game()
{
    this -> initWindow();
}

Game::~Game() {
    delete this -> window;

}
//Functions


void Game::run()
{
    while (this->window -> isOpen()) //to keep updating and rendering while playing
    {
        this->update();
        this->render();
    }

}
void Game:: update()
{
    sf::Event e; //to close the game window
    while (this->window->pollEvent(e)){
        if(e.Event::type==sf::Event::Closed)
            this->window->close();
        if(e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Escape)
            this->window->close();
    }

}
void Game:: render()
{
    this ->window->clear(); // to clear the old frame
    //Draw all the stuff we gonna build
    this -> window-> display();


}


