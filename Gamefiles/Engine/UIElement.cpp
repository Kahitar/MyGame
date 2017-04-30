#include "Framework.hpp"
#include "UIElement.hpp"
#include <algorithm>

UIElement::UIElement()
{
    //ctor
}

UIElement::~UIElement()
{
    //dtor
}

void UIElement::addButton(sf::Vector2f pos, sf::Vector2f Size, std::string Name, std::string Text)
{
    //check if Elementname doesn't already exists
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

void UIElement::addSlider(sf::Vector2f pos, sf::Vector2f Size, std::string Name, std::string Text)
{
    //check if Elementname doesn't already exists
    if(Sliders.find(Name) == Sliders.end()){
    //add Slider if element doesn't already exist
        //Load the Slider
        std::shared_ptr<Slider> newSlider(new Slider(pos,Size));

        //Insert it into the map
        Sliders.insert(make_pair(Name, newSlider));
    }
    else{
    //"error" if it already exists
        std::cout << "ERROR: A UI-element with the name \"";
        std::cout << Name;
        std::cout << "\" already exists!";
    }
}

Button& UIElement::getButton(std::string ButtonName)
{
    //lookup the Button name and see if its in the map
    auto it = Buttons.find(ButtonName);

    //TODO: Check if the Button exists or not! What to do if it doesn't?

    return *it->second;
}

Slider& UIElement::getSlider(std::string SliderName)
{
    //lookup the Slider name and see if its in the map
    auto it = Sliders.find(SliderName);

    //TODO: Check if the Slider exists or not! What to do if it does?

    return *it->second;
}

void UIElement::update(Framework &frmwrk)
{
    for(auto it : Buttons)
    {
        it.second->update();
    }

    for(auto it : Sliders)
    {
        it.second->update(frmwrk);
    }
}

void UIElement::handle(Framework &frmwrk)
{
    for(auto it : Buttons)
    {
        it.second->handle(frmwrk);
    }

    for(auto it : Sliders)
    {
        it.second->handle(frmwrk);
    }
}

void UIElement::render(Framework &frmwrk)
{
    for(auto it : Buttons)
    {
        it.second->render(frmwrk);
    }

    for(auto it : Sliders)
    {
        it.second->render(frmwrk);
    }
}
