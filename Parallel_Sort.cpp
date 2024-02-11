#include "Parallel_Sort.h"

Parallel_Sort::Parallel_Sort(sf::RenderWindow* window, std::stack<State*>* stack_of_states,
	std::vector<int>& array, CreateRectangle &rectBar)
	:State(window, stack_of_states)
{
	this->array = array;

	splitData();
	std::thread t(&Parallel_Sort::sortStart, this);

	t.detach();
}

void Parallel_Sort::update()
{
}

void Parallel_Sort::render()
{
	rectBar1[0].renderRectangle(window);
	rectBar1[1].renderRectangle(window);

	std::lock_guard<std::mutex> lock(mtx);
	rectBar.renderRectangle(window);
}

void Parallel_Sort::splitData()
{
	for (int i = 0; i < 25; i++)
	{
		array1[0].emplace_back(array[i]);
	}
	rectBar1[0].initialize(0, array1[0]);

	for (int i = 25; i < 50; i++)
	{
		array1[1].emplace_back(array[i]);
	}
	rectBar1[1].initialize(300, array1[1]);
}

void Parallel_Sort::sortStart()
{
	/*std::thread t1(&Parallel_Sort::bubbleSort, 0, array1, rectBar1);
	std::thread t2(&Parallel_Sort::bubbleSort, 300, array2, rectBar2);*/
	
	int pos1, pos2, ind1, ind2;
	pos1 = 0;
	pos2 = 300;
	ind1 = 0; 
	ind2 = 1;

	std::thread t1([this, pos1, ind1]()
		{
			Parallel_Sort::bubbleSort(pos1, ind1);
		});

	std::thread t2([this, pos2, ind2]()
		{
			Parallel_Sort::bubbleSort(pos2, ind2);
		});

	t1.join();
	t2.join();

	merge();
}

void Parallel_Sort::merge()
{
	auto it1 = array1[0].begin();
	auto it2 = array1[1].begin();

	int i = 0;

	array.clear();

	while ((it1 != array1[0].end()) && (it2 != array1[1].end()))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(60));
		std::lock_guard<std::mutex> lock(mtx);
		if (*it1 < *it2)
		{
			array.push_back(*it1);
			rectBar.justOne(array.back(), i);
			it1++;
		}
		else if (*it1 > *it2)
		{
			array.push_back(*it2);
			rectBar.justOne(array.back(), i);
			it2++;
		}
		else
		{
			array.push_back(*it1);
			array.push_back(*it2);
			rectBar.justOne(array.back(), i);
			i++;
			rectBar.justOne(array.back(), i);
			it1++;
			it2++;
		}
		i++;
	}

	while (it1 != array1[0].end())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(60));
		std::lock_guard<std::mutex> lock(mtx);
		array.push_back(*it1);
		rectBar.justOne(array.back(), i);
		i++;
		it1++;
	}
	
	while (it2 != array1[1].end())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(60));
		std::lock_guard<std::mutex> lock(mtx);
		array.push_back(*it2);
		rectBar.justOne(array.back(), i);
		i++;
		it2++;
	}
}

void Parallel_Sort::initArray()
{
}

void Parallel_Sort::bubbleSort(int pos, int ind)
{
	int n = array1[ind].size();
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			if (array1[ind][j] > array1[ind][j + 1])
			{
				std::swap(array1[ind][j], array1[ind][j + 1]);
				rectBar1[ind].updateRect(pos, j, j + 1, array1[ind]);
			}
		}
	}
}

void Parallel_Sort::initButtons()
{
}

void Parallel_Sort::updateButtons()
{
}

void Parallel_Sort::renderButtons()
{
}
