#include "Board.hpp"

Board::Board() {

  tileOnTop = OKIYA_NO_TILE_ON_TOP;

  for(int i=0; i<OKIYA_NB_TILES; i++){
    board[i] = i;
  }

  for(int i=0; i<OKIYA_NB_TILES; i++){
    std::cout << board[i] << " ";
  }
  std::cout<<std::endl;
  
  shuffle();

  for(int i=0; i<OKIYA_NB_TILES; i++){
    std::cout << board[i] << " ";
  }
  std::cout<<std::endl;
  for(int i=0; i<OKIYA_NB_TILES; i++){
    std::cout << get(i) << " ";
  }
  std::cout<<std::endl;

}

Board::~Board() {

}

void Board::play(OkiyaPlayer player, int tile, int position) {
  tileOnTop = tile;
  board[position] = player;
}

int Board::get(int position) {
  return board[position];
}

void Board::setDeck(Tile* tiles){
  deck = tiles;
}

bool Board::isPossibleToPlayHere(int tile, int position){
  // Premier coup
  if(tileOnTop == OKIYA_NO_TILE_ON_TOP){
    return true;
  }

  //tuile posée
  Tile& tileOnBoard = deck[tile];
  Tile& lastPlayedTile = deck[tileOnTop];

  return tileOnBoard.isCompatibleWith(lastPlayedTile) &&
    get(position) != OKIYA_PLAYER1 &&
    get(position) != OKIYA_PLAYER2;
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
