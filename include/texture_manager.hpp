/**
 * @file texture_manager.hpp
 * @author Gnik Droy
 * @brief File containing functions/classes for managing SFML textures.
 *
 */
#pragma once

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "resource_exception.hpp"

namespace sq
{

/** @struct TextureData
 *  @brief This container for holding data related to the game textures.
 */
struct texture_data
{
  /** Pointer to the texture object.*/
  std::unique_ptr<sf::Texture> texture;
  /** The path to the texture file.*/
  std::string texture_location;
  
  /**
   * @brief Constructs the texture_data object.
   * @param txt Pointer to the texture object.
   * @param txt_location The path to the texture file. 
   */
  texture_data(std::unique_ptr<sf::Texture> txt, const std::string txt_location) : texture(std::move(txt)),
                                                                                  texture_location(txt_location)
  {
  }

  /**
   * @brief Constructs a empty texture_data object.
   * texture pointer is set to null and texture path is a empty string.
   */
  texture_data() : texture(nullptr),
                  texture_location("")
  {
  }
};

/**
 * @class texture_manager
 * @brief Class for managing sf::Texture objects.
 */
class texture_manager
{
private:

  /** Container that stores the name/identifier and texture_data mappings.*/
  std::unordered_map<std::string, std::unique_ptr<texture_data>> textures;

public:

  /**
   * @brief Constructs the texture_manager object.
   */
  texture_manager();

  /**
    * @brief Returns the number of textures currently held by the game.
    * @return Size of the underlying unordered_map
  */
  std::size_t size() const;

  /**
    * @brief Add a new texture to be managed by the texture manager.
    * Checks if a texture with the same name/identifier is present. If present, it doesn't load any new texture.
    * i.e textures previously added are reused.
    * 
    * Throws resource not found exception if the texture is not present.
    * 
    * @throws sq::resource_not_found
    * @param texture_name The identifier for the texture.
    * @param texture_location The file path for the texture.
  */
  void add_texture(const std::string &texture_name, const std::string &texture_location);

  /**
    * @brief Checks if a texture with the same name/identifier is present.
    * @param texture_name The identifier for the texture.
    * @return true if texture is present
  */
  bool is_texture_loaded(const std::string &texture_name) const;

  /**
    * @brief Gets the texture with the given name/identifier.
    * Throws resource not found exception if the texture is not loaded.
    * 
    * @throws sq::resource_not_found
    * @param texture_name The identifier for the texture.
    * @return The sf::Texture object.
  */
  sf::Texture &get_texture(const std::string &texture_name) const;

  /**
    * @brief Removes texture with the given name/identifier.
    * Note: There is no real use to use this function since texture_manager is a proper RAII
    * class. You have to understand that using this may introduce bugs in you program since
    * the underlying map uses unique_ptr instead of shared_ptr (deliberately for performance).
    * Therefore, you can remove a texture that may be in use in future (using freed resource).
    * Only use if you know the consequences. It is perfectly safe otherwise.
    *  
    * @param texture_name The identifier for the texture.
  */
  void remove_texture(const std::string &texture_name);
};

} // namespace sq