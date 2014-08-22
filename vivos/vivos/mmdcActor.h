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
	std::shared_ptr<drawable_t> cmpSprite; // Sprite

public:

	mmdcActor()
	{
		
	}

	~mmdcActor()
	{
	}
};

