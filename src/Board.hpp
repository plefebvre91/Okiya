#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include "Definitions.hpp"
#include <utility>
#include <ctime>
#include <cstdlib>
#include <iostream>

enum OkiyaPlayer {OLIYA_PLAYER1=-1, OKIYA_PLAYER2=-2};

class Board {
public:
  Board();
  ~Board();

  void play(OkiyaPlayer player, int tile, int position);
  bool checkVictory();
  int getTileOnTop();
  int get(int);
  
private:
  void shuffle();
  int board[OKIYA_NB_TILES];
  int tileOnTop;
};

#endif
