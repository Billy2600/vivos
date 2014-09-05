/* ============================================================
	Event Reader
	Defines a class that can read events, i.e. can accept them
	from the events class
	===========================================================*/
#pragma once
#include <memory>
#include <atomic>
#include "mmdcEventDataTypes.h"

class mmdcEventReader
{
protected:
	// Unique ID
	int aId;
	// Shared ID incrementor
	static std::atomic<int> sId;
	// Remove from world flag
	bool removeMe = false;

public:
	// Get functions

	// Get ID
	int GetID() const { return aId; }
	// Get remove flag
	bool GetRemove() const { return removeMe; }

	// Read event
	// Reads event an interpets it
	void ReadEvent(std::shared_ptr<event_t>);

	// Input
	virtual void OnInput(inputs_t inputs) {}
	// Collision
	virtual void OnCollision(std::shared_ptr<mmdcEventReader>) {}

	mmdcEventReader();
};

