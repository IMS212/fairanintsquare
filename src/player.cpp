#include "player.hpp"

sq::player::player(){
    base.setSize(sf::Vector2f(16, 16));
    base.setOrigin(8, 8);
}

sq::player::player(const int tX, const int tY){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(tX, tY));
    base.setOrigin(8, 8);
}
