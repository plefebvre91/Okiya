#ifndef TILE_HPP
#define TILE_HPP

#include "Constraint.hpp"
#include "Point.hpp"

class Tile {
public:
  Tile();
  ~Tile();

  int getConstraint();
  bool isOnBoard();
  void removeFromBoard();
  void setConstraint(int);

private:
  Constraint* constraint;
  Point* position;
  bool onBoard;
};

#endif
