#ifndef OKIYA_HPP
#define OKIYA_HPP

#include "Board.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"

class Okiya {
public:
  Okiya();
  ~Okiya();

  void run();
  
  
private:
  void init();
  void quit();

  Tile* tiles[OKIYA_NB_TILES];
  sf::RenderWindow* window;
  sf::Event event;
  Board* board;
};

#endif
