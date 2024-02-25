#pragma once
#include "State.h"
class Sequential :
    public State
{
public:
    Sequential(sf::RenderWindow*, std::stack<std::unique_ptr<State>>*);

    //MAIN STUFF
    virtual void update();
    virtual void render();

    void initFiles();

    //State cosmetics

    //Button related
    virtual void initButtons();
    virtual void updateButtons();
    virtual void renderButtons();
    
private:
    sf::Text text;
    sf::Font font;
    std::map<std::string, Button*> buttonMap;

    std::fstream file;
};

