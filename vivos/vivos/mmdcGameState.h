/* ============================================================
	GameState
	Super class for all the states in the game
	Classes derived from this one should have St before their name
	===========================================================*/
#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include "mmdcDataTypes.h"
#include "mmdcActPlayer.h"

class mmdcGameState
{
protected:
	// Change state variables
	states_t changeTo; // State we want to change to
	bool change; // Change state flag
	bool pause; // Pause logic
	std::vector < std::shared_ptr<mmdcActor> >	actors; // Actor list

public:

	// Constructor
	mmdcGameState()
	{
		change = false;
		pause = false;
	}

	// Get change flag
	bool GetChange() const { return change; }
	// Get state we want to change to
	states_t GetChangeTo() const { return changeTo; }
	// Get pause state
	bool GetPause() const { return pause; }
	// Set pause
	void SetPause(bool pause) { this->pause = pause; }

	// START
	// Everything you need to do before you get going
	// Must be passed input queue
	virtual void Start() = 0;

	// UPDATE
	// For game logic; Run every frame
	// dt stands for Delta Time
	// Recieves input from the Input class
	virtual void Update(int dt, inputs_t inputs) = 0;

	// DRAW
	// For drawing things out to the screen; Runs every frame after update
	// Returns array of drawable objects for the Render class to use
	virtual std::vector<drawable_t> Draw() const = 0;

	// STOP
	// Runs after you change game state or close the program
	virtual void Stop() = 0;

	// TRY MOVE
	// Actor broadcasts where it'd like to move, this function checks if its a valid move
	// and if it is, moves it.
	bool TryMove(int index, float x, float y);
};

