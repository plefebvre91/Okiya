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
  //Constructor/Destructor
  Board();
  ~Board();

  //Adds a player pawn to the board
  void play(OkiyaPlayer player, int tile, int position);
  
  //Returns true if the given move is possible
  bool isPossibleToPlayHere(int tile, int position);
  
  //Returns true if one of player has won
  bool checkVictory();
  
  //Returns the last removed tile index 
  int getTileOnTop();

  //Return the tile index in deck (useful after shuffling) 
  int get(int);
  
private:
  void shuffle();
  int board[OKIYA_NB_TILES];
  int tileOnTop;
};

#endif
