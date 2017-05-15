#include "SettingsCache.hpp"
#include "..\SpaceFuture\Variables.hpp"

SettingsCache::SettingsCache()
	:mForceToAccelerate(Variables::defaultAccelerationForce),mPlayershipMass(10)
{
    //ctor
}

SettingsCache::~SettingsCache()
{
    //dtor
}
