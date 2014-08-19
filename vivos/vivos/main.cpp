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

	// Game timing clock
	sf::Clock clock;
	clock.restart();
	int simulationTime = 0; // Simulation time (seperate from 'real' time)

	// GAME LOOP //
	while (window.isOpen())
	{
		// Get real time
		int realTime = clock.getElapsedTime().asMilliseconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Update at constant interval
		// Credits to Fabien Sanglard
		while (simulationTime < realTime)
		{
			simulationTime += 16;
			currentState->Update(16);
		}
		

		// Draw
		window.clear(sf::Color::Black);
		currentState->Draw(window);
		window.display();
	}

	// Clean up
	delete currentState;
	return 0;
}