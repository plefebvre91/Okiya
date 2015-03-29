#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include "Definitions.hpp"

class Constraint {

public:
  Constraint();
  Constraint(int);
  
  void add(int);
  int get();
  void remove(int);
  void clear();
  bool isSet(int);

private:
  int constraint;
};

#endif
