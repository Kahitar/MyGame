#include "MainMenu.hpp"
#include "Framework.hpp"


MainMenu::MainMenu()
{
    pNewGameButton = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(540,300),sf::Vector2f(200,50),"New Game")));
    pSettingsButton = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(540,400),sf::Vector2f(200,50),"Settings")));
    pExitButton = std::move(std::unique_ptr<Button>(new Button(sf::Vector2f(540,500),sf::Vector2f(200,50),"Exit Game")));
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(Framework &frmwrk)
{
    pNewGameButton->update();
    pSettingsButton->update();
    pExitButton->update();
}

void MainMenu::handle(Framework &frmwrk)
{
    pNewGameButton->handle(frmwrk.spMainEvent);
    pSettingsButton->handle(frmwrk.spMainEvent);
    pExitButton->handle(frmwrk.spMainEvent);

    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left){
        if(pNewGameButton->getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::PLAY);
        } else if (pSettingsButton->getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::SETTINGS);
        } else if (pExitButton->getMouseOnButton()){
            frmwrk.quit();
        }
    }
}

void MainMenu::render(Framework &frmwrk)
{
    pNewGameButton->render(frmwrk.spRenderWindow);
    pSettingsButton->render(frmwrk.spRenderWindow);
    pExitButton->render(frmwrk.spRenderWindow);
}
