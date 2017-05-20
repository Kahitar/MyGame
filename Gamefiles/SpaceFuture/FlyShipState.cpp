#include <sstream>
#include "../Engine/Framework.hpp"
#include "FlyShipState.hpp"
#include "Variables.hpp"

FlyShipState::FlyShipState()
    //:playership("assets\\textures\\star_trek_xi_enterprise_v1.png", sf::Vector2f(500,300))
{
    playership = new Playership("assets\\textures\\star_trek_xi_enterprise_v1.png", sf::Vector2f(500,300));
    earth = new Planet();

    camera.track(playership);
}

FlyShipState::~FlyShipState()
{
    delete playership;
    delete earth;
}

void FlyShipState::update(Framework &frmwrk)
{
    playership->update(frmwrk);
    earth->update(frmwrk);
    
    camera.update(frmwrk);
}

void FlyShipState::handle(Framework &frmwrk)
{
    playership->handle(frmwrk);
    earth->handle(frmwrk);
    camera.handle(frmwrk);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        frmwrk.ChangeState(Framework::gameStates::MAINMENU);
}

void FlyShipState::render(Framework &frmwrk)
{
    earth->render(frmwrk);
    playership->render(frmwrk);
    camera.render(frmwrk);
}
