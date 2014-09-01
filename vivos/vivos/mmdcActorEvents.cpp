#include "mmdcActorEvents.h"


mmdcActorEvents::mmdcActorEvents()
{
}

void mmdcActorEvents::SetActorList(std::vector<std::shared_ptr<mmdcActor>> *actors)
{
	this->actors = actors;
}

void mmdcActorEvents::AddEvent(std::shared_ptr<event_t> inEvent)
{
	// Add this event to the queue
	qEvent.push(inEvent);
}

void mmdcActorEvents::DispatchEvents()
{
	for (int i = 0; i < qEvent.size(); i++)
	{
		// Find actor with ID we want
		int actorPos = -1; // Actor position in vector 
		for (int j = 0; j < actors->size(); i++)
		{
			if (actors[0][i]->GetID() == qEvent.back()->targetId)
			{
				actorPos = i;
				break;
			}
		}
		// Did we find it?
		if (actorPos == -1)
			return; // Not found

		// Found it, let's give it the event
		actors[0][actorPos]->ReadEvent(qEvent.back());
		// Get rid of the event
		qEvent.pop();
	}
}