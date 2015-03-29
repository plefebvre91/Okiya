#include <iostream>
#include "Okiya.hpp"

int main(int argc, char** argv) {
  
  Okiya* app = new Okiya();
  app->run();

  delete app;

  return 0;
}
