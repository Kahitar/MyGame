#include <sstream>
#include "../Engine/Framework.hpp"
#include "FlyShipState.hpp"
#include "Variables.hpp"

FlyShipState::FlyShipState()
    //:playership("assets\\textures\\star_trek_xi_enterprise_v1.png", sf::Vector2f(500,300))

{
    playership = new Playership("assets\\textures\\star_trek_xi_enterprise_v1.png", sf::Vector2f(500,300));
    std::cout << "1" << std::endl;
    // earth = new Planet();
    std::cout << "2" << std::endl;

    camera.track(playership);
    std::cout << "3" << std::endl;
}

FlyShipState::~FlyShipState()
{
    delete playership;
}

void FlyShipState::update(Framework &frmwrk)
{
    std::cout << "4" << std::endl;
    playership->update(frmwrk);
    
    std::cout << "5" << std::endl;
    camera.update(frmwrk); // <--- ERROR! (Segfault, works now... TODO?)
    std::cout << "6" << std::endl;
}

void FlyShipState::handle(Framework &frmwrk)
{
    playership->handle(frmwrk);
    camera.handle(frmwrk);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        frmwrk.ChangeState(Framework::gameStates::MAINMENU);
}

void FlyShipState::render(Framework &frmwrk)
{
    earth.render(frmwrk);
    playership->render(frmwrk);
    camera.render(frmwrk);
}
