#include "FlyShipState.hpp"
#include "Framework.hpp"
#include <sstream>

FlyShipState::FlyShipState()
    :NPCShip("assets\\textures\\star_trek_enterprise_botship.png", sf::Vector2f(500,500)),
     playership("assets\\textures\\star_trek_xi_enterprise_v1.png", sf::Vector2f(500,300))
{
    Buttons.addButton(sf::Vector2f(540,50),sf::Vector2f(200,50),"MainMenuButton","Main menu");

    // TODO: (Re)set the view with the actual window size
    playerView.reset(sf::FloatRect(0,0,1280,720));

    Buttons.addTextBox("ActualForceBox");
}

FlyShipState::~FlyShipState()
{
    //dtor
}

void FlyShipState::update(Framework &frmwrk)
{
    int value = ResourceManager::getAcceleratingForce();
    std::stringstream ssvalue;
    ssvalue << value;
    std::string svalue = ssvalue.str();
    Buttons.getTextBox("ActualForceBox").setText(svalue);


    NPCShip.update(frmwrk);
    playership.update(frmwrk);

    playerView.setCenter(playership.getPosition());
    frmwrk.setView(playerView);

    Buttons.update(frmwrk);
}

void FlyShipState::handle(Framework &frmwrk)
{
    Buttons.handle(frmwrk);

    NPCShip.handle(frmwrk);
    playership.handle(frmwrk);

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
    earth.render(frmwrk);
    NPCShip.render(frmwrk);
    playership.render(frmwrk);
    Buttons.render(frmwrk);
}
