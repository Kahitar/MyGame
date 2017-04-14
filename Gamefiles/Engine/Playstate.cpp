#include "Playstate.hpp"
#include "Framework.hpp"

Playstate::Playstate()
    :mMoveSpeed(500)
{
    Buttons.addButton(sf::Vector2f(540,300),sf::Vector2f(200,50),"MainMenuButton","Main Menu");

    // TODO: (Re)set the view with the actual window size
    playerView.reset(sf::FloatRect(0,0,1280,720));
}

Playstate::~Playstate()
{
    //dtor
}

void Playstate::update(Framework &frmwrk)
{
    Buttons.update(frmwrk);
    world1.update(frmwrk);

    frmwrk.setView(playerView);

    EvaluatePressedKeys(frmwrk);
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
        int oldViewX = frmwrk.spRenderWindow->getView().getCenter().x - frmwrk.spRenderWindow->getView().getSize().x/2;
        int oldViewY = frmwrk.spRenderWindow->getView().getCenter().y - frmwrk.spRenderWindow->getView().getSize().y/2;
        sf::FloatRect visibleArea(oldViewX, oldViewY, frmwrk.spRenderWindow->getSize().x, frmwrk.spRenderWindow->getSize().y);

        playerView.reset(visibleArea);
        frmwrk.setView(playerView);
    }
}

void Playstate::render(Framework &frmwrk)
{
    Buttons.render(frmwrk);
    world1.render(frmwrk);
}

void Playstate::EvaluatePressedKeys(Framework &frmwrk)
{
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
