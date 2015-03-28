#include "Constraint.hpp"

Constraint::Constraint() {
  constraint = NO_CONSTRAINT;
}

void Constraint::add(int c) {
  constraint |= c;
}


void Constraint::remove(int c) {
  constraint &= ~c;
}


void Constraint::clear() {
  constraint = NO_CONSTRAINT;
}


bool Constraint::isSet(int c) {
  int count = 0;

  while(c != 1) {
    c >>= 1;
  }
  
  return constraint & ~c;
}


