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

int ResourceManager::getAcceleratingForce()
{
    return mSettingsCache.getForceToAccelerate();
}

void ResourceManager::setAcceleratingForce(int force)
{
    mSettingsCache.setForceToAccelerate(force);
}
