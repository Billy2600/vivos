/* ============================================================
	Actor
	Super class for all the actors in the game
	Each actor has pointers to components it can have
	===========================================================*/
#pragma once
#include <memory>
#include <iostream>
#include <atomic>
#include "mmdc_data_types.h"

class mmdcActor 
{
protected:
	// Unique ID
	int aId;
	// Shared ID incrementor
	static std::atomic<int> sId;
	
	// Components
	std::shared_ptr<drawable_t>		cmpSprite; // Sprite
	std::shared_ptr<rect_t<float>>	cmpHitbox; // Hitbox

public:
	vec2_t<float>  newPos; // New position

	// Get functions
	int GetID() const { return aId; }
	std::shared_ptr<drawable_t> GetSprite() const { return cmpSprite; }
	std::shared_ptr<rect_t<float>> GetHitbox() const { return cmpHitbox; }

	// Constructor
	mmdcActor(float x=0.f, float y=0.f)
	{
		// Set ID
		aId = sId++;
		// Init all components to null
		cmpSprite = NULL;
		cmpHitbox = NULL;
	}

	// Event responses

	// Input
	virtual void OnInput(inputs_t inputs) {}
	// Collision
	virtual void OnCollision(std::shared_ptr<mmdcActor>) { }

	// Think
	// Runs every frame
	virtual void Think(int dt) {}

	// Non-virtual functions

	// Move the object
	// Sets the position of the object
	void Move(float x, float y);
};

