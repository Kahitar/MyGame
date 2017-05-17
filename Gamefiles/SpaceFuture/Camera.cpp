#include "..\Engine\Framework.hpp"
#include "Camera.hpp"
#include "GameObject.hpp"
#include "Planet.hpp"
#include "Variables.hpp"
#include <cmath>

Camera::Camera()
	:mZoom(sf::Vector3f(1,1,0))
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
	return mView.getViewport().contains(Object.getCenter());
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
	float mZoomSpeed;
	if(std::abs(mZoom.y - mZoom.x) > 1)
		mZoomSpeed = std::abs(mZoom.y - mZoom.x);
	else
		mZoomSpeed = 1;

	if(mZoom.x < mZoom.y - std::abs(mZoom.z) || mZoom.x > mZoom.y + std::abs(mZoom.z))
		mZoom.x += mZoom.z*mZoomSpeed;
	else
		mZoom.x = mZoom.y;

	// update the position of the camera
	mView.setCenter(mTrackedObject->getCenter());
	mView.setSize(mZoom.x*Variables::WINDOW_WIDTH,mZoom.x*Variables::WINDOW_HEIGHT);
	frmwrk.setView(mView);

	Buttons.getButton("MainMenuButton").setSize(sf::Vector2f(mZoom.x*200,mZoom.x*50));
	Buttons.getButton("MainMenuButton")
	       .setPosition(sf::Vector2f(mView.getCenter().x - mZoom.x*620,mView.getCenter().y - mZoom.x*340));
	Buttons.update(frmwrk);
}

void Camera::handle(Framework &frmwrk)
{
	// move the camera according to player input
	// - zoom (Mousewheel)
	if(frmwrk.spMainEvent->type == sf::Event::MouseWheelMoved){
		if(mZoom.y > 0.4 || frmwrk.spMainEvent->mouseWheel.delta > 0)
			mZoom.y += frmwrk.spMainEvent->mouseWheel.delta*0.1;
		mZoom.z = frmwrk.spMainEvent->mouseWheel.delta*0.01;
	}

	// - drag&drop (?)
	// if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && 
 //       frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
 //    {
 //    	frmwrk.spMainEvent->mouseButton.x;
 //    }

	// handle buttons
	Buttons.handle(frmwrk);
    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && 
       frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
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
