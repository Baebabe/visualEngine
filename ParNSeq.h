#pragma once
#include "State.h"
class ParNSeq :
    public State
{
public:
    ParNSeq(sf::RenderWindow*, std::stack<std::unique_ptr<State>>*);

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

