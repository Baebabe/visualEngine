#include "CreateRectangle.h"
#include <chrono>


CreateRectangle::CreateRectangle()
{
}

void CreateRectangle::initialize(std::vector<int> &array)
{
	this->array = array;
	initRects();
}

void CreateRectangle::initRects()
{
	sf::Vector2f vect;
	vect.x = 5.f;
	for (int size : array)
	{
		vect.y = size * 10;
		bars.emplace_back(sf::RectangleShape(vect));
	}

	for (int i = 0; i < 50; i++)
	{
		bars[i].setFillColor(sf::Color::Blue);
		bars[i].setOrigin(sf::Vector2f(bars[i].getSize()));
		bars[i].setPosition(100 + i * 10, 800.f);
	}
}

void CreateRectangle::updateRect(int i, int j, std::vector<int> &array)
{
	//bars[i].setFillColor(sf::Color::Red);
	bars[i].setSize(sf::Vector2f(bars[i].getSize().x, 10 * array[i]));
	bars[j].setSize(sf::Vector2f(bars[j].getSize().x, 10 * array[j]));

	bars[i].setOrigin(sf::Vector2f(bars[i].getSize()));
	bars[i].setPosition(100 + i * 10, 800.f);

	bars[j].setOrigin(sf::Vector2f(bars[j].getSize()));
	bars[j].setPosition(100 + j * 10, 800.f);
}

void CreateRectangle::renderRectangle(sf::RenderWindow* window)
{
	for (const auto &it : bars)
	{
		window->draw(it);
	}
}
