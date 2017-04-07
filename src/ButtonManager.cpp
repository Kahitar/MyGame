#include "Framework.hpp"
#include "ButtonManager.hpp"
#include <algorithm>

ButtonManager::ButtonManager()
{
    //ctor
}

ButtonManager::~ButtonManager()
{
    //dtor
}

void ButtonManager::addButton(sf::Vector2f pos, sf::Vector2f Size, std::string Name, std::string Text)
{
    //check if Button doesn't already exists
    if(Buttons.find(Name) == Buttons.end()){
    //add Button if it doesn't already exist
        //Load the button
        std::shared_ptr<Button> newButton(new Button(pos,Size,Text));

        //Insert it into the map
        Buttons.insert(make_pair(Name, newButton));
    }
    else{
    //"error" if it already exists
        std::cout << "ERROR: A UI-element with the name \"";
        std::cout << Name;
        std::cout << "\" already exists!";
    }
}

Button ButtonManager::getButton(std::string ButtonName)
{
    //lookup the Button name and see if its in the map
    auto it = Buttons.find(ButtonName);

    //TODO: Check if the Button exists or not! What to do if it doesn't?

    return *it->second;
}

void ButtonManager::update(Framework &frmwrk)
{
    for(auto it : Buttons)
    {
        it.second->update();
    }
}

void ButtonManager::handle(Framework &frmwrk)
{
    for(auto it : Buttons)
    {
        it.second->handle(frmwrk);
    }
}

void ButtonManager::render(Framework &frmwrk)
{
    for(auto it : Buttons)
    {
        it.second->render(frmwrk.spRenderWindow);
    }
}
