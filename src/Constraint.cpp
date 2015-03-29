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

int Constraint::get() {
  return constraint;
}

void Constraint::clear() {
  constraint = NO_CONSTRAINT;
}


bool Constraint::isSet(int c) {
  while(c != 1) {
    c >>= 1;
  }
  
  return constraint & ~c;
}

