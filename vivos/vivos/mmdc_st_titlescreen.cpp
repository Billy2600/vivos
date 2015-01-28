#include "mmdc_st_titlescreen.h"

void mmdcStTitlescreen::Start()
{

}

void mmdcStTitlescreen::Update(int dt, inputs_t inputs)
{
	if (inputs.accept == true)
	{
		change = true;
		changeTo = ST_GAMEPLAY;
	}
}

std::vector<drawable_t> mmdcStTitlescreen::Draw() const
{
	std::vector<drawable_t> drawable;
	drawable_t pressStart(0,0);
	pressStart.fillColor = color_t(0,0,255);
	pressStart.string = "Press Enter";
	pressStart.strFont = "prstartk.ttf";
	pressStart.strSize = 30;
	drawable.push_back(pressStart);
	return drawable;
}

void mmdcStTitlescreen::Stop()
{
	
}
