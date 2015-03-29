#include "Board.hpp"

Board::Board() {
  shuffle();
  tileOnTop = OKIYA_NO_TILE_ON_TOP;

  for(int i=0; i<OKIYA_NB_TILES; i++){
    board[i] = i;
  }
}

Board::~Board() {

}

void Board::play(int player, int tile, int position) {
  tileOnTop = tile;
  board[position] = player;
}

bool Board::checkVictory() {
  return false;
}

void Board::shuffle() {
  int randomIndex;

  for(int i=OKIYA_NB_TILES-1; i>1; i--) {
    randomIndex = std::rand()%(i+1);
    std::swap(board[i], board[randomIndex]);
  }
}
