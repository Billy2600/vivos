/* ============================================================
	Actor
	Super class for all the actors in the game
	Each actor has pointers to components it can have
	This file also contains some component declarations
	===========================================================*/
#pragma once
#include <memory>
#include <iostream>
#include "mmdcDataTypes.h"
#include "sigslot.h"

class mmdcActor :
	public sigslot::has_slots<>
{
private:
	// Components
	std::shared_ptr<drawable_t> cmpSprite; // Sprite

public:

	mmdcActor()
	{
		
	}

	void Test(std::string test)
	{
		std::cout << test << std::endl;
	}

	~mmdcActor()
	{
	}
};

