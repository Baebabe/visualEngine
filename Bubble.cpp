#include "Bubble.h"

Bubble::Bubble(sf::RenderWindow* window, std::stack<State*>* stack_of_states)
	: State(window, stack_of_states)
{
	initArray();
	rectBar.initialize(array);

	std::thread t(&Bubble::sort, this);
	t.detach();
}

void Bubble::update()
{
	
}

void Bubble::render()
{
	rectBar.renderRectangle(window);
}

void Bubble::initArray()
{
	std::random_device rd;
	std::default_random_engine engine{rd()};
	std::uniform_int_distribution<int> ints{1, 50};
	
	for (int i = 0; i < 50; i++)
	{
		array.emplace_back(ints(engine));
	}
}

void Bubble::sort()
{
	int n = array.size();
	for (int i = 0; i < n - 1; ++i) 	
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			if (array[j] > array[j + 1]) 
			{
				std::swap(array[j], array[j + 1]);
				rectBar.updateRect(j, j+1, array);
			}
		}
	}
}

void Bubble::initButtons()
{
}

void Bubble::updateButtons()
{
}

void Bubble::renderButtons()
{
}
