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
    return mSettingsCache.getAcceleratingForce();
}

int ResourceManager::getPlayershipMass()
{
	return mSettingsCache.getPlayershipMass();
}

void ResourceManager::setAcceleratingForce(int force)
{
    mSettingsCache.setAcceleratingForce(force);
}

void ResourceManager::setPlayershipMass(int mass)
{
	mSettingsCache.setPlayershipMass(mass);
}