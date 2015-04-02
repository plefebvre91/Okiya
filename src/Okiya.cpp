#include "Okiya.hpp"

Okiya::Okiya():event(),gameArea(),focusArea() {
  std::srand(std::time(0));
  board = new Board();

  tiles = new Tile*[OKIYA_NB_TILES];
  tilesSprites = new sf::Sprite*[OKIYA_NB_TILES];
  tilesPosition = new sf::Vector2f*[OKIYA_NB_TILES];
  tilesTexture = new sf::Texture();

  if(!tilesTexture->loadFromFile("../resources/img/default/tuiles2.png")){
    printf("Erreur chargement fichier\n");
  }

  tilesTexture->setSmooth(true);

  int x,y;
  int padding = 10;
  sf::Vector2f globalPadding(20,20);

  for(int i=0; i<OKIYA_NB_TILES; i++){

    x = i/4;
    y = i%4;

    sf::Vector2f offset(x*padding, y*padding);

    sf::Vector2f position(x*OKIYA_TILES_SIZE,y*OKIYA_TILES_SIZE);

    tiles[i] = new Tile();
    tilesPosition[i] = new sf::Vector2f(0,0);
    tilesSprites[i] = new sf::Sprite(*tilesTexture, sf::IntRect(position.x,position.y,  OKIYA_TILES_SIZE, OKIYA_TILES_SIZE));
  
  }

  for(int i=0; i<OKIYA_NB_TILES; i++){
    x = i/4;
    y = i%4;

    sf::Vector2f offset(x*padding, y*padding);
    sf::Vector2f position(x*OKIYA_TILES_SIZE,y*OKIYA_TILES_SIZE);

    sf::Vector2f p(position+offset+globalPadding);
    tilesPosition[board->get(i)]->x = p.x;
    tilesPosition[board->get(i)]->y = p.y;
    tilesSprites[board->get(i)]->setPosition(p);
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
    delete tilesPosition[i];
    delete tilesSprites[i];
  }
  
  delete tilesTexture;
  delete [] tilesPosition;
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
  sf::Vector2f globalPadding(20,20);
  int padding = 10;

  sf::RectangleShape* r = new sf::RectangleShape();
  for(int i=0; i<OKIYA_NB_TILES; i++){
    gameArea = sf::Rect<int>(globalPadding.x, globalPadding.y, 4*OKIYA_TILES_SIZE + 3*padding, 4*OKIYA_TILES_SIZE + 3*padding);
    
    //     sf::RectangleShape* r = new sf::RectangleShape(sf::Vector2f(4*OKIYA_TILES_SIZE + 3*padding, 4*OKIYA_TILES_SIZE + 3*padding));
    r->setOutlineThickness(1);
    r->setFillColor(sf::Color(250,230,100,5));
    
    r->setOutlineColor(sf::Color(250, 230, 100));
    r->setPosition(focusArea.left,focusArea.top);
    r->setSize(sf::Vector2f(OKIYA_TILES_SIZE, OKIYA_TILES_SIZE));
    
    //Si c'est une tuile
    if(board->get(i) < 17) {
      window->draw(*tilesSprites[board->get(i)]);
    }
    window->draw(*r);

  }
  delete r;
  window->display();
}

int Okiya::getTileFromMouse(int x, int y) {
  int a,b;
  int padding = 10;
  sf::Vector2f globalPadding(20,20);

  for(int i=0; i<OKIYA_NB_TILES; i++){
   a = i/4;
   b = i%4;

    sf::Vector2f offset(a*padding, b*padding);
    sf::Vector2f position(a*OKIYA_TILES_SIZE,b*OKIYA_TILES_SIZE);
   
    sf::Rect<int> r(position.x+20+offset.x, position.y+20+offset.y, OKIYA_TILES_SIZE, OKIYA_TILES_SIZE);
    if(r.contains(x,y)){
      focusArea = r;

        return      board->get(i) ;
    }
    



}
  return 0;
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
	
      case sf::Event::MouseMoved:
	getTileFromMouse(event.mouseMove.x, event.mouseMove.y);
	
	break;

      case sf::Event::KeyPressed:
	
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


