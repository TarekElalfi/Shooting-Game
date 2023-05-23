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
void Game::initEnemies()
{
    this->timerMax = 50.f;
    this->spawnTimer = this->timerMax;
}
// CONS
Game::Game()
{
    this->initGUI();
    this->initWindow();
    this->initTextures();
    this->initWorld();
    this->initPlayer();
    this->initEnemies();
    

}

Game::~Game() {
    delete this->window;
    delete this->player;

    // Delete the texutres
    for (auto& i : this->textures) {
        delete i.second;
    }

    //delete bullets
    for (auto* i : this->bullets)
    {
        delete i;
    }
    //delete all enemies
    for (auto* i : this->enemies)
    {
        delete i;
    }
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
    this->player->update();
    this->updateCollosions();
    this->updateBullets();
    this->updateEnemies();
    this->updateGUI();
    this->updateCombat();
    this->updateworld();
}
void Game::updateGUI()
{
}
void Game::renderGUI()
{
    this->window->draw(this->pointText);
}
void Game::render()
{
    
    this->window->clear();
    this->renderWorld();
    // to clear the old frame
    //Draw all the stuff we gonna build
    this->player->render(*this->window);

    for (auto* bullet : this->bullets)
    {
        bullet->render(this->window);
    }
    for (auto* enemy : this->enemies)
    {
        enemy->render(this->window);
    }
    this->renderGUI();
    this->window->display();


}

void Game::updateworld()
{
}

void Game::updateCollosions()
{
    if (this->player->getBounds().left < 0.f) {
        this->player->setPosition(0.f,this->player->getBounds().top);
    }
}

void Game::renderWorld()
{
    this->window->draw(this->worldBackground);
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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttcak())
    {
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 0.f, -1.f, 5.f));

    }

}

void Game::initTextures()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("Textures/bullet.png");

}

void Game::initGUI()
{
    //to load the font
    if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf")) {
        std::cout << "Error in fonts"<<"\n";
    }
    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(12);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setString("test");

    //init point text
}

void Game::initWorld()
{
    if (!this->worldBackgroundTexture.loadFromFile("Textures/background1.jpg")) {
        std::cout << "Background Can NOT be loaded"<<"\n";
    }
    this->worldBackground.setTexture(this->worldBackgroundTexture);
}

void Game::updateBullets() {

    unsigned counter = 0;

    for (auto* bullet : this->bullets)
    {
        bullet->update();

        if (bullet->getBounds().top + bullet->getBounds().height < 0.f) {

            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            --counter;
        }
        ++counter;
    }


}


void Game::updateCombat()
{
    
    for (int i = 0; i < enemies.size(); i++)
    {
        bool enemy_deleted = false;
        for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++) {
            if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds())) {
                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin()+i);
                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k);
                enemy_deleted = true;
            
            }
        }
    }
}

void Game::updateEnemies()
{


    this->spawnTimer += 0.5f;
    if (this->spawnTimer>=this->timerMax) {
        
        this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f));
        this->spawnTimer = 0.f;

    
    }


    unsigned counter = 0;

    for (auto* enemy : this->enemies)
    {
        enemy->update();

        if (enemy->getBounds().top> this->window->getSize().y) {

            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
            --counter;
        }
        ++counter;
    }

}


