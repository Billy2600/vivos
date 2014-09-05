#include "mmdcStGameplay.h"

void mmdcStGameplay::Start()
{
	events.SetActorList(&actors);
	actors.push_back(std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(0, 0)));
	actors.push_back(std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(100, -100)));
}

void mmdcStGameplay::Update(int dt, inputs_t inputs)
{
	// Send input event
	/*std::shared_ptr<ev_input_t> evInput = std::shared_ptr<ev_input_t>(new ev_input_t());
	evInput->targetId = 1;
	evInput->inputs = inputs;*/
	//mmdcActorEvents::AddEvent(evInput);

	actors[0]->OnInput(inputs);

	// Dispatch events
	events.DispatchEvents();

	// Make objects think
	for (unsigned int i = 0; i < actors.size(); i++)
	{
		std::shared_ptr<mmdcActor> curActor = std::dynamic_pointer_cast<mmdcActor>(actors[i]);
		curActor->Think(dt);

		bool b = TryMove(0, curActor->newPos.x, curActor->newPos.y);
		if (!b) b = TryMove(0, curActor->newPos.x, curActor->GetHitbox()->y);
		if (!b) b = TryMove(0, curActor->GetHitbox()->x, curActor->newPos.y);
	}

	// Remove objects
	RemoveActors();
}

std::vector<drawable_t> mmdcStGameplay::Draw() const
{
	// Add drawable objects to a list
	std::vector<drawable_t> drawObjs;
	for (unsigned int i = 0; i < actors.size(); i++)
	{
		std::shared_ptr<mmdcActor> curActor = std::dynamic_pointer_cast<mmdcActor>(actors[i]);
		if (curActor->GetSprite() != NULL)
			drawObjs.push_back(*curActor->GetSprite());
		if (curActor->GetHitbox() != NULL)
		{
			drawable_t hitbox;
			hitbox.pos.x = curActor->GetHitbox()->x;
			hitbox.pos.y = curActor->GetHitbox()->y;
			hitbox.texPosition = rect_t<int>(150, 150, curActor->GetHitbox()->w, curActor->GetHitbox()->h);
			hitbox.fillColor = color_t(0, 255, 0, 100);
			drawObjs.push_back(hitbox);
		}
	}
	
	// Return list
	return drawObjs;
}

void mmdcStGameplay::Stop()
{

}
