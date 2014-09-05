/* ============================================================
	Actor
	Super class for all the actors in the game
	Each actor has pointers to components it can have
	===========================================================*/
#pragma once
#include <memory>
#include <iostream>
#include "mmdcEventReader.h"
#include "mmdcActorEvents.h"

class mmdcActor 
	: public mmdcEventReader
{
protected:
	// Components
	std::shared_ptr<drawable_t>		cmpSprite; // Sprite
	std::shared_ptr<rect_t<float>>	cmpHitbox; // Hitbox

public:
	vec2_t<float>  newPos; // New position

	// Get functions
	std::shared_ptr<drawable_t> GetSprite() const { return cmpSprite; }
	std::shared_ptr<rect_t<float>> GetHitbox() const { return cmpHitbox; }

	// Constructor
	mmdcActor(float x=0.f, float y=0.f)
	{
		// Init all components to null
		cmpSprite = NULL;
		cmpHitbox = NULL;
	}

	// Think
	// Runs every frame
	virtual void Think(int dt) {}

	// Non-virtual functions

	// Move the object
	// Sets the position of the object
	void Move(float x, float y);
};

