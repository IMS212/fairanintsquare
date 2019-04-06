#include "npc.hpp"
#include <string>

unsigned int sq::npc::get_speed() const
{
  return speed;
}

void sq::npc::set_speed(unsigned int input)
{
  speed = input;
}

unsigned int sq::npc::get_running_speed()
{
  return running_speed;
}

void sq::npc::set_running_speed(unsigned int input)
{
  running_speed = input;
}

void sq::npc::set_name(std::string input)
{
  name = input;
}

void sq::npc::up()
{
  movement.y -= speed + (running_speed * running + 1);
  if (movement.y < -max_speed)
  {
    movement.y = -max_speed;
  }
  base.setTextureRect(sf::IntRect(17 + 16, 0, 16, 16));
}

void sq::npc::down()
{
  movement.y += speed + (running_speed * running + 1);
  if (movement.y > max_speed)
  {
    movement.y = max_speed;
  }
  base.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

void sq::npc::left()
{
  movement.x -= speed + (running_speed * running + 1);
  if (movement.x < -max_speed)
  {
    movement.x = -max_speed;
  }
  base.setTextureRect(sf::IntRect(17, 0, 16, 16));
  scale(1, 1);
}

void sq::npc::right()
{
  movement.x += get_speed() + (get_running_speed() * running + 1);
  if (movement.x > max_speed)
  {
    movement.x = max_speed;
  }
  base.setTextureRect(sf::IntRect(17, 0, 16, 16));
  scale(-1, 1);
}

void sq::npc::stop()
{
  movement.x = 0;
  movement.y = 0;
}

// Scaling is only ever used to flip the texture
void sq::npc::scale(int t_x, int t_y) { base.setScale(t_x, t_y); }

sq::npc::npc() : name("")
{
  base.setSize(sf::Vector2f(16, 16));
  // Origin to center to facilitate texture flipping
  base.setOrigin(8, 8);
}

sq::npc::npc(int t_x, int t_y) : name("")
{
  base.setSize(sf::Vector2f(16, 16));
  base.move(sf::Vector2f(t_x, t_y));
  // Origin to center to facilitate texture flipping
  base.setOrigin(8, 8);
}

sq::npc::npc(int t_x, int t_y, std::string input) : name(input)
{
  base.setSize(sf::Vector2f(16, 16));
  base.move(sf::Vector2f(t_x, t_y));
  // Origin to center to facilitate texture flipping
  base.setOrigin(8, 8);
}

sq::npc::npc(std::string input) : name(input)
{
  base.setSize(sf::Vector2f(16, 16));
  base.setOrigin(8, 8);
}

sq::npc::~npc() {}