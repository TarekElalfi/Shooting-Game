#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Game.h"
#include <time.h>
int main()
{
    //check if it's good (initialize seed from time for random shapes)
    srand(static_cast<unsigned>(time(0)));

    Game game;
    game.run();

    return 0;

}
