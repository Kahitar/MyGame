#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <string>
#include <memory>

#include "ResourceCache.hpp"
#include "SettingsCache.hpp"

class ResourceManager
{
    public:
         ResourceManager();
        ~ResourceManager();

        //// GETTER ////
        //ResourceCache
        static sf::Texture getTexture(std::string TexturePath);
        //SettingsCache
        static int         getAcceleratingForce();
        static int         getPlayershipMass();


        //// SETTER ////
        //SettingsCache
        static void setAcceleratingForce(int force);
        static void setPlayershipMass(int mass);

    private:
        static ResourceCache mResourceCache;
        static SettingsCache mSettingsCache;
};

#endif // RESOURCEMANAGER_HPP
