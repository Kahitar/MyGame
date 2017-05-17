#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "..\Engine\UIManager.hpp"

class Framework;
class GameObject;

class Camera 
{
public:
	 Camera();
	~Camera();

	void setView();
	sf::View& getView();
	bool isInView(GameObject &Object);
	void track(GameObject *Object);
	GameObject& getTrackedObject();

	void update(Framework &frmwrk);
	void handle(Framework &frmwrk);
	void render(Framework &frmwrk);

private:
	sf::View mView;
	sf::Vector2f mPosition;
	sf::Vector2f mZoom;

	UIManager Buttons;

	GameObject *mTrackedObject;
};


#endif // CAMERA_HPP