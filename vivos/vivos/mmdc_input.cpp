#include "mmdc_input.h"


mmdcInput::mmdcInput()
{
}

inputs_t mmdcInput::ReadInput()
{
	inputs_t inputs;
	// Init all inputs to false
	inputs.accept = false;
	inputs.up = false; inputs.down = false; inputs.left = false; inputs.right = false;
	inputs.rUp = false; inputs.rDown = false; inputs.rLeft = false; inputs.rRight = false;

	// Check for inputs
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		inputs.accept = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		inputs.up = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		inputs.down = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		inputs.left = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		inputs.right = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		inputs.rUp = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		inputs.rDown = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		inputs.rLeft = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		inputs.rRight = true;

	// return struct
	return inputs;
}
