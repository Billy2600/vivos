/* ============================================================
	Level
	Loads level tiles and creates objects
	Also handles tile collisions
	===========================================================*/
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "INIReader.h"
#include "mmdc_data_types.h"

class mmdcLevel
{
private:
	// Tilset texture
	std::string texture;
	// Tile array
	std::vector<int> tiles;
	// Map size
	int mapWidth;
	int mapHeight;
	// Tile size
	int tileWidth;
	int tileHeight;

public:
	mmdcLevel(std::string filename);

	// Load level information
	void LoadLevel(std::string filename);

	// Get tiles for drawing
	std::vector<drawable_t> GetTiles();

	// Get surrounding level tile collisions
	std::vector<rect_t<int>> GetCollisions(float x, float y);
};

