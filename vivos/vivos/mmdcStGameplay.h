/* ============================================================
	Gameplay
	Game state for the main gameplay
	===========================================================*/
#pragma once
#include "mmdcGameState.h"
#include "mmdcDataTypes.h"
#include "mmdcActPlayer.h"
#include "mmdcActorEvents.h"

class mmdcStGameplay :
	public mmdcGameState
{
private:
	std::shared_ptr<mmdcActPlayer>	player;
	std::shared_ptr<mmdcActPlayer>	player2;
	mmdcActorEvents events;

public:
	void Start();
	void Update(int dt, inputs_t inputs);
	std::vector<drawable_t> Draw() const;
	void Stop();
};

