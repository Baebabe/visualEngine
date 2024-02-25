#include "State.h"

State::State(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* stack)	
{
	this->window = window;
	this->stack_of_states = stack;
}


void State::updateMousePosition()
{
	mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

//bool State::isOpen()
//{
//	return (*window).isOpen();
//}
