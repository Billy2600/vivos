#include "mmdcActPlayer.h"


mmdcActPlayer::mmdcActPlayer(float x, float y)
	: mmdcActor(x,y)
{
	// Initialize components
	// Sprite
	cmpSprite = std::shared_ptr<drawable_t>(new drawable_t(pos.x,pos.y));
	//cmpSprite->fillColor = color_t(0, 255, 0, 255);
	cmpSprite->texPosition = rect_t<int>(0, 0, 48, 48);
	cmpSprite->texFilename = "winchester.png";
}

void mmdcActPlayer::OnInput(inputs_t inputs, int dt)
{
	// Move player on input
	if (inputs.up == true)
		pos.y += speed * dt;
	if (inputs.down == true)
		pos.y -= speed * dt;
	if (inputs.right == true)
		pos.x += speed * dt;
	if (inputs.left == true)
		pos.x -= speed * dt;
}

void mmdcActPlayer::Think(int dt)
{
	// Move sprite to position
	cmpSprite->pos = pos;
}
