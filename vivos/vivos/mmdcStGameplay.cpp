#include "mmdcStGameplay.h"

void mmdcStGameplay::Start()
{
	player = std::shared_ptr<mmdcActPlayer>(new mmdcActPlayer(0,0));
	testSig.connect(&*player, &mmdcActPlayer::OnInput);
}

void mmdcStGameplay::Update(int dt, inputs_t inputs)
{
	// Broadcast input
	testSig.emit(inputs, dt);

	// Make objects think
	player->Think(dt);
}

std::vector<drawable_t> mmdcStGameplay::Draw() const
{
	// Add drawable objects to list
	std::vector<drawable_t> objects;
	objects.push_back(*player->GetSprite());
	// Return list
	return objects;
}

void mmdcStGameplay::Stop()
{

}
