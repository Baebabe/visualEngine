#pragma once

#include"MainMenu.h"

class Engine
{
public:
	void initStates();
	void initWindows();
	Engine();
	void run();
	void update();
	void render();

private:
	std::stack<State*> stack_of_states;
	sf::RenderWindow *window;
};

