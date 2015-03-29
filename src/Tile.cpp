#include "Tile.hpp"

Tile::Tile() {
  position = new Point();
  constraint = new Constraint();
}


Tile::~Tile() {
  delete position;
  delete constraint;
}


int  Tile::getConstraint() {
  return constraint->get();
}


bool Tile::isOnBoard() {
  return onBoard;
}


void Tile::removeFromBoard() {
  onBoard = false;
}


void Tile::setConstraint(int c) {
  constraint->add(c);
}


