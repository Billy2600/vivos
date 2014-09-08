/* ============================================================
	Level
	Loads level tiles and creates objects
	Also handles tile collisions
	===========================================================*/
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "mmdcDataTypes.h"

class mmdcLevel
{
private:

public:
	mmdcLevel(std::string filename);

	// Load level information
	void LoadLevel(std::string filename);

	// Get surrounding level tile collisions
	std::vector<rect_t<int>> GetCollisions(float x, float y);
};

