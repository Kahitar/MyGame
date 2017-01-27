#include "MainMenu.hpp"
#include "Framework.hpp"
#include "ButtonManager.hpp"

MainMenu::MainMenu()
{
    Buttons.addButton(sf::Vector2f(540,300),sf::Vector2f(200,50),"NewGameButton","New Game");
    Buttons.addButton(sf::Vector2f(540,400),sf::Vector2f(200,50),"SettingsButton","Settings");
    Buttons.addButton(sf::Vector2f(540,500),sf::Vector2f(200,50),"ExitButton","Exit Game");

    upBackTexture   = std::move(std::unique_ptr<sf::Texture>(new sf::Texture));
    upBackSprite    = std::move(std::unique_ptr<sf::Sprite>(new sf::Sprite));

    *upBackTexture = ResourceManager::getTexture("assets\\textures\\pillarsofcreation.png");
    upBackSprite->setTexture(*upBackTexture);
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(Framework &frmwrk)
{
    Buttons.update(frmwrk);
}

void MainMenu::handle(Framework &frmwrk)
{
    Buttons.handle(frmwrk);

    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        if(Buttons.getButton("NewGameButton").getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::PLAY);
        } else if (Buttons.getButton("SettingsButton").getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::SETTINGS);
        } else if (Buttons.getButton("ExitButton").getMouseOnButton()){
            frmwrk.quit();
        }
    }
}

void MainMenu::render(Framework &frmwrk)
{

    frmwrk.spRenderWindow->draw(*upBackSprite);     //Main Menu Background
    Buttons.render(frmwrk);
}
