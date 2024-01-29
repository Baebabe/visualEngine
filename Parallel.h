#pragma once
#include "State.h"

class Parallel :
    public State
{
public:
    Parallel(sf::RenderWindow*, std::stack<State*>*);

    virtual void processEvents();
    virtual void update();
    virtual void render();

    //button related
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();

protected:
    std::map<std::string, Button*> buttonMap;
    sf::Text text;
    sf::Font font;
};

