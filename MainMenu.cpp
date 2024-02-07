#include "MainMenu.h"
#include "Sequential.h"
#include "Parallel.h"
#include "ParNSeq.h"

MainMenu::MainMenu(sf::RenderWindow* window, std::stack<State*>* stack) :
	State(window, stack)
{
	initButtons();
}

void MainMenu::update()
{
	updateMousePosition();
	updateButtons();
}

void MainMenu::render()
{
	renderButtons();
}

void MainMenu::initButtons()
{
	buttonMap["Parallel"] = new Button(40.f, 200.f, 500.f, 40.f,
		"Parallel", sf::Color::Red, sf::Color::Blue);
	buttonMap["Sequential"] = new Button(40.f, 200.f, 500.f, 120.f,
		"Sequetial", sf::Color::Red, sf::Color::Blue);
	buttonMap["SeqNPar"] = new Button(40.f, 200.f, 500.f, 200.f,
		"Paralle and Sequential", sf::Color::Red, sf::Color::Blue);
}

void MainMenu::updateButtons()
{
	mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	for (auto &it : buttonMap)
	{
		it.second->update(mousePosView);
	}

	if (buttonMap["Sequential"]->isPressed())
	{
		stack_of_states->push(new Sequential(window, stack_of_states));
	}

	if (buttonMap["Parallel"]->isPressed())
	{
		stack_of_states->push(new Parallel(window, stack_of_states));
	}

	if (buttonMap["SeqNPar"]->isPressed())
	{
		stack_of_states->push(new ParNSeq(window, stack_of_states));
	}
	
}

void MainMenu::renderButtons()
{
	for (auto& it : buttonMap)
	{
		it.second->render(window);
	}
}

//void MainMenu::updateMousePosition()
//{
//	mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//}

//bool MainMenu::isOpen()
//{
//	return (window->isOpen());
//}
