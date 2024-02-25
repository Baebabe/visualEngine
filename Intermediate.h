#pragma once
#include "State.h"
#include "CreateRectangle.h"
class Intermediate :
    public State
{
public:
    Intermediate(sf::RenderWindow* , std::stack<std::unique_ptr<State>>*, bool);

    //main stuff
    virtual void update();
    virtual void render();

    //
    void initArray();

    // BUTTON RELATED
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();

private:
    std::map<std::string, Button*> buttonMap;
    std::vector<int> array;
    CreateRectangle rectBar;

    bool sequential;
};

