/* ============================================================
	Player Actor
	Controls the player
	===========================================================*/
#pragma once
#include "mmdcActor.h"

class mmdcActPlayer :
	public mmdcActor
{
private:
	// Speed the player moves
	//const float speed = 0.5f;
	float speed;

public:
	mmdcActPlayer(float x = 0.f, float y = 0.f);
	void OnInput(inputs_t inputs, int dt);
	void Think(int dt);
};

