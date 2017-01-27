#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include "Gamestate.hpp"
#include "Button.hpp"
#include "ButtonManager.hpp"
#include "Slider.hpp"

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
        ButtonManager Buttons;
        std::unique_ptr<Slider> upSlider;
};

#endif // SETTINGSMENU_HPP
