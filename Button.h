#pragma once
#include<iostream>
#include<fstream>
#include"SFML/window.hpp"
#include"SFML/graphics.hpp"
#include"SFML/audio.hpp"

enum button_state { IDLE = 0, HOVER, PRESSED };

class Button
{
public:
	Button(float, float, float x, float y, std::string, sf::Color, sf::Color);
	void update(sf::Vector2f);
	void render(sf::RenderWindow *);

	//return function
	const bool isPressed() const;

private:
	//initializer functions
	void initButtonDimen(float&, float&, float&, float&);
	void initButtonText( std::string&);
	//data members
	sf::RectangleShape rectangle;
	short unsigned buttonState;
	sf::Color idle_color, hover_color;
	sf::Font font;
	sf::Text text;
	sf::SoundBuffer hsound, csound;
	sf::Sound sound;
};
