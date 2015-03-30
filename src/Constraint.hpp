#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include "Definitions.hpp"

class Constraint {

public:
  //Constructor/Destructor
  Constraint();
  Constraint(int);

  //Adds a new constraint
  void add(int);

  //Returns an interger representing constraint (bit=1 if constraint is set, 0 otherwise)
  int get();

  //Removes aconstraint
  void remove(int);
  
  //Removes all constraints
  void clear();

  //Returns true if the given constraint is set
  bool isSet(int);

private:
  int constraint;
};

#endif
