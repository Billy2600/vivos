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
	const float moveSpeed = 5.f; // Movement speed

public:
	mmdcActPlayer(float x = 0.f, float y = 0.f);
	void OnInput(inputs_t inputs);
	void OnCollision(std::shared_ptr<mmdcEventReader>);
	void Think(int dt);
};

