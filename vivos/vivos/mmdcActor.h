/* ============================================================
	Actor
	Super class for all the actors in the game
	Each actor has pointers to components it can have
	This file also contains some component declarations
	===========================================================*/
#pragma once
#include <memory>
#include "mmdcDataTypes.h"

class mmdcActor
{
private:
	// Components
	sprite_t *cmpSprite;

public:

	mmdcActor()
	{
	}

	~mmdcActor()
	{
	}
};
