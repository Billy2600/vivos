#include "mmdcLevel.h"


mmdcLevel::mmdcLevel(std::string filename)
{
	LoadLevel(filename);
}

void mmdcLevel::LoadLevel(std::string filename)
{
	// Load level map
	INIReader reader(ASSETS_FOLDER + filename);

	if (reader.ParseError() < 0)
	{
		std::cout << "Cant load " + filename << std::endl;
	}

	// Load tileset information
	std::stringstream stream(reader.Get("layer", "data", "ERROR"));

	// Texture filename
	std::getline(stream, this->texture, ',');
	// Map width/height
	tileWidth = reader.GetInteger("header", "width", -1);
	tileHeight = reader.GetInteger("header", "height", -1);
	// Tile width/height
	tileWidth = reader.GetInteger("header", "tileWidth", -1);
	tileHeight = reader.GetInteger("header", "tileHeight", -1);

	// Load tile array
	stream = std::stringstream(reader.Get("layer", "data", "ERROR"));
	std::string num;
	// Load data into vector
	while (std::getline(stream, num, ','))
	{
		tiles.push_back(atoi(num.c_str()));
	}
}

std::vector<drawable_t> GetTiles()
{
	std::vector<drawable_t> tiles;

	// Loop through tiles
	for (unsigned int i = 0; i < tiles.size(); i++)
	{
		drawable_t tile;
	}

	return tiles;
}