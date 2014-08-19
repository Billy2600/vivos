/* ============================================================
	Titlescreen
	Game state for the title screen
	===========================================================*/
#pragma once
#include "mmdcGameState.h"

class mmdcStTitlescreen :
	public mmdcGameState
{
private:
	vec2_t<float> pos;

public:
	void Start();
	void Update(int dt, inputs_t inputs);
	void Draw(sf::RenderWindow &window);
	void Stop();
};

