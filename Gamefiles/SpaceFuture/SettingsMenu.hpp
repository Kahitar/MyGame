#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include "../Engine/Gamestate.hpp"
#include "../Engine/UIManager.hpp"
#include "../Engine/SettingsCache.hpp"

class Framework;

class SettingsMenu : public Gamestate
{
    public:
         SettingsMenu();
        ~SettingsMenu();
        void close();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        UIManager uielements;
};

#endif // SETTINGSMENU_HPP
