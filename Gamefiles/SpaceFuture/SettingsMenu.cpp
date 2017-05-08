#include <string>
#include <sstream>
#include "../Engine/Framework.hpp"
#include "../Engine/ResourceManager.hpp"
#include "SettingsMenu.hpp"

SettingsMenu::SettingsMenu()
{
    uielements.addButton(sf::Vector2f(500,500),sf::Vector2f(200,50),"BackButton","Back");

    uielements.addSlider(sf::Vector2f(700,300),sf::Vector2f(200,50),"ForceSlider","Accelerating Force: ");
    uielements.getSlider("ForceSlider").setNumberOfPositions(100);
    uielements.getSlider("ForceSlider").setMinMax(0,10000000); //setMinMax must be BEFORE setValue on Sliders. Otherwise the Value gets changed
    uielements.getSlider("ForceSlider").setValue(ResourceManager::getAcceleratingForce());
}

SettingsMenu::~SettingsMenu()
{
    //dtor
}

void SettingsMenu::update(Framework &frmwrk)
{
    uielements.update(frmwrk);
    ResourceManager::setAcceleratingForce(uielements.getSlider("ForceSlider").getSliderValue());
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
