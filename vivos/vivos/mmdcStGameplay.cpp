#include "mmdcStGameplay.h"

void mmdcStGameplay::Start()
{
	actors.push_back(std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(0, 0)));
	actors.push_back(std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(100, -100)));
}

void mmdcStGameplay::Update(int dt, inputs_t inputs)
{
	// Send inputs
	actors[0]->OnInput(inputs);

	// Make objects think
	for (unsigned int i = 0; i < actors.size(); i++)
	{
		actors[i]->Think(dt);
	}

	bool b = TryMove(0, actors[0]->newPos.x, actors[0]->newPos.y);
	if (!b) b = TryMove(0, actors[0]->newPos.x, actors[0]->GetHitbox()->y);
	if (!b) b = TryMove(0, actors[0]->GetHitbox()->x, actors[0]->newPos.y);
}

std::vector<drawable_t> mmdcStGameplay::Draw() const
{
	// Add drawable objects to a list
	std::vector<drawable_t> drawObjs;
	for (unsigned int i = 0; i < actors.size(); i++)
	{
		if (actors[i]->GetSprite() != NULL)
			drawObjs.push_back(*actors[i]->GetSprite());
	}
	
	// Return list
	return drawObjs;
}

void mmdcStGameplay::Stop()
{

}
