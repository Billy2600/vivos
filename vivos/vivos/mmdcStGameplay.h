/* ============================================================
	Gameplay
	Game state for the main gameplay
	===========================================================*/
#pragma once
#include "mmdcGameState.h"

class mmdcStGameplay :
	public mmdcGameState
{
private:

public:
	void Start();
	void Update(int dt, inputs_t inputs);
	std::vector<drawable_t> Draw() const;
	void Stop();
};

