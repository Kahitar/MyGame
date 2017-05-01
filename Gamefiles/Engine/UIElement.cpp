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

void UIElement::addTextBox(std::string Name, std::string text, std::string FontPath, sf::Vector2f position,
                        int borderThickness, sf::Color fillColor, sf::Color outlineColor)
{
    //check if Elementname doesn't already exists
    if(TextBoxes.find(Name) == TextBoxes.end()){
    //add TextBoxes if it doesn't already exist
        //Load the TextBox
        std::shared_ptr<TextBox> newTextBox(new TextBox(text, FontPath, position, borderThickness, fillColor, outlineColor));

        //Insert it into the map
        TextBoxes.insert(make_pair(Name, newTextBox));
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
    if(Buttons.find(ButtonName) == Buttons.end()){
    //"error" if it doesn't exist
        std::cout << "ERROR: There is no UIElement with the name \"";
        std::cout << ButtonName;
        std::cout << "\" !";

        return *Buttons.end()->second;
    }else {
        auto it = Buttons.find(ButtonName);

        return *it->second;
    }

    //TODO: Check if the Button exists or not! What to do if it doesn't?
}

Slider& UIElement::getSlider(std::string SliderName)
{
    //lookup the Slider name and see if its in the map
    auto it = Sliders.find(SliderName);

    //TODO: Check if the Slider exists or not! What to do if it does?

    return *it->second;
}

TextBox& UIElement::getTextBox(std::string TextBoxName)
{
    //lookup the Textbox name and see if its in the map
    auto it = TextBoxes.find(TextBoxName);

    //TODO: Check if the TextBox exists or not! What to do if it doesn't?

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

    for(auto it : TextBoxes)
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

    for(auto it : TextBoxes)
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

    for(auto it : TextBoxes)
    {
        it.second->render(frmwrk);
    }
}
