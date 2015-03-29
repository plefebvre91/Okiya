#include "Okiya.hpp"

Okiya::Okiya() {
  board = new Board();
}


Okiya::~Okiya() {
  delete board;
}


void Okiya::run() {
  std::cout << "Lancement Okiya" << std::endl;
}


void Okiya::init() {
}


void Okiya::quit() {

}


