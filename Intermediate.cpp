#include "Intermediate.h"
#include "Sort.h"

Intermediate::Intermediate(sf::RenderWindow* window, std::stack<State*>* stack_of_states)
	: State(window, stack_of_states)
{
	initButtons();
	initArray();
	rectBar.initialize(array);
}

void Intermediate::update()
{
	updateMousePosition();
	updateButtons();
}

void Intermediate::render()
{
	renderButtons();
}

void Intermediate::initArray()
{
	std::random_device rd;
	std::default_random_engine engine{rd()};
	std::uniform_int_distribution<int> ints{1, 50};

	for (int i = 0; i < 50; i++)
	{
		array.emplace_back(ints(engine));
	}
}

void Intermediate::initButtons()
{
	buttonMap["Start"] = new Button(40.f, 100.f, 200.f, 900.f,
		"Start", sf::Color::Red, sf::Color::Blue);
	
	buttonMap["Randomize"] = new Button(40.f, 200.f, 350.f, 900.f,
		"Randomize", sf::Color::Red, sf::Color::Blue);

	buttonMap["Exit"] = new Button(40.f, 100.f, 520.f, 900.f,
		"Exit", sf::Color::Red, sf::Color::Blue);
	
	buttonMap["Increase"] = new Button(40.f, 50.f, 630.f, 900.f,
		"+", sf::Color::Red, sf::Color::Blue);
	
	buttonMap["Decrease"] = new Button(40.f, 50.f, 690.f, 900.f,
		"-", sf::Color::Red, sf::Color::Blue);
}

void Intermediate::updateButtons()
{
	for (auto& it : buttonMap)
	{
		it.second->update(mousePosView);
	}

	if (buttonMap["Randomize"]->isPressed())
	{
		array.clear();
		initArray();
		rectBar.justSize(array);
	}

	if (buttonMap["Start"]->isPressed())
	{
		stack_of_states->push(new Sort(window, stack_of_states, array, rectBar));
	}
}

void Intermediate::renderButtons()
{
	for (auto& it : buttonMap)
	{
		it.second->render(window);
	}
	rectBar.renderRectangle(window);
}