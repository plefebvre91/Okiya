#ifndef OKIYA_HPP
#define OKIYA_HPP

#include "Board.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"



class Okiya {
public:
  //Constructor/Destructor
  Okiya();
  ~Okiya();

  //Starts the game
  void run();

  //  friend void rendering(const Okiya* app);
private:
  //Initializes SFML, tiles, and board
  void init();

  //Displays the game board
  void render();

  //Stops game and frees memory
  void quit();

  Tile** tiles;
  Board*  board;

  sf::RenderWindow* window;
  sf::Event event;
  //  sf::Thread*  renderingThread;
  sf::Texture* tilesTexture;
  sf::Sprite** tilesSprites;
};
#endif
