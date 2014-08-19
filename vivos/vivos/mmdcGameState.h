/* ============================================================
	GameState
	Super class for all the states in the game
	Classes derived from this one should have St before their name
	===========================================================*/
#pragma once
#include <SFML/Graphics.hpp>

class mmdcGameState
{
public:

	// Change state variables
	int changeTo; // State we want to change to
	bool change; // Change state flag
	bool pause; // Pause logic

	// Constructor
	mmdcGameState()
	{
		change = false;
		pause = false;
	}

	// START
	// Everything you need to do before you get going
	// We give it the window so it can make adjustments to it
	virtual void Start() = 0;

	// UPDATE
	// For game logic
	// Run every frame
	virtual void Update() = 0;

	// DRAW
	// For drawing things out to the screen
	// Runs every frame after update
	virtual void Draw(sf::RenderWindow &window) = 0;

	// STOP
	// Runs after you change game state or close the program
	virtual void Stop() = 0;
};

