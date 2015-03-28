#include "Constraint.hpp"

Constraint::Constraint() {
  constraints = NO_CONSTRAINT;
}

Constraint::~Constraint();
  
void Constraint::add(int c) {
  constraints |= c;
}


void Constraint::remove(int c) {
  constraint &= ~c;
}


void Constraint::clear() {
  constraints = NO_CONSTRAINT;
}


bool Constraint::isSet(int c) {
  int count = 0;

  while(c != 1) {
    c >>= 1;
  }
  
  return constraint & ~c;
}


