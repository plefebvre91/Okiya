#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#define NO_CONSTRAINT  0x0000
#define OKIYA_FLOWER   0x0001
#define OKIYA_BIRD     0x0002
#define OKIYA_SUN      0x0004
#define OKIYA_SKY      0x0008
#define OKIYA_TREE     0x0010
#define OKIYA_LEAF     0x0020
#define OKIYA_CACTUS   0x0040
#define OKIYA_REDTHING 0x0080

class Constraint {

public:
  Constraint();
  Constraint(int);
  
  void add(int);
  void remove(int);
  void clear();
  bool isSet(int);

private:
  int constraint;
};

#endif