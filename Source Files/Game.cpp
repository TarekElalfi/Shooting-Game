//
// Created by khaled saleh on 2023-05-09.
//

#include "../Header Files/Game.h"
//here we gonna have our private functions
void Game::initWindow() {
 this-> window = new sf:: RenderWindow(sf::VideoMode(800,600),"Shooting Game", sf::Style::Close |sf::Style:: Titlebar )
}
// CONS
Game::Game() {
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

}
void Game:: render()
{
    this ->window->clear(); // to clear the old frame
    //Draw all the stuff we gonna build
    this -> window-> display();


}



