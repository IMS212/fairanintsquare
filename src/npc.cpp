#include "npc.hpp"
#include <string>
namespace sq {

void Npc::up()
{
    movement.y -= speed + (runningSpeed * running + 1);
    if (movement.y < -maxSpeed) {
        movement.y = -maxSpeed;
    }
    base.setTextureRect(sf::IntRect(17 + 16, 0, 16, 16));
}

void Npc::down()
{
    movement.y += speed + (runningSpeed * running + 1);
    if (movement.y > maxSpeed) {
        movement.y = maxSpeed;
    }
    base.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

void Npc::left()
{
    movement.x -= speed + (runningSpeed * running + 1);
    if (movement.x < -maxSpeed) {
        movement.x = -maxSpeed;
    }
    base.setTextureRect(sf::IntRect(17, 0, 16, 16));
    scale(1, 1);
}

void Npc::right()
{
    movement.x += speed + (runningSpeed * running + 1);
    if (movement.x > maxSpeed) {
        movement.x = maxSpeed;
    }
    base.setTextureRect(sf::IntRect(17, 0, 16, 16));
    scale(-1, 1);
}

void Npc::stop()
{
    movement.x = 0;
    movement.y = 0;
}

// Scaling is only ever used to flip the texture
void Npc::scale(const int tX, const int tY)
{
    base.setScale(tX, tY);
}

Npc::Npc()
    : name("")
{
    base.setSize(sf::Vector2f(16, 16));
    // Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
}

Npc::Npc(const int tX, const int tY)
    : name()
{
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(tX, tY));
    // Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
}

Npc::Npc(const int tX, const int tY, const std::string&& input)
    : name(input)
{
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(tX, tY));
    // Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
}

Npc::Npc(const std::string&& input)
    : name(input)
{
    base.setSize(sf::Vector2f(16, 16));
    base.setOrigin(8, 8);
}

Npc::~Npc() {}

unsigned int Npc::getSpeed() const { return speed; }
unsigned int Npc::getRunningSpeed() const { return runningSpeed; }

void Npc::setSpeed(const unsigned int input) { speed = input; }
void Npc::setName(const std::string&& input) { name = input; }
void Npc::setRunningSpeed(const unsigned int input) { runningSpeed = input; }
}