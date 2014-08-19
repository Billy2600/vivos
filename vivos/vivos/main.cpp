#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include "mmdcGameState.h"
#include "mmdcStTitlescreen.h"
#include "mmdcInput.h"

// MAIN FUNCTION //
int main()
{
	// ====== //
	//  INIT  //
	// ====== //

	// Create window
	sf::RenderWindow window(sf::VideoMode(640, 480), "The Rich and the Dead");

	// Input class
	mmdcInput input;

	// Create and initialize game state (to title screen)
	mmdcGameState *currentState;
	currentState = new mmdcStTitlescreen();
	currentState->Start();

	// Game timing clock
	sf::Clock clock;
	clock.restart();
	int simulationTime = 0; // Simulation time (seperate from 'real' time)

	// ========= //
	// GAME LOOP //
	// ========= //
	while (window.isOpen())
	{
		// Get real time
		int realTime = clock.getElapsedTime().asMilliseconds();
		std::cout << realTime << std::endl << simulationTime;
		system("cls");

		// Handle events
		static bool focus = true; // Whether the window has focus or not

		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window
			if (event.type == sf::Event::Closed)
				window.close();
			// Gain/lose focus
			if (event.type == sf::Event::LostFocus)
				focus = false;
			if (event.type == sf::Event::GainedFocus)
				focus = true;
		}

		// Update at constant interval
		// Credits to Fabien Sanglard
		while (simulationTime < realTime)
		{
			simulationTime += 16;
			if (focus) // Don't update of window is not focused
				currentState->Update(16,input.ReadInput());
		}

		// Draw
		window.clear(sf::Color::Black); // Clear previous frame
		currentState->Draw(window); // Draw new frame
		window.display(); // Update window
	}

	// ======== //
	// CLEAN UP //
	// ======== //
	delete currentState;
	return 0;
}