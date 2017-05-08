#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include "../Engine/Gamestate.hpp"
#include "../Engine/UIElement.hpp"
#include "../Engine/SettingsCache.hpp"

class Framework;

class SettingsMenu : public Gamestate
{
    public:
         SettingsMenu();
        ~SettingsMenu();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        UIElement uielements;
};

#endif // SETTINGSMENU_HPP
