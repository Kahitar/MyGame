#ifndef OBJECTTIME_HPP
#define OBJECTTIME_HPP

#include <SFML/Graphics.hpp>
#include "../Engine/UIManager.hpp"

#include <sstream>

class Framework;

class ObjectTime
{
    public:
        ObjectTime(std::string name);
        ~ObjectTime();

        // Setter //
        void setTime(float time)                     {mTime = time;};
        void setGlobalTimeStep(float GlobalTimeStep) {mGlobalTimeStep = GlobalTimeStep;};
        void setPosition(sf::Vector2f position)      {mPosition = position;};

        // Getter //
        float getTime()              {return mTime;};
        float getNextTimeStep()      {return mNextTimeStep;};
        float getGlobalTimeStep()    {return mGlobalTimeStep;};
        sf::Vector2f getPosition()   {return mPosition;};

        void reset(int newTime = 0);

        void update(Framework &frmwrk, float velocity);
        void render(Framework &frmwrk);
    private:
        void updateTime(float velocity);
        void calculateNextTimeStep(double v_local);
        void CalculateTimeInHours();

        float mTime; // time in seconds
        //sf::Vector3f mTimeInHours; // time in yy/mm hh:mm:ss (TODO)
        float mNextTimeStep;
        float mGlobalTimeStep;

        sf::Vector2f mPosition;

        static int mClockNr;
        std::stringstream ClockName;

        UIManager uielements;
};

#endif // OBJECTTIME_HPP
