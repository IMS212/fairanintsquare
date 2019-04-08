/**
 * @file animation.hpp
 * @author Gnik Droy
 * @brief File containing functions/classes that handle simple spritesheet animations.
 *
 */
#pragma once
#include <SFML/Graphics.hpp>

namespace sq
{

/**
 * @class animation
 * Class containing functions/classes that handle simple spritesheet animations.
 */
class animation{
private:
  /** The position of sprite in the spritesheet.*/
  sf::Vector2u imagePosition;
  /** The size of the image in the spritesheet.*/
  sf::Vector2u imageSize;
  /** The number of frames in the animation.*/
  unsigned int imageCount;
  /** The time taken to switch frames.*/
  double switchTime;
  /** The total time since last complete animation.*/
  double totalTime = 0.0;
  /** The index of the current frame.*/
  unsigned int currentImage = 0;
  /** Flag that controls if the animation has stopped*/
  bool stopped = false;

public:
  /** The part of texture the current frame should display*/
  sf::IntRect uvRect;

  /**
   * @brief Constructor for the animation class
   * @param imagePosition The position of sprite in the spritesheet
   * @param imageSize The size of the image in the spritesheet. (Each frame has same size)
   * @param imageCount The number of frames in the animation
   * @param switcht The time to switch frames
   */
  animation(const sf::Vector2u &imagePosition, const sf::Vector2u &imageSize, const unsigned int imageCount, const double switcht);

  /**
   * @brief Updates the uvRect to match the image for current frame.
   * @param dt Time passed since last frame.
   */
  void update(const double dt);

  /**
   * @brief Update the current frame image to the one supplied.
   * @param imageIndex The index of the image.
   */
  void update(const unsigned int imageIndex);

  /**
   * @brief Sets the image position in the spritesheet.
   * @param pos The position of the image in the spritesheet.
   */
  void setImagePosition(const sf::Vector2u &pos);

  /**
   * @brief Sets the current frame.
   * @param index The index of the frame in the spritesheet.
   */
  void setCurrentImage(const unsigned int index);

  /**
   * @brief Sets if the scene should be animated or not.
   * @param status Set to true if animation is to stop.
   */
  void setStatus(const bool status);

  /**
   * @brief Returns if the image is being animated.
   * @returns true if image is being animated.
   */
  bool status() const;
};
}
