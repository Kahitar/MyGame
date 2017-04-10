#include "ResourceManager.hpp"

ResourceCache ResourceManager::mResourceCache;
SettingsCache ResourceManager::mSettingsCache;

ResourceManager::ResourceManager()
{
    //ctor
}

ResourceManager::~ResourceManager()
{
    //dtor
}

sf::Texture ResourceManager::getTexture(std::string TexturePath)
{
    return mResourceCache.getTexture(TexturePath);
}
