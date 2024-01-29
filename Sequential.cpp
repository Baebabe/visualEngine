#include "Sequential.h"

Sequential::Sequential(sf::RenderWindow* window, std::stack<State*>* stack)
	: State(window, stack)
{
	initButtons();
}

void Sequential::processEvents()
{
	sf::Event evnt;
	while (window->pollEvent(evnt))
	{
		if (evnt.type == sf::Event::Closed)
			window->close();
	}
}

void Sequential::update()
{
	updateMousePosition();
	updateButtons();
}

void Sequential::render()
{
	window->clear();
	renderButtons();
	window->display();
}

void Sequential::initButtons()
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

void Sequential::updateButtons()
{
	for (auto& it : buttonMap)
	{
		it.second->update(mousePosView);
	}
	if (buttonMap["Exit"]->isPressed())
	{
		stack_of_states->pop();
	}
}

void Sequential::renderButtons()
{
	for (auto& it : buttonMap)
	{
		it.second->render(window);
	}
}
