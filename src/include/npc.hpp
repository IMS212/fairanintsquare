#ifndef NPC_H
#define NPC_H

#include "tiles.hpp"
namespace sq
{
class npc : public tile
{

private:
  std::string name;
  unsigned int speed = 1;
  int maxSpeed = 6;
  unsigned int runningSpeed = 6;

public:
  sf::Vector2f movement = {0, 0};
  bool running = false;

public:
  npc();
  ~npc();
  npc(int t_x, int t_y);
  npc(int t_x, int t_y, std::string input);
  npc(std::string input);
  unsigned int getSpeed() const;
  void setSpeed(unsigned int input);
  unsigned int getRunningSpeed();
  void setRunningSpeed(unsigned int input);
  void setName(std::string input);
  virtual void up();
  virtual void down();
  virtual void left();
  void right();
  void stop();
  //Scaling is only ever used to flip the texture
  void scale(int t_x, int t_y);
};
} // namespace sq
#endif
