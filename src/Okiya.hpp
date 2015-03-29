#ifndef OKIYA_HPP
#define OKIYA_HPP

#include <iostream>
#include "Board.hpp"

class Okiya {
public:
  Okiya();
  ~Okiya();

  void run();
  
  
private:
  void init();
  void quit();

  Board* board;
};

#endif
