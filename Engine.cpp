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
		sf::Event evnt;
		while (window->pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window->close();
			}
			update();
		}
		render();
	}
}

void Engine::update()
{
	stack_of_states.top()->update();
}

void Engine::render()
{
	window->clear(sf::Color(128, 128, 128, 128));
	stack_of_states.top()->render();
	window->display();
}



