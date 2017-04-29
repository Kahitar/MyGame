#include "FlyShipState.hpp"
#include "Framework.hpp"

FlyShipState::FlyShipState()
    :ship(100),ship2(130)
{
   Buttons.addButton(sf::Vector2f(540,300),sf::Vector2f(200,50),"MainMenuButton","Main menu");
}

FlyShipState::~FlyShipState()
{
    //dtor
}

void FlyShipState::update(Framework &frmwrk)
{
    float force1 = 1000000;
    ship.update(frmwrk,force1);

    float force2 = 0;
    ship2.update(frmwrk,force2);

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
}

void FlyShipState::render(Framework &frmwrk)
{
    ship.render(frmwrk);
    ship2.render(frmwrk);
    Buttons.render(frmwrk);
}
