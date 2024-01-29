#include "Button.h"


Button::Button(float w, float h, float x, float y, std::string buttonText, 
	sf::Color idle_color, sf::Color hover_color)
{
	
	initButtonDimen(w, h, x, y);			//initialize button dimension
	initButtonText(buttonText);				//initialize button text
	
	this->idle_color = idle_color;
	this->hover_color = hover_color;

	rectangle.setFillColor(idle_color);
	buttonState = IDLE;

	hsound.loadFromFile("Sounds/hover.mp3");
	csound.loadFromFile("Sounds/click.mp3");
	sound.setBuffer(hsound);
	sound.setVolume(50.f);
}

void Button::update(sf::Vector2f mousePosView)
{
	buttonState = IDLE;
	if (rectangle.getGlobalBounds().contains(mousePosView))
	{
		buttonState = HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = PRESSED;
		}
		sound.play();
	}

	switch (buttonState)
	{
	case IDLE:
		rectangle.setFillColor(idle_color);
		text.setFillColor(sf::Color::White);
		break;

	case HOVER:
		rectangle.setFillColor(hover_color);
		text.setFillColor(sf::Color(128, 128, 128, 128));
		break;

	case PRESSED:
		rectangle.setFillColor(sf::Color::Yellow);
		text.setFillColor(sf::Color::Magenta);
		break;
	}
}

void Button::render(sf::RenderWindow * window)
{
	window->draw(rectangle);
	window->draw(text);
}

const bool Button::isPressed() const
{
	return buttonState == PRESSED;
}

void Button::initButtonDimen(float& h, float& w, float& x, float& y)
{
	//dimension of button
	sf::Vector2f vect(w, h);
	rectangle.setSize(vect);

	//origin of the rectangle shape
	rectangle.setOrigin(vect.x / 2.f, vect.y / 2.f);

	//position of button
	vect.x = x;
	vect.y = y;
	rectangle.setPosition(vect);
}

void Button::initButtonText(std::string& buttonText)
{
	if (!font.loadFromFile("Fonts/bauhs93.ttf"))
	{
		std::cout << "Error";
	}
	//button Text and fonts;
	text.setString(buttonText);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	//Set the origin of text to its centre
	sf::FloatRect rect = text.getLocalBounds();
	text.setOrigin((rect.left + rect.width) / 2.f, (rect.top + rect.height) / 2.f);
	//set the position of the text on the rectangle
	sf::Vector2f vect = rectangle.getPosition();
	text.setPosition(vect);
}
