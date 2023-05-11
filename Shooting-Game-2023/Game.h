
#ifndef SHOOTING_GAME_GAME_H
#define SHOOTING_GAME_GAME_H
#include <External/include/SFML/Graphics.hpp>
#include "External/include/SFML/Window.hpp"
#include <External/include/SFML/Graphics.hpp>
//#include <tkDecls.h>
#include "External/include/SFML/Window/Window.hpp"
#include "External/include/SFML/Graphics/RenderWindow.hpp"
#include "External/include/SFML/Window.hpp"
#include "External/include/SFML/Window/ContextSettings.hpp"
#include "External/include/SFML/System.hpp"
#include "External/include/SFML/Window/Window.hpp"

//#include <tkDecls.h>


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
