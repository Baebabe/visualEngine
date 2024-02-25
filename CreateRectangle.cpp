#include "CreateRectangle.h"
#include <chrono>


CreateRectangle::CreateRectangle()
{
}

void CreateRectangle::initialize(int pos, std::vector<int> &array)
{
	this->array = array;
	initRects(pos);
}

void CreateRectangle::initRects(int pos)
{
	sf::Vector2f vect;
	vect.x = 5.f;
	for (int size : array)
	{
		vect.y = size * 10;
		bars.emplace_back(sf::RectangleShape(vect));
	}

	for (int i = 0; i < array.size() ; i++)
	{
		bars[i].setFillColor(sf::Color::Blue);
		bars[i].setOrigin(sf::Vector2f(bars[i].getSize()));
		bars[i].setPosition(pos + 100 + i * 10, 800.f);
	}
}

void CreateRectangle::justSize(int pos, std::vector<int>& array)
{
	for (int i = 0; i < array.size() ; i++)
	{
		bars[i].setSize(sf::Vector2f(5.f, 10 * array[i]));
		bars[i].setOrigin(sf::Vector2f(bars[i].getSize()));
		bars[i].setPosition(pos + 100 + i * 10, 800.f);
	}
}

void CreateRectangle::justOne(int size, int ind)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(5.f, 10 * size));
	rect.setOrigin(sf::Vector2f(rect.getSize()));
	rect.setPosition(800 + ind * 10, 800.f);

	bars.push_back(rect);
}

void CreateRectangle::updateRect(int pos, int i, int j, std::vector<int> &array)
{
	//bars[i].setFillColor(sf::Color::Red);
	for (auto& it : bars)
	{
		it.setFillColor(sf::Color::Blue);
	}
	bars[i].setSize(sf::Vector2f(bars[i].getSize().x, 10 * array[i]));
	bars[j].setSize(sf::Vector2f(bars[j].getSize().x, 10 * array[j]));

	bars[i].setOrigin(sf::Vector2f(bars[i].getSize()));
	bars[i].setPosition(pos + 100 + i * 10, 800.f);

	bars[j].setOrigin(sf::Vector2f(bars[j].getSize()));
	bars[j].setPosition(pos + 100 + j * 10, 800.f);

	bars[i].setFillColor(sf::Color::Red);
	bars[j].setFillColor(sf::Color::Red);
}

void CreateRectangle::renderRectangle(sf::RenderWindow* window)
{
	if (!bars.empty())
	{
		for (const auto& it : bars)
		{
			window->draw(it);
		}
	}
}



