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
  Okiya();
  ~Okiya();

  void run();
  
  friend void rendering(const Okiya* app);
  
  sf::RenderWindow* getWindow() const;
  sf::Sprite* getSprite(int i) const;

private:
  
  void init();
  void quit();
  Tile** tiles;
  sf::RenderWindow* window;
  sf::Event event;
  sf::Thread*  renderingThread;
  sf::Texture* tilesTexture;
  sf::Sprite** tilesSprites;
  
  
  Board*  board;

  

};

#endif
