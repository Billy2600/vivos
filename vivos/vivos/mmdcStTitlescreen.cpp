#include "mmdcStTitlescreen.h"

void mmdcStTitlescreen::Start()
{

}

void mmdcStTitlescreen::Update()
{

}

void mmdcStTitlescreen::Draw(sf::RenderWindow &window)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
}

void mmdcStTitlescreen::Stop()
{

}
