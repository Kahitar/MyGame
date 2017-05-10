#ifndef SETTINGSCACHE_HPP
#define SETTINGSCACHE_HPP

class SettingsCache
{
    public:
        SettingsCache();
        ~SettingsCache();

        //// GETTER ////
        int getAcceleratingForce() {return mForceToAccelerate;};
        int getPlayershipMass()	   {return mPlayershipMass;};


        //// SETTER ////
        void setAcceleratingForce(float force) {mForceToAccelerate = force;};
		void setPlayershipMass(int mass)	   {mPlayershipMass = mass;};

    private:
        int mForceToAccelerate;
        int mPlayershipMass;

};

#endif // SETTINGSCACHE_HPP
