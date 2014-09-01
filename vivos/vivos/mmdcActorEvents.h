/* ============================================================
	Actor Events
	Event handler for actors
	An actor will register with this event, then it will broadcast
	those events to it when they happen
	===========================================================*/
#pragma once
#include <queue>
#include <memory> 
#include "mmdcActor.h"
#include "mmdcEventDataTypes.h"

class mmdcActorEvents
{
private:
	// Event queue
	std::queue<std::shared_ptr<event_t>>		 qEvent;
	// Pointer to actor vector
	std::vector<std::shared_ptr<mmdcActor>>		 *actors;

public:
	mmdcActorEvents();

	// Give us actor list
	void SetActorList(std::vector<std::shared_ptr<mmdcActor>>*);

	// Add event
	void AddEvent(std::shared_ptr<event_t>);

	// Dispatch events
	// Sends events out to their targets
	void DispatchEvents();
};

