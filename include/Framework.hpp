#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include <SFML\Graphics.hpp>
#include <memory>

#include "Gamestate.hpp"
#include "MainMenu.hpp"

class Framework
{
public:
     Framework();
    ~Framework();

    enum class gameStates {SETTINGS, MAINMENU, PLAY};

    void run();
    void quit();
    void ChangeState(gameStates newstate);

    std::shared_ptr<sf::RenderWindow> spRenderWindow;
    std::shared_ptr<sf::Event>        spMainEvent;

private:
    void update(float mFrameTime);
    void handleEvents();
    void render();

    void CalculateFrameTime();
    //void CalculateScale(); //Not implemented yet

    std::unique_ptr<Gamestate>   CurrentState;

    std::unique_ptr<sf::Clock>   upClock;
    std::unique_ptr<sf::Texture> upBackTexture;
    std::unique_ptr<sf::Sprite>  upBackSprite;

    float   mFrameTime;
    bool    mRunning;
};

#endif // FRAMEWORK_HPP
