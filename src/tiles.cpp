#include "tiles.hpp"

int sq::tile::getPosX() const {
  return base.getPosition().x;
}

int sq::tile::getPosY() const {
  return base.getPosition().y;
}

void sq::tile::show(sf::RenderWindow &window){
  window.draw(base);
}

void sq::tile::setTexture(const std::string &&name, const int posX, const int posY, const int sizeX, const int sizeY){
  texture.loadFromFile(name);
  base.setTexture(&texture);
  base.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
}

void sq::tile::setTexture(const sf::Texture &ptexture, const int posX, const int posY, const int sizeX, const int sizeY){
  base.setTexture(&ptexture);
  base.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
}

void sq::tile::setColour(const unsigned int r, const unsigned int g, const unsigned int b){
  base.setFillColor(sf::Color(r, g, b));
}

void sq::tile::setColour(const sf::Color &colour){
  base.setFillColor(colour);
}

void sq::tile::setPosition(const int t_x, const int t_y){
  base.setPosition(sf::Vector2f(t_x, t_y));
}

void sq::tile::move(const int t_x, const int t_y){
  base.move(sf::Vector2f(t_x, t_y));
}

void sq::tile::move(const sf::Vector2f &movement){
  base.move(movement);
}

sq::tile::tile() : base(sf::Vector2f(16, 16))
{}

sq::tile::tile(const unsigned int t_x, const unsigned int t_y) : base(sf::Vector2f(16, 16)){
  base.move(sf::Vector2f(t_x, t_y));
}

sq::tile::~tile() {}
