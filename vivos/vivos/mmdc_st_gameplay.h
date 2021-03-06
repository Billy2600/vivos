/* ============================================================
	Gameplay
	Game state for the main gameplay
	===========================================================*/
#pragma once
#include "mmdc_game_state.h"
#include "mmdc_level.h"

class mmdcStGameplay :
	public mmdcGameState
{
private:
	mmdcLevel level = mmdcLevel("map01.txt");

public:
	void Start();
	void Update(int dt, inputs_t inputs);
	std::vector<drawable_t> Draw() const;
	void Stop();
};

