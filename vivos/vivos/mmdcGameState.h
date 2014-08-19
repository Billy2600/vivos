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
	virtual void Start() = 0;

	// UPDATE
	// For game logic; Run every frame
	// dt stands for Delta Time
	virtual void Update(int dt) = 0;

	// DRAW
	// For drawing things out to the screen; Runs every frame after update
	// Draws to window by reference
	virtual void Draw(sf::RenderWindow &window) = 0;

	// STOP
	// Runs after you change game state or close the program
	virtual void Stop() = 0;
};

