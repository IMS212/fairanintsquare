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
class animation
{
private:
  /** The position of sprite in the spritesheet.*/
  sf::Vector2u img_pos;
  /** The size of the image in the spritesheet.*/
  sf::Vector2u img_size;
  /** The number of frames in the animation.*/
  int img_count;
  /** The time taken to switch frames.*/
  float switch_time;
  /** The total time since last complete animation.*/
  float total_time = 0.0f;
  /** The index of the current frame.*/
  int current_img = 0;
  /** Flag that controls if the animation has stopped*/
  bool stopped = false;
  
public:
  /** The part of texture the current frame should display*/
  sf::IntRect uv_rect;

  /** 
   * @brief Constructor for the animation class
   * @param img_pos The position of sprite in the spritesheet
   * @param img_size The size of the image in the spritesheet. (Each frame has same size)
   * @param img_count The number of frames in the animation
   * @param switcht The time to switch frames
  */
  animation(const sf::Vector2u img_pos, const sf::Vector2u img_size, const int img_count, const float switcht);
  
  /**
   * @brief Updates the uv_rect to match the image for current frame.
   * @param dt Time passed since last frame. 
   */
  void update(float dt);

  /**
   * @brief Sets the image position in the spritesheet.
   * @param pos The position of the image in the spritesheet.
   */
  void set_img_pos(const sf::Vector2u &pos);

  /**
   * @brief Sets the current frame.
   * @param index The index of the frame in the spritesheet.
   */
  void set_current_img(int index);

  /**
   * @brief Update the current frame image to the one supplied.
   * @param img_index The index of the image.
   */
  void update(int img_index);

  /**
   * @brief Sets if the scene should be animated or not.
   * @param status Set to true if animation is to stop.
   */
  void set_stopped(bool status);

  /**
   * @brief Returns if the image is being animated.
   * @returns true if image is being animated.
   */
  bool status() const;
};
}