#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include "Definitions.hpp"

class Board {
public:
  Board();
  ~Board();
  
  void shuffle();
  

private:
  Tile* tiles[OKIYA_NB_TILES];
  int deck[OKIYA_NB_TILES];
};

#endif
