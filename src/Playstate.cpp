#include "Playstate.hpp"
#include "Framework.hpp"

Playstate::Playstate()
{
    upMainMenuButton = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(540,300),sf::Vector2f(200,50),"Main Menu")));

    mRect.setFillColor(sf::Color::Blue);
    mRect.setOutlineThickness(1);
    mRect.setOutlineColor(sf::Color::Black);
    mRect.setPosition(sf::Vector2f(200,200));
    mRect.setSize(sf::Vector2f(100,100));

    texture = ResourceManager::getTexture("assets\\textures\\button.png");
    sprite.setTexture(texture);
}

Playstate::~Playstate()
{
    //dtor
}

void Playstate::update(Framework &frmwrk)
{
    upMainMenuButton->update();
}

void Playstate::handle(Framework &frmwrk)
{
    upMainMenuButton->handle(frmwrk);

    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left){
        if(upMainMenuButton->getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }
}

void Playstate::render(Framework &frmwrk)
{
    upMainMenuButton->render(frmwrk.spRenderWindow);

    frmwrk.spRenderWindow->draw(mRect);
    frmwrk.spRenderWindow->draw(sprite);
}
