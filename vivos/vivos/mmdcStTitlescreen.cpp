#include "mmdcStTitlescreen.h"

void mmdcStTitlescreen::Start()
{
	testAct = std::shared_ptr<mmdcActor>(new mmdcActor());
	testSig.connect(&*testAct, &mmdcActor::Test);
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

	testSig.emit("Boobs");
}

std::vector<drawable_t> mmdcStTitlescreen::Draw() const
{
	std::vector<drawable_t> objects;

	drawable_t box(15);
	box.pos = this->pos;
	box.fillColor = color_t(0,255,0,255);
	box.texPosition = rect_t<int>(86,168,32,32);
	objects.push_back(box);

	drawable_t box2(15);
	box2.pos.x = this->pos.x + 50;
	box2.pos.y = this->pos.y + 50;
	box2.fillColor = color_t(0, 255, 0, 255);
	box2.texPosition = rect_t<int>(0, 0, 32, 32);
	objects.push_back(box2);

	return objects;
}

void mmdcStTitlescreen::Stop()
{
	
}
