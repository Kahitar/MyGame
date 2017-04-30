#include "Button.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"

Button::Button(sf::Vector2f pos, sf::Vector2f Size, std::string text)
    :mMouseOnButton(false),mClicked(false)
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
    mText.setPosition(mPos.x + upSpriteNotHovered->getGlobalBounds().width/2, mPos.y + upSpriteNotHovered->getGlobalBounds().height/2);
}

void Button::setSize(sf::Vector2f Size)
{
    mSize = Size;

    float scaleX = Size.x / TextureWidth;
    float scaleY = Size.y / TextureHeight;

    upSpriteNotHovered->setScale(scaleX, scaleY);
    upSpriteHovered->setScale(scaleX, scaleY);

    mText.setCharacterSize(Size.y*0.5);

    mText.setPosition(mPos.x + upSpriteNotHovered->getGlobalBounds().width*1.4, mPos.y + upSpriteNotHovered->getGlobalBounds().height/2);
}

void Button::setColor(sf::Color color)
{
    upSpriteHovered->setColor(color);
    upSpriteNotHovered->setColor(color);
}

void Button::update()
{

}

void Button::handle(Framework &frmwrk)
{
    std::shared_ptr<sf::Event> event = frmwrk.spMainEvent;

    // Dealing with a resized Window
    sf::Vector2f MouseWorldPos = frmwrk.getTransformedMousePosition();

    if(MouseWorldPos.x > mPos.x
        && MouseWorldPos.y > mPos.y
        && MouseWorldPos.x < mPos.x + mSize.x
        && MouseWorldPos.y < mPos.y + mSize.y)
        mMouseOnButton = true;
    else
        mMouseOnButton = false;

    if(event->type == sf::Event::MouseButtonReleased && mMouseOnButton)
        mClicked = !mClicked;
}

void Button::render(Framework &frmwrk)
{
    std::shared_ptr<sf::RenderWindow> window = frmwrk.spRenderWindow;

    if(mMouseOnButton){
        window->draw(*upSpriteHovered);
    } else {
        window->draw(*upSpriteNotHovered);
    }
    window->draw(mText);
}
