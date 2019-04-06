#include "animation.hpp"
#include <iostream>

sq::animation::animation(const sf::Vector2u ipos, const sf::Vector2u isize, const int icount, const float switcht)
    : img_pos(ipos),
      img_size(isize),
      img_count(icount),
      switch_time(switcht),
      uv_rect(sf::IntRect(ipos.x,ipos.y,isize.x,isize.y))
{
}

void sq::animation::update(float dt)
{
    total_time += dt;
    if (total_time >= switch_time)
    {
        total_time -= switch_time;
        current_img++;
        if (current_img >= img_count)
        {
            current_img = 0;
        }
    }
    if (!stopped)
    {
        uv_rect.left = img_pos.x + current_img * uv_rect.width;
        uv_rect.top = img_pos.y;
    }
}
void sq::animation::update(int img_index)
{
    if (!stopped)
    {
        uv_rect.left = img_pos.x + img_index * uv_rect.width;
        uv_rect.top = img_pos.y;
    }
}
void sq::animation::set_current_img(int index)
{
    current_img = index;
}
void sq::animation::set_img_pos(const sf::Vector2u &pos)
{
    img_pos.x = pos.x;
    img_pos.y = pos.y;
}
bool sq::animation::status() const
{
    return stopped;
}

void sq::animation::set_stopped(bool status)
{
    stopped = status;
}