#include "mmdcStTitlescreen.h"

void mmdcStTitlescreen::Start()
{
	
}

void mmdcStTitlescreen::Update(int dt, inputs_t inputs)
{
	float s = 0.5f;
	if (inputs.up == true)
		pos.y -= s * dt;
	if (inputs.down == true)
		pos.y += s * dt;
	if (inputs.right == true)
		pos.x += s * dt;
	if (inputs.left == true)
		pos.x -= s * dt;
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
