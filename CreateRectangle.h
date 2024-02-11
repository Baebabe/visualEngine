#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <thread>

class CreateRectangle
{
public:
	CreateRectangle();
	void initialize(int,std::vector<int> &);
	void initRects(int);
	void updateRect(int, int, int, std::vector<int>&);
	void renderRectangle(sf::RenderWindow *);
	void justSize(int, std::vector<int>&);

	void justOne(int, int);

private:
	std::vector<sf::RectangleShape> bars;
	std::vector<int> array;
};

