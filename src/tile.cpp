#include "tile.hpp"

namespace sq{
int Tile::getPosX() const
{
    return base.getPosition().x;
}

int Tile::getPosY() const
{
    return base.getPosition().y;
}

void Tile::show(sf::RenderWindow& window)
{
    window.draw(base);
}

void Tile::setTexture(const sf::Texture& ptexture, const int posX, const int posY, const int sizeX, const int sizeY)
{
    base.setTexture(&ptexture);
    base.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
}

void Tile::setColour(const unsigned int r, const unsigned int g, const unsigned int b)
{
    base.setFillColor(sf::Color(r, g, b));
}

void Tile::setColour(const sf::Color& colour)
{
    base.setFillColor(colour);
}

void Tile::setPosition(const int t_x, const int t_y)
{
    base.setPosition(sf::Vector2f(t_x, t_y));
}

void Tile::move(const int t_x, const int t_y)
{
    base.move(sf::Vector2f(t_x, t_y));
}

void Tile::move(const sf::Vector2f& movement)
{
    base.move(movement);
}

Tile::Tile()
    : base(sf::Vector2f(16, 16))
{
}

Tile::Tile(const unsigned int t_x, const unsigned int t_y)
    : base(sf::Vector2f(16, 16))
{
    base.move(sf::Vector2f(t_x, t_y));
}

Tile::~Tile() {}
}