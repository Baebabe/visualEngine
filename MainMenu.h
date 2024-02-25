#pragma once
#include "State.h"

class MainMenu :
    public State
{
public:
    MainMenu(sf::RenderWindow* window, std::stack<std::unique_ptr<State>> *);

    //Updates
    virtual void update();
    virtual void render();

    //virtual void initText();

    //Button related
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();
    //virtual void updateMousePosition();

    //NECESSARY RETURN FUNCTION
    //bool isOpen();

private:
    sf::Text text;
    sf::Font font;
    std::map<std::string, Button *> buttonMap;
    sf::Vector2f mousePos;
};

