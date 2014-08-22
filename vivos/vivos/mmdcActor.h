/* ============================================================
	Actor
	Super class for all the actors in the game
	Each actor has pointers to components it can have
	===========================================================*/
#pragma once
#include <memory>
#include <iostream>
#include "mmdcDataTypes.h"
#include "sigslot.h"

class mmdcActor :
	public sigslot::has_slots<>
{
private:

	// Components
	std::shared_ptr<drawable_t>		cmpSprite; // Sprite
	std::shared_ptr<rect_t<int>>	cmpHitbox; // Hitbox

public:

	// Get functions
	std::shared_ptr<drawable_t> GetSprite() { return cmpSprite; }
	std::shared_ptr<rect_t<int>> GetHitbox() { return cmpHitbox; }

	// Constructor
	mmdcActor()
	{
		// Init all components to null
		cmpSprite = NULL;
		cmpHitbox = NULL;
	}

	// Event responses
	void OnInput(inputs_t inputs, int dt)
	{
		std::cout << "Actor recived input" << std::endl;
	}
};

