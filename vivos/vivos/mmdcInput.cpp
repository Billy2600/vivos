#include "mmdcInput.h"


mmdcInput::mmdcInput()
{
}

inputs_t mmdcInput::ReadInput()
{
	inputs_t inputs;
	// Init all inputs to false
	inputs.up = false; inputs.down = false; inputs.left = false; inputs.right = false;

	// Check for inputs
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		inputs.up = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		inputs.down = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		inputs.left = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		inputs.right = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		inputs.accept = true;

	// return struct
	return inputs;
}
