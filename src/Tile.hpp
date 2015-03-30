#ifndef TILE_HPP
#define TILE_HPP

#include "Constraint.hpp"
#include "Point.hpp"

class Tile {
public:
  //Constructor/Destructor
  Tile();
  ~Tile();

  //Returns an integer representing the card constraint
  int getConstraint();

  //Return true if card is still on board game
  bool isOnBoard();

  //Swaps tile and player pawn
  void removeFromBoard();

  //Attaches a constraint
  void setConstraint(int);

private:
  Constraint* constraint;
  Point* position;
  bool onBoard;
};

#endif
