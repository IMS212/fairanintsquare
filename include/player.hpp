#ifndef PLAYER_H
#define PLAYER_H

#include "npc.hpp"
namespace sq{
class player : public npc{
public:
  player();

  player(const int tX, const int tY);
};
} // namespace sq

#endif
