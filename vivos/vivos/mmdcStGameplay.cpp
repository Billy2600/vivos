#include "mmdcStGameplay.h"

void mmdcStGameplay::Start()
{
	objects.push_back(std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(0, 0)));
	objects.push_back(std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(100, -100)));
	events.Register(EV_INPUT, &*objects[0]);
}

void mmdcStGameplay::Update(int dt, inputs_t inputs)
{
	// Send input event
	events.SendInput(inputs);

	// Make objects think
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i]->Think(dt);
	}
}

std::vector<drawable_t> mmdcStGameplay::Draw() const
{
	// Add drawable objects to a list
	std::vector<drawable_t> drawObjs;
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->GetSprite() != NULL)
			drawObjs.push_back(*objects[i]->GetSprite());
	}
	// Return list
	return drawObjs;
}

void mmdcStGameplay::Stop()
{

}
