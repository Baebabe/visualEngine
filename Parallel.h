#pragma once
#include "State.h"

class Parallel :
    public State
{
public:
    Parallel(sf::RenderWindow*, std::stack<std::unique_ptr<State>>*);

    virtual void update();
    virtual void render();

    //button related
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();

protected:
    char whichSort;
    std::map<std::string, Button*> buttonMap;
    sf::Text text;
    sf::Font font;
};

