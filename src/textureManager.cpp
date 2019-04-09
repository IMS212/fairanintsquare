#include "textureManager.hpp"
#include <iostream>
#include <memory>

sq::textureManager::textureManager() : textures(){}

std::size_t sq::textureManager::size() const {
  return textures.size();
}

void sq::textureManager::addTexture(const std::string &&textureName, const std::string &&textureLocation){
  if (textures.find(textureName) != textures.end()){
	return;
  }
  auto newTexture = std::make_unique<sf::Texture>();
  if (!newTexture->loadFromFile(textureLocation)){
	throw resourceNotFound(sq::resourceType::TEXTURE, textureLocation);
  }
  auto txtData = std::make_unique<sq::textureData>(std::move(newTexture), textureLocation);
  textures[textureName] = std::move(txtData);
}

bool sq::textureManager::isTextureLoaded(const std::string &textureName) const {
  return textures.find(textureName) != textures.end();
}

sf::Texture &sq::textureManager::getTexture(const std::string &&textureName) const {
  if (!isTextureLoaded(textureName)){
	throw resourceNotFound(resourceType::TEXTURE, textureName);
  }
  return *(textures.at(textureName)->texture);
}

void sq::textureManager::removeTexture(const std::string &&textureName){
  if (textures.find(textureName) != textures.end()){
	textures.erase(textureName);
  }
}
