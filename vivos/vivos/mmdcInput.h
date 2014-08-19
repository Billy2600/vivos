/* ============================================================
	Input
	Reads input from keyboard, mouse, and controllers and
	passes it along to gamestate in abstract form
	===========================================================*/
#pragma once
#include <SFML/Window.hpp>
#include "mmdcDataTypes.h"

class mmdcInput
{
public:
	mmdcInput();
	
	// Read input
	int ReadInput();
};

