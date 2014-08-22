#include "mmdcStTitlescreen.h"

void mmdcStTitlescreen::Start()
{

}

void mmdcStTitlescreen::Update(int dt, inputs_t inputs)
{
	std::cout << "Press enter" << std::endl;
	if (inputs.accept == true)
	{
		change = true;
		changeTo = ST_GAMEPLAY;
	}
}

std::vector<drawable_t> mmdcStTitlescreen::Draw() const
{
	std::vector<drawable_t> drawable;

	return drawable;
}

void mmdcStTitlescreen::Stop()
{
	
}
