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
  int get_pos_x() const;
  int get_pos_y() const;
  void show(sf::RenderWindow &window);
  void set_texture(const std::string &&name, const int posX, const int posY, const int sizeX, const int sizeY);
  void set_texture(const sf::Texture texture, const int posX, const int posY, const int sizeX, const int sizeY);
  void set_colour(const unsigned int r, const unsigned int g, const unsigned int b);
  void set_colour(const sf::Color &colour);
  void set_position(int t_x, int t_y);
  void move(int t_x, int t_y);
  void move(sf::Vector2f &movement);
};
} // namespace sq

#endif