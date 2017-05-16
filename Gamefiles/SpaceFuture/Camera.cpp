#include "..\Engine\Framework.hpp"
#include "Camera.hpp"
#include "GameObject.hpp"
#include "Planet.hpp"
#include "Variables.hpp"

Camera::Camera()
{
	mView.reset(sf::FloatRect(0,0,Variables::WINDOW_WIDTH,Variables::WINDOW_HEIGHT));

	Buttons.addButton(sf::Vector2f(540,50),sf::Vector2f(200,50),"MainMenuButton","Main menu");
}

Camera::~Camera()
{
	// dtor
}

bool Camera::isInView(GameObject &Object)
{
	// check if Object is in camera view
	return mView.getViewport().contains(Object.getPosition());
}

void Camera::track(GameObject *Object)
{
	// Center the view on Object.
	this->mTrackedObject = Object;
}

GameObject& Camera::getTrackedObject()
{
	return *mTrackedObject;
}

void Camera::update(Framework &frmwrk)
{
	// update the position of the camera
	mView.setCenter(mTrackedObject->getPosition());
	frmwrk.setView(mView);

	Buttons.getButton("MainMenuButton").setPosition(sf::Vector2f(mView.getCenter().x - 620,mView.getCenter().y - 340));
	Buttons.update(frmwrk);
}

void Camera::handle(Framework &frmwrk)
{
	// move the camera according to player input
	// - zoom (Mousewheel)
	// - drag&drop (?)

	// handle buttons
	Buttons.handle(frmwrk);
    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        if(Buttons.getButton("MainMenuButton").getMouseOnButton()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }
}

void Camera::render(Framework &frmwrk) 
{
   Buttons.render(frmwrk);
}

// Getter and Setter //

void Camera::setView()
{

}

sf::View& Camera::getView()
{
	return mView;
}
