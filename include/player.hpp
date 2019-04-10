#ifndef PLAYER_H
#define PLAYER_H

#include "npc.hpp"
namespace sq {
class Player : public Npc {
public:
    Player();

    Player(const int tX, const int tY);
};
} // namespace sq

#endif
