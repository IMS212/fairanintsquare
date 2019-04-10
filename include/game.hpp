/**
 * @file game.hpp
 * @author Gnik Droy
 * @brief File containing functions/classes for managing SFML textures.
 *
 */
#pragma once

#include "texture_manager.hpp"
#include <SFML/Graphics.hpp>

namespace sq {

/**
 * @class Game
 * @brief Class that manages the game for now.
 */
class Game {
    /** The game window*/
    sf::RenderWindow window;
    /** The game's TextureManager*/
    TextureManager textureManager;

public:
    /**
     * @brief Set's up the game
     * @param config dummy config variable
     */
    Game(bool config);

    /**
     * @brief Start the game loop.
     */
    void start();
};
}