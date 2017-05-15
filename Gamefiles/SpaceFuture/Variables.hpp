#ifndef VARIABLES_HPP
#define VARIABLES_HPP

class Variables
{
public:
	// Graphics
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;
	static int FRAMERATE_LIMIT;

	// Game Settings
	static int lengthScaleFactor;  // 1 pxls = x m
	static int TimeFactor;		   // Time will be accelerated by this amount

	static int defaultAccelerationForce;
};

#endif // VARIABLES_HPP
