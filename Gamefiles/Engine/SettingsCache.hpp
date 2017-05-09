#ifndef SETTINGSCACHE_HPP
#define SETTINGSCACHE_HPP

class SettingsCache
{
    public:
        SettingsCache();
        ~SettingsCache();

        //// GETTER ////
        float getAcceleratingForce() {return mForceToAccelerate;};

        //// SETTER ////
        void setAcceleratingForce(float force) {mForceToAccelerate = force;};

    private:
        float mForceToAccelerate;

};

#endif // SETTINGSCACHE_HPP
