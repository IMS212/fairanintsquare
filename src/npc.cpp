#include "npc.hpp"
#include <string>

unsigned int sq::npc::getSpeed() const {
  return speed;
}

void sq::npc::setSpeed(const unsigned int input){
  speed = input;
}

unsigned int sq::npc::getRunningSpeed() const {
  return runningSpeed;
}

void sq::npc::setRunningSpeed(const unsigned int input){
  runningSpeed = input;
}

void sq::npc::setName(const std::string &&input){
  name = input;
}

void sq::npc::up(){
  movement.y -= speed + (runningSpeed * running + 1);
  if (movement.y < -maxSpeed){
    movement.y = -maxSpeed;
  }
  base.setTextureRect(sf::IntRect(17 + 16, 0, 16, 16));
}

void sq::npc::down(){
  movement.y += speed + (runningSpeed * running + 1);
  if (movement.y > maxSpeed){
    movement.y = maxSpeed;
  }
  base.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

void sq::npc::left(){
  movement.x -= speed + (runningSpeed * running + 1);
  if (movement.x < -maxSpeed){
    movement.x = -maxSpeed;
  }
  base.setTextureRect(sf::IntRect(17, 0, 16, 16));
  scale(1, 1);
}

void sq::npc::right(){
  movement.x += speed + (runningSpeed * running + 1);
  if (movement.x > maxSpeed){
    movement.x = maxSpeed;
  }
  base.setTextureRect(sf::IntRect(17, 0, 16, 16));
  scale(-1, 1);
}

void sq::npc::stop(){
  movement.x = 0;
  movement.y = 0;
}

// Scaling is only ever used to flip the texture
void sq::npc::scale(const int tX, const int tY){
  base.setScale(tX, tY);
}

sq::npc::npc() : name(""){
  base.setSize(sf::Vector2f(16, 16));
  // Origin to center to facilitate texture flipping
  base.setOrigin(8, 8);
}

sq::npc::npc(const int tX, const int tY) : name(""){
  base.setSize(sf::Vector2f(16, 16));
  base.move(sf::Vector2f(tX, tY));
  // Origin to center to facilitate texture flipping
  base.setOrigin(8, 8);
}

sq::npc::npc(const int tX, const int tY, const std::string &&input) : name(input){
  base.setSize(sf::Vector2f(16, 16));
  base.move(sf::Vector2f(tX, tY));
  // Origin to center to facilitate texture flipping
  base.setOrigin(8, 8);
}

sq::npc::npc(const std::string &&input) : name(input){
  base.setSize(sf::Vector2f(16, 16));
  base.setOrigin(8, 8);
}

sq::npc::~npc() {}