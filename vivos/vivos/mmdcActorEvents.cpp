#include "mmdcActorEvents.h"


mmdcActorEvents::mmdcActorEvents(void)
{
}


void mmdcActorEvents::Register(act_event_t eventType, mmdcActor *actor)
{
	// Register to signal matching event type
	switch(eventType)
	{
	case EV_INPUT:
		input.connect(&*actor, &mmdcActor::OnInput);
		break;
	}
}

void mmdcActorEvents::SendInput(inputs_t inputs, int dt)
{
	input.emit(inputs, dt);
}