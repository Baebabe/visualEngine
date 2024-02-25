#pragma once
#include "State.h"
#include "CreateRectangle.h"

class Sort :
    public State
{
public:
    Sort(sf::RenderWindow*, std::stack<std::unique_ptr<State>>*, std::vector<int>& , CreateRectangle& );

    //Main stuff
    virtual void update();
    virtual void render();

    // UNIQUE TO SORT STATES
    void initArray();
    void bubbleSort();
    

    //Button Related
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();

private:
    std::vector<int> array;
    CreateRectangle rectBar;
};

