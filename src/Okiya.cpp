#include "Okiya.hpp"

Okiya::Okiya() {
  std::srand(std::time(0));
  board = new Board();

  for(int i=0; i<OKIYA_NB_TILES; i++){
    tiles[i] = new Tile();
  }

  tiles[0]->setConstraint(OKIYA_LEAF | OKIYA_SUN);
  tiles[1]->setConstraint(OKIYA_LEAF | OKIYA_SKY);
  tiles[2]->setConstraint(OKIYA_LEAF | OKIYA_BIRD);
  tiles[3]->setConstraint(OKIYA_LEAF | OKIYA_REDTHING);

  tiles[4]->setConstraint(OKIYA_FLOWER | OKIYA_SUN);
  tiles[5]->setConstraint(OKIYA_FLOWER | OKIYA_SKY);
  tiles[6]->setConstraint(OKIYA_FLOWER | OKIYA_BIRD);
  tiles[7]->setConstraint(OKIYA_FLOWER | OKIYA_REDTHING);

  tiles[8]->setConstraint(OKIYA_TREE | OKIYA_SUN);
  tiles[9]->setConstraint(OKIYA_TREE | OKIYA_SKY);
  tiles[10]->setConstraint(OKIYA_TREE | OKIYA_BIRD);
  tiles[11]->setConstraint(OKIYA_TREE | OKIYA_REDTHING);

  tiles[12]->setConstraint(OKIYA_CACTUS | OKIYA_SUN);
  tiles[13]->setConstraint(OKIYA_CACTUS | OKIYA_BIRD);
  tiles[14]->setConstraint(OKIYA_CACTUS | OKIYA_SKY);
  tiles[15]->setConstraint(OKIYA_CACTUS | OKIYA_REDTHING);

  

}


Okiya::~Okiya() {
  delete board;
  
  for(int i=0; i<OKIYA_NB_TILES; i++){
    delete tiles[i];
  }
  
  delete window;
  
}


void Okiya::run() {
  init();
  std::cout << "Lancement Okiya" << std::endl;




  while (window->isOpen()) {
      while (window->pollEvent(event)) {
	if (event.type == sf::Event::Closed)
	  window->close();
      }
      window->clear(sf::Color(20,20,20));
      //...
      window->display();
  }

}

void Okiya::init() {
  window = new sf::RenderWindow(sf::VideoMode(OKIYA_RESOLUTION_X, OKIYA_RESOLUTION_Y), 
				OKIYA_TITLE,
				sf::Style::Titlebar);
  
  window->setVerticalSyncEnabled(true);
  window->setFramerateLimit(20);
}


void Okiya::quit() {

}


