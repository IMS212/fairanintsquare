/**
 * @file Animation.hpp
 * @author Gnik Droy
 * @brief File containing functions/classes that handle simple spritesheet
 * animations.
 *
 */
#pragma once
#include <SFML/Graphics.hpp>

namespace sq {
/** This holds the information of a frame */
struct AnimationFrame {
    /** The part of texture the current frame should display*/
    sf::IntRect uvRect;
    /** The duration for which the current frame should be displayed*/
    double duration;
};

/**
 * @class Animation
 * Class containing functions/classes that handle simple spritesheet animations.
 */
class Animation {
    /** The sprite to apply the uv_rect to. */
    sf::Sprite& target;
    /** Whether the animation loops or not. */
    bool loop;
    /** The frames to be displayed for the animation. **/
    std::vector<AnimationFrame> frames;
    /** The current frame */
    std::size_t currentFrame = 0u;
    /** The total time for the animation */
    double totalTime = 0.;
    /** The total time since last frame.*/
    double progress = 0.;
    /** Flag that controls if the animation has stopped*/
    bool stopped = false;

public:
    /**
   * @brief Constructor for the animation class
   * @param target The sf::sprite object to animate.
   * @param loop Whether to run the animation in loop or not.
   */
    Animation(sf::Sprite& target, bool loop = true);

    /**
   * @brief Constructor for the animation class (move the frames)
   * @param target The sf::sprite object to animate.
   * @param allFrames The frames for the animation.
   * @param loop Whether to run the animation in loop or not.
   */
    Animation(sf::Sprite& target, std::vector<AnimationFrame>&& allFrames,
        bool loop = true);

    /**
   * @brief Updates the uvRect to match the current frame.
   * @param dt Time passed since last frame.
   */
    void update(double dt);

    /**
   * @brief Add a new frame to the animation.
   * Note: We may need to overload with a function that takes multiple frames.
   * But for now only this will be implemented.
   * @param frame The new frame to add.
   */
    void addFrame(const AnimationFrame&& frame);

    /**
   * @brief Add a new frame to the animation.
   * @param frame The new frame to add.
   * @param index The index at which to insert. 
   */
    void addFrame(const AnimationFrame&& frame, std::size_t index);

    /**
   * @brief Sets the current frame.
   * @param index The index of the frame in the.
   */
    void setCurrentFrame(std::size_t index);

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

    /**
   * @brief Returns if the animation loops or not.
   * @returns true if animation loops
   */
    bool isLooping() const;

    /**
   * @brief Sets if the animation is to loop
   * @param loop_status true if animation is to loop.
   */
    void setLoop(bool loop_status);

    /**
   * @brief Gets the animation frames.
   */
    const std::vector<AnimationFrame>& getFrames() const;

    /**
   * @brief Sets the progress of the current frame.
   * @param p The progress since last frame
   */
    void setProgress(double p) { progress = p; }
};
} // namespace sq