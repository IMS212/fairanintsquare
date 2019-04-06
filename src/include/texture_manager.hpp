#pragma once

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "resource_exception.hpp"

namespace sq
{

struct TextureData
{
  std::unique_ptr<sf::Texture> texture;
  std::string texture_location;
  TextureData(std::unique_ptr<sf::Texture> txt, const std::string txt_location) : texture(std::move(txt)),
                                                                                  texture_location(txt_location)
  {
  }
  TextureData() : texture(nullptr),
                  texture_location("")
  {
  }
};

class texture_manager
{
private:
  std::unordered_map<std::string, std::unique_ptr<TextureData>> textures;

public:
  texture_manager();
  std::size_t size() const;
  void add_texture(const std::string &texture_name, const std::string &texture_location);
  bool is_texture_loaded(const std::string &texture_name) const;
  sf::Texture &get_texture(const std::string &texture_name) const;
  void remove_texture(const std::string &texture_name);
};

} // namespace sq