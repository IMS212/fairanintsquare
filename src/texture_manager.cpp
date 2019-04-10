#include "texture_manager.hpp"
#include <iostream>
#include <memory>

namespace sq {

TextureManager::TextureManager()
    : textures()
{
}

std::size_t TextureManager::size() const
{
    return textures.size();
}

void TextureManager::addTexture(const std::string&& textureName, const std::string&& textureLocation)
{
    if (textures.find(textureName) != textures.end()) {
        return;
    }
    auto newTexture = std::make_unique<sf::Texture>();
    if (!newTexture->loadFromFile(textureLocation)) {
        throw ResourceNotFound(ResourceType::TEXTURE, textureLocation);
    }
    auto txtData = std::make_unique<TextureData>(std::move(newTexture), textureLocation);
    textures[textureName] = std::move(txtData);
}

bool TextureManager::isTextureLoaded(const std::string& textureName) const
{
    return textures.find(textureName) != textures.end();
}

const sf::Texture& TextureManager::getTexture(const std::string&& textureName) const
{
    if (!isTextureLoaded(textureName)) {
        throw ResourceNotFound(ResourceType::TEXTURE, textureName);
    }
    return *(textures.at(textureName)->texture);
}

void TextureManager::removeTexture(const std::string&& textureName)
{
    if (textures.find(textureName) != textures.end()) {
        textures.erase(textureName);
    }
}
}