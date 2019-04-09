#ifndef TILES_H
#define TILES_H

#include "SFML/Graphics.hpp"

namespace sq
{
class tile{
protected:
  sf::Texture texture;
  sf::RectangleShape base;

public:
  int getPosX() const;
  int getPosY() const;
  void show(sf::RenderWindow &window);
  void setTexture(const std::string &&name, const int posX, const int posY, const int sizeX, const int sizeY);
  void setTexture(const sf::Texture &texture, const int posX, const int posY, const int sizeX, const int sizeY);
  void setColour(const unsigned int r, const unsigned int g, const unsigned int b);
  void setColour(const sf::Color &colour);
  void setPosition(const int t_x, const int t_y);
  void move(const int t_x, const int t_y);
  void move(const sf::Vector2f &movement);
  tile(const unsigned int t_x, const unsigned int t_y);
  tile();
  virtual ~tile() = 0;
};
} // namespace sq

#endif