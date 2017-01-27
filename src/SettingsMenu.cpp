#include "SettingsMenu.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"
#include <string>

SettingsMenu::SettingsMenu()
{
    Buttons.addButton(sf::Vector2f(500,300),sf::Vector2f(200,50),"SliderHeadline","Slider:");
    Buttons.addButton(sf::Vector2f(700,500),sf::Vector2f(200,50),"BackButton","Back");

    upSlider            = std::move(std::unique_ptr<Slider>(new Slider(sf::Vector2f(750,300),sf::Vector2f(200,50))));
    upSlider->setValue(3);
}

SettingsMenu::~SettingsMenu()
{
    //dtor
}

void SettingsMenu::update(Framework &frmwrk)
{
    Buttons.update(frmwrk);
    upSlider->update(frmwrk);

    int anExampleNumber = upSlider->getSliderValue();
}

void SettingsMenu::handle(Framework &frmwrk)
{
    Buttons.handle(frmwrk);
    upSlider->handle(frmwrk);

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
    upSlider->render(frmwrk);
}
