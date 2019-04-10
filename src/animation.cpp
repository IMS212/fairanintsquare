#include "animation.hpp"
#include <iostream>
namespace sq {
Animation::Animation(sf::Sprite& aniTarget, bool willLoop)
    : target(aniTarget)
    , loop(willLoop)
    , frames()
{
}

Animation::Animation(sf::Sprite& aniTarget,
    std::vector<AnimationFrame>&& allFrames, bool willLoop)
    : target(aniTarget)
    , loop(willLoop)
    , frames(std::move(allFrames))

{
}

void Animation::update(double dt)
{
    if (stopped)
        return;
    progress += dt;
    while (progress >= frames[currentFrame].duration) {
        progress -= frames[currentFrame].duration;
        if ((currentFrame == frames.size() - 1) && !loop)
            return; // If it's the last frame and loop is disabled return;
        currentFrame = (currentFrame + 1) % frames.size();
        target.setTextureRect(frames[currentFrame].uvRect);
    }
}

void Animation::addFrame(const AnimationFrame&& frame, std::size_t index)
{
    totalTime += frame.duration;
    frames.insert(frames.begin() + index, std::move(frame));
}

void Animation::addFrame(const AnimationFrame&& frame)
{
    totalTime += frame.duration;
    frames.push_back(std::move(frame));
}

void Animation::setCurrentFrame(std::size_t index)
{
    currentFrame = index;
    target.setTextureRect(frames[index].uvRect);
}

bool Animation::status() const { return stopped; }
void Animation::setStatus(bool status) { stopped = status; }

bool Animation::isLooping() const { return loop; }
void Animation::setLoop(bool loopStatus) { loop = loopStatus; }

const std::vector<AnimationFrame>& Animation::getFrames() const
{
    return frames;
}

} // namespace sq
