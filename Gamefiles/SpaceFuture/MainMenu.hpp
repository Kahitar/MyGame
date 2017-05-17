#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "../Engine/Gamestate.hpp"
#include "../Engine/UIManager.hpp"

class Framework;

class MainMenu : public Gamestate
{
public:
     MainMenu();
    ~MainMenu();

    void update(Framework &frmwrk);
    void handle(Framework &frmwrk);
    void render(Framework &frmwrk);

private:
    UIManager Buttons;

    std::unique_ptr<sf::Texture> upBackTexture;
    std::unique_ptr<sf::Sprite>  upBackSprite;
};

#endif // MAINMENU_HPP
