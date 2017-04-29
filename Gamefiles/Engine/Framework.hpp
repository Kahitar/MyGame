#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>

#include "Gamestate.hpp"
#include "MainMenu.hpp"
#include "SettingsMenu.hpp"
#include "Playstate.hpp"
#include "FlyShipState.hpp"

class Framework
{
public:
     Framework();
    ~Framework();

    enum class gameStates {SETTINGS, MAINMENU, PLAY, FLYSHIP};

    void run();
    void quit();
    void ChangeState(gameStates newstate);

    void    setViewToWindowSize();
    void    setView(sf::View newView);
    void    setView(sf::FloatRect visibleArea);

    sf::Vector2f getTransformedMousePosition();

    sf::View        getView();
    static float    getFrameTime();

    std::shared_ptr<sf::RenderWindow> spRenderWindow;
    std::shared_ptr<sf::Event>        spMainEvent;

private:
    void update(float mFrameTime);
    void handleEvents();
    void render();

    void CalculateFrameTime();
    //void CalculateScale(); //Not implemented yet (TODO?)

    std::unique_ptr<Gamestate>   CurrentState;
    std::unique_ptr<sf::Clock>   upClock;

    static float   mFrameTime;
    bool           mRunning;
};

#endif // FRAMEWORK_HPP
