#include "FlyShipState.hpp"
#include "Framework.hpp"

FlyShipState::FlyShipState()
{
   Buttons.addButton(sf::Vector2f(540,50),sf::Vector2f(200,50),"MainMenuButton","Main menu");
}

FlyShipState::~FlyShipState()
{
    //dtor
}

void FlyShipState::update(Framework &frmwrk)
{
    ship.update(frmwrk);
    playership.update(frmwrk);

    Buttons.update(frmwrk);
}

void FlyShipState::handle(Framework &frmwrk)
{
    Buttons.handle(frmwrk);

    // handle buttons
    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        if(Buttons.getButton("MainMenuButton").getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }

    ship.handle(frmwrk);
    playership.handle(frmwrk);
}

void FlyShipState::render(Framework &frmwrk)
{
    ship.render(frmwrk);
    playership.render(frmwrk);
    Buttons.render(frmwrk);
}
