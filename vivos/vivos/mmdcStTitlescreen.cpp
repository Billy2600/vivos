#include "mmdcStTitlescreen.h"

void mmdcStTitlescreen::Start()
{
	
}

void mmdcStTitlescreen::Update(int dt, int input)
{
	if (input == INPUT_UP)
		pos.y -= 1 * dt;
	if (input == INPUT_DOWN)
		pos.y += 1 * dt;
	if (input == INPUT_RIGHT)
		pos.x += 1 * dt;
	if (input == INPUT_LEFT)
		pos.x -= 1 * dt;
}

void mmdcStTitlescreen::Draw(sf::RenderWindow &window)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(pos.x, pos.y));
	window.draw(shape);
}

void mmdcStTitlescreen::Stop()
{

}
