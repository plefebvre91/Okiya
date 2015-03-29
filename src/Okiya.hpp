#ifndef OKIYA_HPP
#define OKIYA_HPP

#include <iostream>
#include "Board.hpp"
#include <ctime>
#include <cstdlib>

class Okiya {
public:
  Okiya();
  ~Okiya();

  void run();
  
  
private:
  void init();
  void quit();

  Tile* tiles[OKIYA_NB_TILES];
  int tileOnTop;
  Board* board;
};

#endif
