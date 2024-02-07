#pragma once
#include "State.h"
#include "CreateRectangle.h"

class Bubble :
    public State
{
public:
    Bubble(sf::RenderWindow*, std::stack<State*>*);

    //Main stuff
    virtual void update();
    virtual void render();

    // UNIQUE TO SORT STATES
    void initArray();
    void sort();

    //Button Related
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();

private:
    std::vector<int> array;
    CreateRectangle rectBar;
};

