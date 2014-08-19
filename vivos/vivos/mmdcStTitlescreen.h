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
	vec2_t<int> pos;

public:
	void Start();
	void Update(int dt, int input);
	void Draw(sf::RenderWindow &window);
	void Stop();
};

