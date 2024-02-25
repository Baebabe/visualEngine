#include "Sort.h"

Sort::Sort(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* stack_of_states,
	std::vector<int>& array, CreateRectangle& rectBar)
	: State(window, stack_of_states)
{

	this->array = array;
	this->rectBar = rectBar;

	std::thread t(&Sort::bubbleSort, this);
	t.detach();
}

void Sort::update()
{
	
}

void Sort::render()
{
	rectBar.renderRectangle(window);
}

void Sort::initArray()
{
	std::random_device rd;
	std::default_random_engine engine{rd()};
	std::uniform_int_distribution<int> ints{1, 50};
	
	for (int i = 0; i < 50; i++)
	{
		array.emplace_back(ints(engine));
	}
}

void Sort::bubbleSort()
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
				rectBar.updateRect(0, j, j+1, array);
			}
		}
	}
	//this->stack_of_states->pop();
}

void Sort::initButtons()
{
}

void Sort::updateButtons()
{
}

void Sort::renderButtons()
{
}
