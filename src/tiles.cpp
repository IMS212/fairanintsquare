#include "tiles.hpp"

int sq::tile::get_pos_x() const
{
    return base.getPosition().x;
}

int sq::tile::get_pos_y() const
{
    return base.getPosition().y;
}

void sq::tile::show(sf::RenderWindow &window)
{
    window.draw(base);
}

void sq::tile::set_texture(const std::string &&name, const int posX, const int posY, const int sizeX, const int sizeY)
{
    texture.loadFromFile(name);
    base.setTexture(&texture);
    base.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
}

void sq::tile::set_texture(const sf::Texture ptexture, const int posX, const int posY, const int sizeX, const int sizeY)
{
    base.setTexture(&ptexture);
    base.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
}

void sq::tile::set_colour(const unsigned int r, const unsigned int g, const unsigned int b)
{
    base.setFillColor(sf::Color(r, g, b));
}

void sq::tile::set_colour(const sf::Color &colour)
{
    base.setFillColor(colour);
}

void sq::tile::set_position(int t_x, int t_y)
{
    base.setPosition(sf::Vector2f(t_x, t_y));
}

void sq::tile::move(int t_x, int t_y)
{
    base.move(sf::Vector2f(t_x, t_y));
}

void sq::tile::move(sf::Vector2f &movement)
{
    base.move(movement);
}

sq::tile::tile() : base(sf::Vector2f(16, 16))
{
}

sq::tile::tile(unsigned int t_x, unsigned int t_y) : base(sf::Vector2f(16, 16))
{
    base.move(sf::Vector2f(t_x, t_y));
}

sq::tile::~tile() {}