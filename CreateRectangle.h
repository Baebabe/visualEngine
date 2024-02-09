#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <thread>

class CreateRectangle
{
public:
	CreateRectangle();
	void initialize(std::vector<int> &);
	void initRects();
	void updateRect(int, int, std::vector<int>&);
	void renderRectangle(sf::RenderWindow *);
	void justSize(std::vector<int>&);


private:
	std::vector<sf::RectangleShape> bars;
	std::vector<int> array;
};

