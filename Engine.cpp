#include "Engine.h"

void Engine::initStates()
{
	stack_of_states.push(new MainMenu(window, &stack_of_states));
}

void Engine::initWindows()
{
	window = new sf::RenderWindow(sf::VideoMode(1920, 1080),
		"Parallel Sort Visualization");
}

Engine::Engine() 
{
	initWindows();
	initStates();
}

void Engine::run()
{
	while (this->window->isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Engine::processEvents()
{
	stack_of_states.top()->processEvents();
}

void Engine::update()
{
	stack_of_states.top()->update();
}

void Engine::render()
{
	stack_of_states.top()->render();
}



