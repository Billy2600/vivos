/* ============================================================
	Titlescreen
	Game state for the title screen
	===========================================================*/
#pragma once
#include "mmdcGameState.h"

class mmdcStTitlescreen :
	public mmdcGameState
{
public:
	void Start();
	void Update(int dt);
	void Draw(sf::RenderWindow &window);
	void Stop();
};

