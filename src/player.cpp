#include "player.hpp"

namespace sq {
Player::Player()
{
    base.setSize(sf::Vector2f(16, 16));
    base.setOrigin(8, 8);
}

Player::Player(const int tX, const int tY)
{
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(tX, tY));
    base.setOrigin(8, 8);
}
}