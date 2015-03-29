#include <iostream>
#include "Okiya.hpp"

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;

  //Initializes board game, tiles and window
  Okiya* app = new Okiya();

  //Starts game
  app->run();

  //Frees memory
  delete app;

  return 0;
}
