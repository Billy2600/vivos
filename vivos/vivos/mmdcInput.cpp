#include "mmdcInput.h"


mmdcInput::mmdcInput()
{
}

int mmdcInput::ReadInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		return INPUT_UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		return INPUT_DOWN;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return INPUT_LEFT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return INPUT_RIGHT;

	return 0;
}
