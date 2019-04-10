#ifndef NPC_H
#define NPC_H

#include "tile.hpp"
namespace sq {
class Npc : public Tile {

private:
    std::string name;
    unsigned int speed = 1;
    int maxSpeed = 6;
    unsigned int runningSpeed = 6;

public:
    sf::Vector2f movement = { 0, 0 };
    bool running = false;

    unsigned int getSpeed() const;
    void setSpeed(const unsigned int input);
    unsigned int getRunningSpeed() const;
    void setRunningSpeed(const unsigned int input);
    void setName(const std::string&& input);
    virtual void up();
    virtual void down();
    virtual void left();
    void right();
    void stop();
    //Scaling is only ever used to flip the texture
    void scale(const int tX, const int tY);
    Npc();
    ~Npc();
    Npc(const int tX, const int tY);
    Npc(const int tX, const int tY, const std::string&& input);
    Npc(const std::string&& input);
};
} // namespace sq
#endif
