#ifndef TILEWORLD_HPP
#define TILEWORLD_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

class Framework;

class Tileworld
{
    public:
        Tileworld();
        ~Tileworld();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

        void setTileset(std::string texturepath);
        void setWorldSize(sf::Vector2i WorldSize);

    private:
        void drawTiles(Framework &frmwrk);

        sf::Vector2i mWorldSize;

        sf::Texture mTilesetTexture;
        sf::Sprite  mTilesetSprite;

        int mTilemap[10*10];

};

#endif // TILEWORLD_HPP
