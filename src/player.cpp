#include "player.hpp"

sq::player::player()
{
    base.setSize(sf::Vector2f(16, 16));
    base.setOrigin(8, 8);
}

sq::player::player(int t_x, int t_y)
{
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
    base.setOrigin(8, 8);
}
