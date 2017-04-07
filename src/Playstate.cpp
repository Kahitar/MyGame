#include "Playstate.hpp"
#include "Framework.hpp"

Playstate::Playstate()
    :mMoveSpeed(500)
{
    Buttons.addButton(sf::Vector2f(540,300),sf::Vector2f(200,50),"MainMenuButton","Main Menu");

    playerView.reset(sf::FloatRect(200,200,400,400));
//    playerView.setViewport(sf::FloatRect(0.25,0.25,0.5,0.5));
}

Playstate::~Playstate()
{
    //dtor
}

void Playstate::update(Framework &frmwrk)
{
    Buttons.update(frmwrk);
    world1.update(frmwrk);

    frmwrk.spRenderWindow->setView(playerView);

    //Keyboard Key pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerView.move(0,-mMoveSpeed*frmwrk.getFrameTime());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerView.move(-mMoveSpeed*frmwrk.getFrameTime(),0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerView.move(0,mMoveSpeed*frmwrk.getFrameTime());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerView.move(mMoveSpeed*frmwrk.getFrameTime(),0);
    }
}

void Playstate::handle(Framework &frmwrk)
{
    Buttons.handle(frmwrk);
    world1.handle(frmwrk);

    //Mouse Button pressed
    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left){
        if(Buttons.getButton("MainMenuButton").getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }

    // catch the resize events
    if (frmwrk.spMainEvent->type == sf::Event::Resized)
    {
        // update the view to the new size of the window
        sf::FloatRect visibleArea(0, 0, frmwrk.spMainEvent->size.width, frmwrk.spMainEvent->size.height);
        playerView.reset(visibleArea);
        frmwrk.spRenderWindow->setView(playerView);
    }
}

void Playstate::render(Framework &frmwrk)
{
    Buttons.render(frmwrk);
    world1.render(frmwrk);
}
