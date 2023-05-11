//
// Created by khaled saleh on 2023-05-09.
//

#ifndef SHOOTING_GAME_GAME_H
#define SHOOTING_GAME_GAME_H
#include <SFML/Graphics.hpp>
#include <include/SFML/Graphics.hpp>


#include <tkDecls.h>


class Game
 {
private:
     sf:RenderWindow* window;
     void initWindow();

 public:
     Game();


 virtual ~Game();
     // Functions
     void run();
     void update();
     void render();

 };




#endif //SHOOTING_GAME_GAME_H
