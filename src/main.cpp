#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    bool config{ false };
    sq::Game game(config);
    game.start();
}