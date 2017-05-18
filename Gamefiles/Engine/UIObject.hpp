#ifndef UIObject_HPP
#define UIObject_HPP

#include <SFML/Graphics.hpp>

class Framework;

class UIObject
{
    public:
                     UIObject();
        virtual     ~UIObject() {} ;

        virtual void update(Framework &frmwrk) = 0;
        virtual void handle(Framework &frmwrk) = 0;
        virtual void render(Framework &frmwrk) = 0;

        ///////////Setter///////////
        virtual void setScale(float x, float y) = 0;
        virtual void setPosition(sf::Vector2f pos) = 0;
        virtual void setSize(sf::Vector2f size) = 0;

        ///////////Getter///////////
        virtual sf::Vector2f getPosition()  {return mPos;};
        virtual sf::Vector2f getSize()      {return mSize;};
        virtual bool getMouseOnObject()     {return mMouseOnObject;};

    protected:
        sf::Vector2f    mSize;
        sf::Vector2f    mPos;

        bool            mMouseOnObject;
        bool            mClicked;
};

#endif // UIObject_HPP
