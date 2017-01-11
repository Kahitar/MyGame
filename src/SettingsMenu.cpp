#include "SettingsMenu.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"
#include <string>

SettingsMenu::SettingsMenu()
{
    pSliderHeadline    = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(500,300),sf::Vector2f(200,50),"Slider:")));
    upSlider            = std::move(std::unique_ptr<Slider>(new Slider(sf::Vector2f(750,300),sf::Vector2f(200,50))));
    pBackButton         = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(700,500),sf::Vector2f(200,50),"Back")));

    upSlider->setValue(3);
}

SettingsMenu::~SettingsMenu()
{
    //dtor
}

void SettingsMenu::update(Framework &frmwrk)
{
    pBackButton->update();
    upSlider->update(frmwrk);

    int anExampleNumber = upSlider->getSliderValue();
}

void SettingsMenu::handle(Framework &frmwrk)
{
    pBackButton->handle(frmwrk);
    upSlider->handle(frmwrk);

    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed
       && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        if (pBackButton->getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }
}

void SettingsMenu::render(Framework &frmwrk)
{
    pSliderHeadline->render(frmwrk.spRenderWindow);
    pBackButton->render(frmwrk.spRenderWindow);
    upSlider->render(frmwrk);
}
