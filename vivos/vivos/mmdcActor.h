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
protected:

	// Components
	vec2_t<float>					pos; // World position
	std::shared_ptr<drawable_t>		cmpSprite; // Sprite
	std::shared_ptr<rect_t<int>>	cmpHitbox; // Hitbox

public:

	// Get functions
	vec2_t<float> GetPos() { return pos; }
	std::shared_ptr<drawable_t> GetSprite() { return cmpSprite; }
	std::shared_ptr<rect_t<int>> GetHitbox() { return cmpHitbox; }

	// Constructor
	mmdcActor(float x=0.f, float y=0.f)
	{
		// Set position
		pos.x = x;
		pos.y = y;
		// Init all components to null
		cmpSprite = NULL;
		cmpHitbox = NULL;
	}

	// Event responses

	// Input
	virtual void OnInput(inputs_t inputs, int dt) {}
	// Collision
	virtual void OnCollision(mmdcActor *) { }

	// Think
	// Runs every frame
	virtual void Think(int dt) {}
};

