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

	std::cout << "Map Information:";
}
