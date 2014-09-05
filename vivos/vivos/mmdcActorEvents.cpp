#include "mmdcActorEvents.h"

std::queue<std::shared_ptr<event_t>> mmdcActorEvents::qEvent = std::queue<std::shared_ptr<event_t>>();

mmdcActorEvents::mmdcActorEvents()
{
}

void mmdcActorEvents::SetActorList(std::vector<std::shared_ptr<mmdcEventReader>> *actors)
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
			if (actors[j][0]->GetID() == qEvent.back()->targetId)
			{
				actorPos = j;
				break;
			}
		}
		// Did we find it?
		if (actorPos == -1)
		{
			// Not found
			return;
			qEvent.pop();
		}

		// Found it, let's give it the event
		actors[actorPos][0]->ReadEvent(qEvent.back());
		// Get rid of the event
		qEvent.pop();
	}
}