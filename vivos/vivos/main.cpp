#include <SFML/Graphics.hpp>
#include <memory>
#include "mmdcGameState.h"
#include "mmdcStTitlescreen.h"

// MAIN FUNCTION //
int main()
{
	// Create window
	sf::RenderWindow window(sf::VideoMode(640, 480), "The Rich and the Dead");

	// Create and initialize game state (to title screen)
	mmdcGameState *currentState;
	currentState = new mmdcStTitlescreen();
	currentState->Start();

	// GAME LOOP //
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Update
		currentState->Update();

		// Draw
		window.clear(sf::Color::Black);
		currentState->Draw(window);
		window.display();
	}

	// Clean up
	delete currentState;
	return 0;
}