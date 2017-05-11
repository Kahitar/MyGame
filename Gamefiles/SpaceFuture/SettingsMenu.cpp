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
    uielements.getSlider("ForceSlider").setMinMax(1,500000);
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

    uielements.addTextBox("AccelerationTextbox","Resulting Acceleration: ", sf::Vector2f(200,400));
}

SettingsMenu::~SettingsMenu()
{
    //dtor
}

void SettingsMenu::update(Framework &frmwrk)
{
    float Acceleration = (float)ResourceManager::getAcceleratingForce() / (float)ResourceManager::getPlayershipMass();
    std::stringstream ssAcceleration;
    ssAcceleration << Acceleration;
    std::string newText = "Resulting Acceleration: ";
    newText.append(ssAcceleration.str());
    newText.append(" m/s/s");
    uielements.getTextBox("AccelerationTextbox").setText(newText);

    uielements.update(frmwrk);
    ResourceManager::setAcceleratingForce(uielements.getSlider("ForceSlider").getSliderValue());
    ResourceManager::setPlayershipMass(uielements.getSlider("MassSlider").getSliderValue());
}

void SettingsMenu::handle(Framework &frmwrk)
{
    uielements.handle(frmwrk);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        frmwrk.ChangeState(Framework::gameStates::MAINMENU);

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





















