#include "SettingsMenu.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"
#include <string>

SettingsMenu::SettingsMenu()
    :ForceSliderMultiplicator(1000)
{
    Buttons.addButton(sf::Vector2f(450,300),sf::Vector2f(280,50),"SliderHeadline","Accelerating Force:");
    Buttons.addButton(sf::Vector2f(700,500),sf::Vector2f(200,50),"BackButton","Back");

    Sliders.addSlider(sf::Vector2f(800,300),sf::Vector2f(200,50),"ForceSlider","This is a slider:");
    Sliders.getSlider("ForceSlider").setNumberOfPositions(100);
    Sliders.getSlider("ForceSlider").setValue(ResourceManager::getAcceleratingForce()/ForceSliderMultiplicator);
}

SettingsMenu::~SettingsMenu()
{
    //dtor
}

void SettingsMenu::update(Framework &frmwrk)
{
    Buttons.update(frmwrk);
    Sliders.update(frmwrk);
    ResourceManager::setAcceleratingForce(Sliders.getSlider("ForceSlider").getSliderValue()*ForceSliderMultiplicator);
}

void SettingsMenu::handle(Framework &frmwrk)
{
    Buttons.handle(frmwrk);
    Sliders.handle(frmwrk);

    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed
       && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        if (Buttons.getButton("BackButton").getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }
}

void SettingsMenu::render(Framework &frmwrk)
{
    Buttons.render(frmwrk);
    Sliders.render(frmwrk);
}
