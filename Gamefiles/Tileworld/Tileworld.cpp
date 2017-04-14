#include "Tileworld.hpp"
#include "Framework.hpp"

Tileworld::Tileworld()
{
    mTilesetTexture = ResourceManager::getTexture("assets\\textures\\tilesets\\Set1.png");
    mTilesetSprite.setTexture(mTilesetTexture);
    mWorldSize = sf::Vector2i(10,10);

    //TODO: Seperate Tilemap into different header, add a function in Tileworld to load different maps.
    int array1[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
        1, 1, 2, 2, 2, 2, 1, 1, 1, 1,
        1, 1, 2, 2, 2, 2, 2, 2, 1, 1,
        1, 2, 2, 2, 1, 2, 2, 2, 2, 2,
        2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    for(int i = 0;i<10*10;i++)
    {
        mTilemap[i] = array1[i];
    }
}

Tileworld::~Tileworld()
{
    //dtor
}

void Tileworld::update(Framework &frmwrk)
{

}

void Tileworld::handle(Framework &frmwrk)
{

}

void Tileworld::render(Framework &frmwrk)
{
    drawTiles(frmwrk);
}

void Tileworld::setTileset(std::string texturepath)
{
    mTilesetTexture = ResourceManager::getTexture(texturepath);
}

void Tileworld::setWorldSize(sf::Vector2i WorldSize)
{
    mWorldSize = WorldSize;
}

// TODO: Write a function to control where the map is drawn (position) instead of starting at (x,y) = (0,0)
void Tileworld::drawTiles(Framework &frmwrk)
{
    for(int y = 0;y < mWorldSize.y; ++y){
        for(int x = 0;x < mWorldSize.x; ++x)
        {
            int tilecount = x + y*mWorldSize.x;

            mTilesetSprite.setPosition(x * 50.f, y * 50.f);
            mTilesetSprite.setTextureRect(sf::IntRect(mTilemap[tilecount] * 50, 0, 50, 50));
            frmwrk.spRenderWindow->draw(mTilesetSprite);
        }
    }
}
