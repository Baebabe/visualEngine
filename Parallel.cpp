#include "Parallel.h"
#include "Intermediate.h"

Parallel::Parallel(sf::RenderWindow*window, std::stack<std::unique_ptr<State>>* stack)
	:State(window, stack)
{
	initButtons();
}

void Parallel::update()
{
	updateMousePosition();
	updateButtons();
}

void Parallel::render()
{
	renderButtons();
}

void Parallel::initButtons()
{
	buttonMap["Bubble"] = new Button(40.f, 200.f, 960.f, 20.f,
		"BubbleSort", sf::Color::Red, sf::Color::Blue);

	buttonMap["Merge"] = new Button(40.f, 200.f, 960.f, 70.f,
		"MergeSort", sf::Color::Red, sf::Color::Blue);

	buttonMap["Quick"] = new Button(40.f, 200.f, 960.f, 120.f,
		"QuickSort", sf::Color::Red, sf::Color::Blue);

	buttonMap["Insertion"] = new Button(40.f, 200.f, 960.f, 170.f,
		"InsertionSort", sf::Color::Red, sf::Color::Blue);

	buttonMap["Selection"] = new Button(40.f, 200.f, 960.f, 220.f,
		"SelectionSort", sf::Color::Red, sf::Color::Blue);

	buttonMap["Heap"] = new Button(40.f, 200.f, 960.f, 270.f,
		"HeapSort", sf::Color::Red, sf::Color::Blue);

	buttonMap["Bucket"] = new Button(40.f, 200.f, 960.f, 320.f,
		"BucketSort", sf::Color::Red, sf::Color::Blue);

	buttonMap["Radix"] = new Button(40.f, 200.f, 960.f, 370.f,
		"RadixSort", sf::Color::Red, sf::Color::Blue);

	buttonMap["Exit"] = new Button(40.f, 200.f, 960.f, 1020.f,
		"Exit", sf::Color::Red, sf::Color::Blue);
}

void Parallel::updateButtons()
{
	for (auto& it : buttonMap)
	{
		it.second->update(mousePosView);
	}

	if (buttonMap["Bubble"]->isPressed())
	{
		whichSort = 'b';
		stack_of_states->push(std::make_unique<Intermediate>(window, stack_of_states, whichSort, false));
	}
	if (buttonMap["Merge"]->isPressed())
	{
		whichSort = 'm';
		stack_of_states->push(std::make_unique<Intermediate>(window, stack_of_states, whichSort, false));
	}
	if (buttonMap["Selection"]->isPressed())
	{
		whichSort = 's';
		stack_of_states->push(std::make_unique<Intermediate>(window, stack_of_states, whichSort, false));
	}
	if (buttonMap["Quick"]->isPressed())
	{
		whichSort = 'q';
		stack_of_states->push(std::make_unique<Intermediate>(window, stack_of_states, whichSort, false));
	}
	if (buttonMap["Exit"]->isPressed())
	{
		stack_of_states->pop();
	}
}

void Parallel::renderButtons()
{
	for (auto& it : buttonMap)
	{
		it.second->render(window);
	}
}
