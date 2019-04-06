#pragma once
#include <SFML/Graphics.hpp>

namespace sq
{
class animation
{
private:
  sf::Vector2u img_pos;
  sf::Vector2u img_size;
  int img_count;
  float switch_time;
  float total_time = 0.0f;
  int current_img = 0;
  bool stopped = false;
  
public:
  sf::IntRect uv_rect;
  animation(const sf::Vector2u img_pos, const sf::Vector2u img_size, const int img_count, const float switcht);
  void update(float dt);
  void set_img_pos(const sf::Vector2u &pos);
  void set_current_img(int index);
  void update(int img_index);
  void set_stopped(bool status);
  bool status() const;
};
}