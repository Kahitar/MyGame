#include "Framework.hpp"
#include "ResourceManager.hpp"

using namespace std;

Framework::Framework()
    :mRunning(true)
{
    spRenderWindow  = std::move(std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(1280,720,32),"NewGame")));
    spMainEvent     = std::move(std::unique_ptr<sf::Event>(new sf::Event));
    upClock         = std::move(std::unique_ptr<sf::Clock>(new sf::Clock));

    upBackTexture   = std::move(std::unique_ptr<sf::Texture>(new sf::Texture));
    upBackSprite    = std::move(std::unique_ptr<sf::Sprite>(new sf::Sprite));

    spRenderWindow->setPosition(sf::Vector2i(50,50));
    *upBackTexture = ResourceManager::getTexture("assets\\textures\\pillarsofcreation.png");
    upBackSprite->setTexture(*upBackTexture);

    // Set Gamestate to MAINMENU, in case it is not changed in main
    CurrentState = std::move(std::unique_ptr<MainMenu>(new MainMenu));
}

Framework::~Framework()
{

}

void Framework::run()
{

    while(mRunning)
    {
        update(mFrameTime);
        handleEvents();
        render();

        if(mRunning == false)
            quit();
    }
}

void Framework::ChangeState(gameStates newstate)
{
    switch(newstate)
    {
    case gameStates::MAINMENU:
        CurrentState = std::move(std::unique_ptr<MainMenu>(new MainMenu));
    break;
    case gameStates::SETTINGS:
        CurrentState = std::move(std::unique_ptr<SettingsMenu>(new SettingsMenu));
    break;
    }
}

sf::Vector2f Framework::getTransformedMousePosition()
{
    // get the current mouse position in the window
    sf::Vector2i MousePixelPos = sf::Mouse::getPosition(*spRenderWindow);
    // convert it to world coordinates
    return spRenderWindow->mapPixelToCoords(MousePixelPos);
}

void Framework::quit()
{
    spRenderWindow->close();
    mRunning = false;
}

void Framework::update(float FrameTime)
{
    CurrentState->update(*this);

    this->CalculateFrameTime();
}

void Framework::handleEvents()
{
    while(spRenderWindow->pollEvent(*spMainEvent))
    {
        CurrentState->handle(*this);

        if(spMainEvent->type == sf::Event::MouseButtonPressed){
            if(spMainEvent->mouseButton.button == sf::Mouse::Left){

            }
        }
        if(spMainEvent->type == sf::Event::Closed)
            mRunning = false;
    }
}

void Framework::render()
{
    spRenderWindow->clear();

    spRenderWindow->draw(*upBackSprite);
    CurrentState->render(*this);

    spRenderWindow->display();
}

void Framework::CalculateFrameTime()
{
    mFrameTime = upClock->getElapsedTime().asSeconds();
    upClock->restart();
//    cout << "FPS:" << 1/mFrameTime << endl;
}
