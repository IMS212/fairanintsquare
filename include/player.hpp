#ifndef PLAYER_H
#define PLAYER_H
#include "npc.hpp"
namespace sq
{
class player : public npc
{
public:
  player();

  player(int t_x, int t_y);
};
} // namespace sq
#endif
