#include "mmdcActPlayer.h"


mmdcActPlayer::mmdcActPlayer(float x, float y)
	: mmdcActor(x,y)
{
	// Initialize components
	// Sprite
	cmpSprite = std::shared_ptr<drawable_t>(new drawable_t(pos.x,pos.y));
	cmpSprite->fillColor = color_t(0, 255, 0, 255);
	cmpSprite->texPosition = rect_t<int>(86, 168, 32, 32);
	cmpSprite->texFilename = "dopefish.png";
}

void mmdcActPlayer::OnInput(inputs_t inputs, int dt)
{
	// Move player on input
	const float s = 0.5f;
	if (inputs.up == true)
		pos.y += s * dt;
	if (inputs.down == true)
		pos.y -= s * dt;
	if (inputs.right == true)
		pos.x += s * dt;
	if (inputs.left == true)
		pos.x -= s * dt;
}

void mmdcActPlayer::Think(int dt)
{
	// Move sprite to position
	cmpSprite->pos = pos;
}
