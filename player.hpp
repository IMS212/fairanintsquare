
#ifndef PLAYER_H
#define PLAYER_H

#include "tiles.hpp"

struct player: public npc{
private:
  
public:
  
  // Current Health
  
  double health = 35.0;
  
  // Max health the player can have
  
  double maxHealth = 35.0;
  
  player(){
    base.setSize(sf::Vector2f(16, 16));
    base.setOrigin(8, 8);
  }
  
  player(int t_x, int t_y){
    //Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
  }
  
};

#endif
