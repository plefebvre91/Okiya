#include "Okiya.hpp"

Okiya::Okiya():event() {
  std::srand(std::time(0));
  board = new Board();

  tiles = new Tile*[OKIYA_NB_TILES];
  tilesSprites = new sf::Sprite*[OKIYA_NB_TILES];
  tilesTexture = new sf::Texture();
  
  if(!tilesTexture->loadFromFile("../resources/img/default/tuiles2.png")){
    printf("Erreur chargement fichier\n");
  }

  tilesTexture->setSmooth(true);

  int x,y;
  for(int i=0; i<OKIYA_NB_TILES; i++){
    x = (i/4) * OKIYA_TILES_SIZE;
    y = (i%4) * OKIYA_TILES_SIZE;
    tiles[i] = new Tile();
    tilesSprites[i] = new sf::Sprite(*tilesTexture, sf::IntRect(x,y,  OKIYA_TILES_SIZE, OKIYA_TILES_SIZE));
    tilesSprites[i]->setPosition(sf::Vector2f(x,y));
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

  delete [] tiles;
  delete window;
  //  delete renderingThread;

}

// void rendering(const Okiya* app) {
//   sf::RenderWindow* window = app->getWindow();
//   sf::Sprite* sprite = NULL;
//   while (window->isOpen()) {

//   }
// }

void Okiya::render() {
  window->clear(sf::Color(20,20,20));
  for(int i=0; i<OKIYA_NB_TILES; i++){


    int x = (i/4) * OKIYA_TILES_SIZE;
    int y = (i%4) * OKIYA_TILES_SIZE;
    tilesSprites[board->get(i)]->setPosition(sf::Vector2f(x,y));

    //Si c'est une tuile
    if(board->get(i) < 17) {
      window->draw(*tilesSprites[board->get(i)]);
    }
  }
  
  window->display();
}

void Okiya::run() {
  init();
  std::cout << "Lancement Okiya" << std::endl;

  //  window->setActive(false);
  //  renderingThread->launch();



  while (window->isOpen()) {
    while (window->pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
	window->close();
	break;

      case sf::Event::KeyPressed:
	window->setPosition(sf::Vector2i(500,20));
	break;

      default: break;
      }
    }
    
    render();
  }
}
  
  
void Okiya::init() {
  window = new sf::RenderWindow(sf::VideoMode(OKIYA_RESOLUTION_X, OKIYA_RESOLUTION_Y), 
				OKIYA_TITLE,
				sf::Style::Default);
  
  window->setVerticalSyncEnabled(true);
  window->setFramerateLimit(20);
  
  
  //    renderingThread = new sf::Thread(rendering, this);
}


void Okiya::quit() {
  
}


