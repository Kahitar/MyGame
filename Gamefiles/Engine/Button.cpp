#include "Button.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"

Button::Button(sf::Vector2f pos, sf::Vector2f Size, std::string text)
{
    this->setText(text);

    mFont.loadFromFile("assets\\fonts\\PAPYRUS.TTF");
    mText.setFont(mFont);
    mText.setFillColor(sf::Color::Black);
    mText.setStyle(sf::Text::Bold);

    upTexture            = std::shared_ptr<sf::Texture>(new sf::Texture);
    upSpriteNotHovered   = std::shared_ptr<sf::Sprite> (new sf::Sprite);
    upSpriteHovered      = std::shared_ptr<sf::Sprite> (new sf::Sprite);

    sf::Image subImage;
    subImage.loadFromFile("assets\\textures\\Button.png"); //TODO: Load from resource Manager
    subImage.createMaskFromColor(sf::Color::White);

    upTexture->loadFromImage(subImage);
    TextureHeight = 50.0;
    TextureWidth = 200.0;

    upSpriteHovered->setTexture(*upTexture);
    upSpriteHovered->setTextureRect(sf::IntRect(0, 0, TextureWidth, TextureHeight));
    upSpriteNotHovered->setTexture(*upTexture);
    upSpriteNotHovered->setTextureRect(sf::IntRect(0, TextureHeight, TextureWidth, TextureHeight));

    setSize(Size);
    setPosition(pos);
}

Button::~Button()
{

}

void Button::setText(std::string text)
{
    mText.setString(text);
}

void Button::setPosition(sf::Vector2f pos)
{
    mPos = pos;

    upSpriteNotHovered->setPosition(mPos);
    upSpriteHovered->setPosition(mPos);

    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPos.x + mSize.x/2, mPos.y + mSize.y/2);
}

void Button::setSize(sf::Vector2f size)
{
    mSize = size;

    float scaleX = size.x / TextureWidth;
    float scaleY = size.y / TextureHeight;

    upSpriteNotHovered->setScale(scaleX, scaleY);
    upSpriteHovered->setScale(scaleX, scaleY);

    mText.setCharacterSize(size.y*0.5);

    mText.setPosition(mPos.x + upSpriteNotHovered->getGlobalBounds().width*1.4, mPos.y + upSpriteNotHovered->getGlobalBounds().height/2);
}

void Button::setScale(float x, float y)
{

}

void Button::setColor(sf::Color color)
{
    upSpriteHovered->setColor(color);
    upSpriteNotHovered->setColor(color);
}

void Button::update(Framework &frmwrk)
{

}

void Button::handle(Framework &frmwrk)
{
    // Dealing with a resized Window
    sf::Vector2f MouseWorldPos = frmwrk.getTransformedMousePosition();

    if(MouseWorldPos.x > mPos.x
        && MouseWorldPos.y > mPos.y
        && MouseWorldPos.x < mPos.x + mSize.x
        && MouseWorldPos.y < mPos.y + mSize.y)
        mMouseOnObject = true;
    else
        mMouseOnObject = false;

    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonReleased && mMouseOnObject)
        mClicked = !mClicked;
}

void Button::render(Framework &frmwrk)
{
    if(mMouseOnObject){
        frmwrk.spRenderWindow->draw(*upSpriteHovered);
    } else {
        frmwrk.spRenderWindow->draw(*upSpriteNotHovered);
    }
    frmwrk.spRenderWindow->draw(mText);
}