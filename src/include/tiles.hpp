#ifndef TILES_H
#define TILES_H

#include "SFML/Graphics.hpp"

namespace sq
{
class tile
{
protected:
  sf::Texture texture;
  sf::RectangleShape base;

public:
  tile();
  virtual ~tile() = 0;
  tile(unsigned int t_x, unsigned int t_y);
  int getXPos() const;
  int getYPos() const;
  void show(sf::RenderWindow &window);
  void setTexture(const std::string &&name, const int posX, const int posY, const int sizeX, const int sizeY);
  void setTexture(const sf::Texture texture, const int posX, const int posY, const int sizeX, const int sizeY);
  void setColour(const unsigned int r, const unsigned int g, const unsigned int b);
  void setColour(const sf::Color &colour);
  void setPosition(int t_x, int t_y);
  void move(int t_x, int t_y);
  void move(sf::Vector2f &movement);
};
} // namespace sq

#endif