#include "mmdcStTitlescreen.h"

void mmdcStTitlescreen::Start()
{
	
}

void mmdcStTitlescreen::Update(int dt, inputs_t inputs)
{
	float s = 0.5f;
	if (inputs.up == true)
		pos.y -= s * dt;
	if (inputs.down == true)
		pos.y += s * dt;
	if (inputs.right == true)
		pos.x += s * dt;
	if (inputs.left == true)
		pos.x -= s * dt;
	/*{
		change = true;
		changeTo = ST_TITLE;
	}*/
}

drawable_t mmdcStTitlescreen::Draw() const
{
	drawable_t objects[1];
	drawable_t box(15);
	box.pos = this->pos;
	box.fillColor = color_t(0,255,0,255);
	box.texPosition = rect_t<int>(86,168,32,32);

	objects[0] = box;

	return box;
}

void mmdcStTitlescreen::Stop()
{

}
