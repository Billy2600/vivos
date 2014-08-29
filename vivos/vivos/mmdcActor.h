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
	std::shared_ptr<drawable_t>		cmpSprite; // Sprite
	std::shared_ptr<rect_t<float>>	cmpHitbox; // Hitbox
	std::shared_ptr<physics_t>		cmpPhysics; // Physics information

public:

	// Get functions
	std::shared_ptr<drawable_t> GetSprite() { return cmpSprite; }
	std::shared_ptr<rect_t<float>> GetHitbox() { return cmpHitbox; }
	std::shared_ptr<physics_t> GetPhysics() { return cmpPhysics; }

	// Constructor
	mmdcActor(float x=0.f, float y=0.f)
	{
		// Init all components to null
		cmpSprite = NULL;
		cmpHitbox = NULL;
		cmpPhysics = NULL;
	}

	// Event responses

	// Input
	virtual void OnInput(inputs_t inputs) {}
	// Collision
	virtual void OnCollision(std::shared_ptr<mmdcActor>) { }

	// Think
	// Runs every frame
	virtual void Think(int dt) {}
};

