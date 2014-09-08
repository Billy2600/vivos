#include "mmdcLevel.h"


mmdcLevel::mmdcLevel(std::string filename)
{
}

void mmdcLevel::LoadLevel(std::string filename)
{
	// Load level map
	filename.insert(0, ASSETS_FOLDER); // Add folder path to filename
}
