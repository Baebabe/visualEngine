#include "Sequential.h"
#include "Intermediate.h"

Sequential::Sequential(sf::RenderWindow* window, std::stack<State*>* stack)
	: State(window, stack)
{
	initButtons();
	initFiles();
}

void Sequential::update()
{
	updateMousePosition();
	updateButtons();
}

void Sequential::render()
{
	renderButtons();
}

void Sequential::initFiles()
{
	file.open("Files/sort.txt");
	if (!file.is_open())
		std::cout << "Could not open file" << std::endl;
}

void Sequential::initButtons()
{
	buttonMap["Bubble"] = new Button(40.f, 200.f, 1800.f, 20.f,
		"BubbleSort", sf::Color(100, 100, 100, 100), sf::Color(150,150,150,150));

	buttonMap["Merge"] = new Button(40.f, 200.f, 1800.f, 70.f,
		"MergeSort", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));

	buttonMap["Quick"] = new Button(40.f, 200.f, 1800.f, 120.f,
		"QuickSort", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));

	buttonMap["Insertion"] = new Button(40.f, 200.f, 1800.f, 170.f,
		"InsertionSort", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));

	buttonMap["Selection"] = new Button(40.f, 200.f, 1800.f, 220.f,
		"SelectionSort", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));

	buttonMap["Heap"] = new Button(40.f, 200.f, 1800.f, 270.f,
		"HeapSort", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));

	buttonMap["Bucket"] = new Button(40.f, 200.f, 1800.f, 320.f,
		"BucketSort", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));

	buttonMap["Radix"] = new Button(40.f, 200.f, 1800.f, 370.f,
		"RadixSort", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));

	buttonMap["Exit"] = new Button(40.f, 200.f, 1800.f, 470.f,
		"Exit", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));
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

	if (buttonMap["Bubble"]->isPressed())
	{
		file << "a";
		stack_of_states->push(new Intermediate(window, stack_of_states, true));
	}

	if (buttonMap["Merge"]->isPressed())
	{
		file << "b";
		stack_of_states->push(new Intermediate(window, stack_of_states, true));
	}

	if (buttonMap["Quick"]->isPressed())
	{
		file << "c";
		stack_of_states->push(new Intermediate(window, stack_of_states, true));
	}

	if (buttonMap["Insertion"]->isPressed())
	{
		file << "d";
		stack_of_states->push(new Intermediate(window, stack_of_states, true));
	}

	if (buttonMap["Selection"]->isPressed())
	{
		file << "e";
		stack_of_states->push(new Intermediate(window, stack_of_states, true));
	}

	if (buttonMap["Heap"]->isPressed())
	{
		file << "f";
		stack_of_states->push(new Intermediate(window, stack_of_states, true));
	}

	if (buttonMap["Bucket"]->isPressed())
	{
		file << "g";
		stack_of_states->push(new Intermediate(window, stack_of_states, true));
	}

	if (buttonMap["Radix"]->isPressed())
	{
		file << "h";
		stack_of_states->push(new Intermediate(window, stack_of_states, true));
	}
}

void Sequential::renderButtons()
{
	for (auto& it : buttonMap)
	{
		it.second->render(window);
	}
}
