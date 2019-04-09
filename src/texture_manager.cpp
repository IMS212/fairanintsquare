#include "texture_manager.hpp"
#include <iostream>
#include <memory>

sq::texture_manager::texture_manager() : textures()
{
}

std::size_t sq::texture_manager::size() const
{
    return textures.size();
}

void sq::texture_manager::add_texture(const std::string &texture_name, const std::string &texture_location)
{
    if (textures.find(texture_name) != textures.end())
        return;
    auto new_texture = std::make_unique<sf::Texture>();
    if (!new_texture->loadFromFile(texture_location))
        throw resource_not_found(sq::resource_type::TEXTURE, texture_location);
    auto txt_data = std::make_unique<sq::texture_data>(std::move(new_texture), texture_location);
    textures[texture_name] = std::move(txt_data);
}

bool sq::texture_manager::is_texture_loaded(const std::string &texture_name) const
{
    return textures.find(texture_name) != textures.end();
}

sf::Texture &sq::texture_manager::get_texture(const std::string &texture_name) const
{
    if (!is_texture_loaded(texture_name))
        throw resource_not_found(resource_type::TEXTURE, texture_name);
    return *(textures.at(texture_name)->texture);
}

void sq::texture_manager::remove_texture(const std::string &texture_name)
{
    if (textures.find(texture_name) != textures.end())
        textures.erase(texture_name);
}