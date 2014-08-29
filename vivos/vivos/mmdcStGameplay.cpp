#include "mmdcStGameplay.h"

void mmdcStGameplay::Start()
{
	player = std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(0, 0));
	player2 = std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(30, -30));
	events.Register(EV_INPUT, &*player);
}

void mmdcStGameplay::Update(int dt, inputs_t inputs)
{
	// Send input event
	events.SendInput(inputs, dt);

	// Make objects think
	player->Think(dt);
	player2->Think(dt);

	if(player->GetHitbox()->Collision(*player->GetHitbox(), *player2->GetHitbox()))
		std::cout << "Collision!" << std::endl;
}

std::vector<drawable_t> mmdcStGameplay::Draw() const
{
	// Add drawable objects to a list
	std::vector<drawable_t> drawObjs;
	drawObjs.push_back(*player->GetSprite());
	drawObjs.push_back(*player2->GetSprite());
	// Return list
	return drawObjs;
}

void mmdcStGameplay::Stop()
{

}
