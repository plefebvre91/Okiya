#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include "Definitions.hpp"
#include <utility>
#include <ctime>
#include <cstdlib>
#include <iostream>

class Board {
public:
  Board();
  ~Board();

  void play(int player, int tile, int position);
  bool checkVictory();
  int getTileOnTop();
  
  
private:
  void shuffle();
  int board[OKIYA_NB_TILES];
  int tileOnTop;
};

#endif
