/* ============================================================
	Titlescreen
	Game state for the title screen
	===========================================================*/
#pragma once
#include <memory>
#include <iostream>
#include "mmdc_game_state.h"


class mmdcStTitlescreen :
	public mmdcGameState
{
private:

public:
	void Start();
	void Update(int dt, inputs_t inputs);
	std::vector<drawable_t> Draw() const;
	void Stop();
};

