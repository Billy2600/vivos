/* ============================================================
	Actor Events
	Event handler for actors
	An actor will register with this event, then it will broadcast
	those events to it when they happen
	===========================================================*/
#pragma once
#include "mmdcActor.h"
#include "sigslot.h"

class mmdcActorEvents
{
private:
	// Signals for types of events
	sigslot::signal2<inputs_t, int>		input;

public:
	mmdcActorEvents(void);
	
	// Register with system
	// Must give event type, and pointer to actor
	void Register(act_event_t, mmdcActor*);

	// Send input event
	void SendInput(inputs_t, int);
};

