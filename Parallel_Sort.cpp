#include "Parallel_Sort.h"

Parallel_Sort::Parallel_Sort(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* stack_of_states,
	std::vector<int>& array, CreateRectangle &rectBar, int speed,  char whichSort)
	:State(window, stack_of_states)
{
	this->whichSort = whichSort;
	this->array = array;
	this->speed = speed;

	sf::Font font;
	font.loadFromFile("Fonts/bauhs93.ttf");

	infoText.setFont(font);
	infoText.setCharacterSize(16);
	infoText.setFillColor(sf::Color::White);
	infoText.setString("Sorting completed in + Number of swaps: ");
	infoText.setPosition(10, 950);

	splitData();
	std::thread t(&Parallel_Sort::sortStart, this);
	initButtons();
	t.detach();
}

void Parallel_Sort::update()
{
	updateMousePosition();
	if (finished)
	{
		updateButtons();
	}
}

void Parallel_Sort::render()
{
	rectBar1[0].renderRectangle(window);
	rectBar1[1].renderRectangle(window);

	std::lock_guard<std::mutex> lock(mtx);
	rectBar.renderRectangle(window);
	if (finished)
	{
	window->draw(infoText);	
	renderButtons();
	}
}

void Parallel_Sort::splitData()
{
	for (int i = 0; i < array.size()/2; i++)
	{
		array1[0].emplace_back(array[i]);
	}
	rectBar1[0].initialize(0, array1[0]);

	for (int i = array.size()/2; i < array.size(); i++)
	{
		array1[1].emplace_back(array[i]);
	}
	rectBar1[1].initialize(500, array1[1]);
}

void Parallel_Sort::sortStart()
{
	/*std::thread t1(&Parallel_Sort::bubbleSort, 0, array1, rectBar1);
	std::thread t2(&Parallel_Sort::bubbleSort, 300, array2, rectBar2);*/
	auto start = std::chrono::high_resolution_clock::now();

	int pos1 = 0, pos2 = 500, ind1 = 0, ind2 = 1;

	if (whichSort == 'b') {
		std::thread t1([this, pos1, ind1]() {
			Parallel_Sort::bubbleSort(pos1, ind1);
			});

		std::thread t2([this, pos2, ind2]() {
			Parallel_Sort::bubbleSort(pos2, ind2);
			});

		t1.join();
		t2.join();
	}
	else if (whichSort == 'm') {
		std::thread t1([this, pos1, ind1]() {
			Parallel_Sort::mergeSort(pos1, ind1);
			});

		std::thread t2([this, pos2, ind2]() {
			Parallel_Sort::mergeSort(pos2, ind2);
			});

		t1.join();
		t2.join();
	}
	else if (whichSort == 's') {
		std::thread t1([this, pos1, ind1]() {
			Parallel_Sort::selectionSort(pos1, ind1);
			});

		std::thread t2([this, pos2, ind2]() {
			Parallel_Sort::selectionSort(pos2, ind2);
			});

		t1.join();
		t2.join();
	}


	merge();
	int swaps = 10;
	auto end = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double> duration = end - start;

	this->duration = std::to_string(duration.count());

	sf::Font font;
	font.loadFromFile("Fonts/bauhs93.ttf");
	
	infoText.setFont(font);
	infoText.setCharacterSize(16);
	infoText.setFillColor(sf::Color::White);
	infoText.setString("Sorting completed in " + std::to_string(duration.count()) +
		" seconds\n"
		+ "Number of swaps: " + std::to_string(swaps));
	infoText.setPosition(10, 950);	
}

void Parallel_Sort::merge()
{
	auto it1 = array1[0].begin();
	auto it2 = array1[1].begin();

	int i = 0;

	array.clear();

	while ((it1 != array1[0].end()) && (it2 != array1[1].end()))
	{
		std::this_thread::sleep_for(std::chrono::microseconds(speed));
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
		std::this_thread::sleep_for(std::chrono::microseconds(speed));
		std::lock_guard<std::mutex> lock(mtx);
		array.push_back(*it1);
		rectBar.justOne(array.back(), i);
		i++;
		it1++;
	}
	
	while (it2 != array1[1].end())
	{
		std::this_thread::sleep_for(std::chrono::microseconds(speed));
		std::lock_guard<std::mutex> lock(mtx);
		array.push_back(*it2);
		rectBar.justOne(array.back(), i);
		i++;
		it2++;
	}
	finished = true;
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
			std::this_thread::sleep_for(std::chrono::microseconds(speed/3));
			if (array1[ind][j] > array1[ind][j + 1])
			{
				std::swap(array1[ind][j], array1[ind][j + 1]);
				rectBar1[ind].updateRect(pos, j, j + 1, array1[ind]);
			}
		}
	}
}
void Parallel_Sort::selectionSort(int pos, int ind)
{
	int n = array1[ind].size();
	for (int i = 0; i < n - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(speed / 3));
			if (array1[ind][j] < array1[ind][minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(array1[ind][i], array1[ind][minIndex]);
			rectBar1[ind].updateRect(pos, i, minIndex, array1[ind]);
		}
	}
}

void Parallel_Sort::mergeSort(int pos, int ind)
{
	mergeSortHelper(array1[ind], 0, array1[ind].size() - 1, ind, pos);
}

void Parallel_Sort::mergeSortHelper(std::vector<int>& arr, int l, int r, int ind, int pos)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortHelper(arr, l, m, ind, pos);
		mergeSortHelper(arr, m + 1, r, ind, pos);

		mergee(arr, l, m, r, ind, pos);
	}
}

void Parallel_Sort::mergee(std::vector<int>& arr, int l, int m, int r, int ind, int pos)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; ++j)
		R[j] = arr[m + 1 + j];

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		std::this_thread::sleep_for(std::chrono::microseconds(speed / 3));
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			++i;
		}
		else {
			arr[k] = R[j];
			++j;
		}
		++k;

		// Visualization update
		std::lock_guard<std::mutex> lock(mtx);
		rectBar1[ind].updateRect(pos, l + i - 1, m + j, arr); // Pass the indices of the elements just swapped
	}

	while (i < n1) {
		std::this_thread::sleep_for(std::chrono::microseconds(speed / 3));
		arr[k] = L[i];
		++i;
		++k;

		// Visualization update
		std::lock_guard<std::mutex> lock(mtx);
		rectBar1[ind].updateRect(pos, l + i - 1, k - 1, arr); // Pass the indices of the elements just swapped
	}

	while (j < n2) {
		std::this_thread::sleep_for(std::chrono::microseconds(speed / 3));
		arr[k] = R[j];
		++j;
		++k;

		// Visualization update
		std::lock_guard<std::mutex> lock(mtx);
		rectBar1[ind].updateRect(pos, m + j - 1, k - 1, arr); // Pass the indices of the elements just swapped
	}
}


void Parallel_Sort::initButtons()
{
	buttonMap["Exit"] = new Button(40.f, 200.f, 1800.f, 470.f,
		"Exit", sf::Color(100, 100, 100, 100), sf::Color(150, 150, 150, 150));
}

void Parallel_Sort::updateButtons()
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

void Parallel_Sort::renderButtons()
{
		for (auto& it : buttonMap)
		{
			it.second->render(window);
		}
}
