#include "Tile.hpp"

Tile::Tile() {
  position = new Point();
  constraint = new Constraint();
}


Tile::~Tile() {
  delete position;
  delete constraint;
}


int  Tile::getConstraint() const {
  return constraint->get();
}


bool Tile::isOnBoard() const {
  return onBoard;
}


void Tile::removeFromBoard() {
  onBoard = false;
}


void Tile::setConstraint(int c) {
  constraint->add(c);
}

bool Tile::isCompatibleWith(const Tile& tile) const {
  int c1 = getConstraint();
  int c2 = tile.getConstraint();
  
  return (c1 & c2);
}
