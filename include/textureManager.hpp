/**
 * @file textureManager.hpp
 * @author Gnik Droy
 * @brief File containing functions/classes for managing SFML textures.
 *
 */
#pragma once

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "resourceException.hpp"

namespace sq
{

/** @struct TextureData
 *  @brief This container for holding data related to the game textures.
 */
struct textureData{
  /** Pointer to the texture object.*/
  std::unique_ptr<sf::Texture> texture;
  /** The path to the texture file.*/
  std::string textureLocation;

  /**
   * @brief Constructs the textureData object.
   * @param txt Pointer to the texture object.
   * @param txtLocation The path to the texture file.
   */
  textureData(std::unique_ptr<sf::Texture> txt, const std::string txtLocation) : texture(std::move(txt)),
                                                                                  textureLocation(txtLocation)
  {}

  /**
   * @brief Constructs a empty textureData object.
   * texture pointer is set to null and texture path is a empty string.
   */
  textureData() : texture(nullptr),
                  textureLocation("")
  {}
};

/**
 * @class textureManager
 * @brief Class for managing sf::Texture objects.
 */
class textureManager{
private:

  /** Container that stores the name/identifier and textureData mappings.*/
  std::unordered_map<std::string, std::unique_ptr<textureData>> textures;

public:

  /**
   * @brief Constructs the textureManager object.
   */
  textureManager();

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
    * @throws sq::resourceNotFound
    * @param textureName The identifier for the texture.
    * @param textureLocation The file path for the texture.
  */
  void addTexture(const std::string &&textureName, const std::string &&textureLocation);

  /**
    * @brief Checks if a texture with the same name/identifier is present.
    * @param textureName The identifier for the texture.
    * @return true if texture is present
  */
  bool isTextureLoaded(const std::string &textureName) const;

  /**
    * @brief Gets the texture with the given name/identifier.
    * Throws resource not found exception if the texture is not loaded.
    *
    * @throws sq::resourceNotFound
    * @param textureName The identifier for the texture.
    * @return The sf::Texture object.
  */
  sf::Texture &getTexture(const std::string &&textureName) const;

  /**
    * @brief Removes texture with the given name/identifier.
    * Note: There is no real use to use this function since textureManager is a proper RAII
    * class. You have to understand that using this may introduce bugs in you program since
    * the underlying map uses unique_ptr instead of shared_ptr (deliberately for performance).
    * Therefore, you can remove a texture that may be in use in future (using freed resource).
    * Only use if you know the consequences. It is perfectly safe otherwise.
    *
    * @param textureName The identifier for the texture.
  */
  void removeTexture(const std::string &&textureName);
};

} // namespace sq
