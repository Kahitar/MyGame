#include <string>
#include <sstream>
#include "../Engine/Framework.hpp"
#include "../Engine/ResourceManager.hpp"
#include "SettingsMenu.hpp"

SettingsMenu::SettingsMenu()
{
    uielements.addButton(sf::Vector2f(500,500),sf::Vector2f(200,50),"BackButton","Back");

    uielements.addSlider(sf::Vector2f(500,300),sf::Vector2f(600,50),"ForceSlider","Accelerating Force: ","N");
    uielements.getSlider("ForceSlider").setNumberOfPositions(5000);
    uielements.getSlider("ForceSlider").setMinMax(0,500000);
    if(ResourceManager::getAcceleratingForce())
        uielements.getSlider("ForceSlider").setValue(ResourceManager::getAcceleratingForce());
    else
        uielements.getSlider("ForceSlider").setValue(500);

    uielements.addSlider(sf::Vector2f(500,200), sf::Vector2f(200,50),"MassSlider","Ship Mass: ","kg");
    uielements.getSlider("MassSlider").setMinMax(1,1000);
    if(ResourceManager::getPlayershipMass())
        uielements.getSlider("MassSlider").setValue(ResourceManager::getPlayershipMass());
    else
        uielements.getSlider("MassSlider").setValue(10);
}

SettingsMenu::~SettingsMenu()
{
    //dtor
}

void SettingsMenu::update(Framework &frmwrk)
{
    uielements.update(frmwrk);
    ResourceManager::setAcceleratingForce(uielements.getSlider("ForceSlider").getSliderValue());
    ResourceManager::setPlayershipMass(uielements.getSlider("MassSlider").getSliderValue());
}

void SettingsMenu::handle(Framework &frmwrk)
{
    uielements.handle(frmwrk);

    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed
       && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        if (uielements.getButton("BackButton").getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }
}

void SettingsMenu::render(Framework &frmwrk)
{
    uielements.render(frmwrk);
}





















