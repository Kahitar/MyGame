#ifndef SETTINGSCACHE_HPP
#define SETTINGSCACHE_HPP

class SettingsCache
{
    public:
        SettingsCache();
        ~SettingsCache();

        //// GETTER ////
        float getForceToAccelerate() {return mForceToAccelerate;};

        //// SETTER ////
        void setForceToAccelerate(float force) {mForceToAccelerate = force;};

    private:
        float mForceToAccelerate;

};

#endif // SETTINGSCACHE_HPP
