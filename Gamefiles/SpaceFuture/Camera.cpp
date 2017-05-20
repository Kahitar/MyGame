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
	uielements.addButton(sf::Vector2f(540,50),sf::Vector2f(200,50),"MainMenuButton","Main menu");
}

Camera::~Camera()
{
	uielements.deleteButton("MainMenuButton");
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
	updateUI(frmwrk);
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
	uielements.handle(frmwrk);
    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && 
       frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        if(uielements.getButton("MainMenuButton").getMouseOnObject()){
            frmwrk.ChangeState(Framework::gameStates::MAINMENU);
        }
    }
}

void Camera::render(Framework &frmwrk) 
{
   uielements.render(frmwrk);
}

// Getter and Setter //

void Camera::setView()
{

}

sf::View& Camera::getView()
{
	return mView;
}

void Camera::updateUI(Framework &frmwrk)
{
	float mZoomSpeed;
	if(std::abs(mZoom.y - mZoom.x) > 1)
		mZoomSpeed = std::abs(mZoom.y - mZoom.x);
	else
		mZoomSpeed = 1;

	// zoom the view if the actual position x is not within the target position x +/- abs(z)*zoomspeed
	if(mZoom.x < mZoom.y - std::abs(mZoom.z)*mZoomSpeed || mZoom.x > mZoom.y + std::abs(mZoom.z)*mZoomSpeed)
		mZoom.x += mZoom.z*mZoomSpeed;
	else
		mZoom.x = mZoom.y;

	// update the view
	mView.setCenter(mTrackedObject->getCenter());
	mView.setSize(mZoom.x*Variables::WINDOW_WIDTH,mZoom.x*Variables::WINDOW_HEIGHT);
	frmwrk.setView(mView);

	// update Buttons
	uielements.getButton("MainMenuButton").setSize(sf::Vector2f(mZoom.x*200,mZoom.x*50));
	// uielements.getButton("MainMenuButton").setScale(mZoom.x,mZoom.x);
	uielements.getButton("MainMenuButton")
	          .setPosition(sf::Vector2f(mView.getCenter().x - mZoom.x*620,mView.getCenter().y - mZoom.x*340));

	// uielements.getButton("VelocityResetButton").setSize(sf::Vector2f(mZoom.x*200,mZoom.x*50));
	uielements.getButton("VelocityResetButton").setScale(mZoom.x,mZoom.x);
	uielements.getButton("VelocityResetButton")
	       	  .setPosition(sf::Vector2f(mView.getCenter().x - mZoom.x*300,mView.getCenter().y - mZoom.x*100));

	uielements.update(frmwrk);
}