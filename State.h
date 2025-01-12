#pragma once

#include"Button.h"
#include<map>
#include<stack>

class State
{
public:
	State(sf::RenderWindow* , std::stack<std::unique_ptr<State>>* );

	//MAIN STUFF
	virtual void update() = 0;
	virtual void render() = 0;

	//STATE COSMETICS

	//BUTTON RELATED
	virtual void initButtons() = 0;
	virtual void updateButtons() = 0;
	virtual void renderButtons() = 0;
	void updateMousePosition(); 

	//RETURN FUNCTION
	//bool isOpen();

protected:
	sf::Vector2f mousePosView;
	sf::RenderWindow* window;
	std::stack<std::unique_ptr<State>>* stack_of_states;	
};

