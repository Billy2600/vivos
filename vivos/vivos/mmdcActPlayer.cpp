#include "mmdcActPlayer.h"


mmdcActPlayer::mmdcActPlayer(float x, float y)
	: mmdcActor(x,y)
{
	// Initialize components

	// Sprite
	cmpSprite = std::shared_ptr<drawable_t>(new drawable_t(x,y));
	//cmpSprite->fillColor = color_t(0, 255, 0, 255);
	cmpSprite->texPosition = rect_t<int>(0, 0, 48, 48);
	cmpSprite->texFilename = "winchester.png";

	// Hitbox
	cmpHitbox = std::shared_ptr<rect_t<float>>(new rect_t<float>(x,y,48,40));
}

void mmdcActPlayer::OnInput(inputs_t inputs)
{
	if (inputs.up)
		newPos.y = cmpHitbox->y + moveSpeed;
	if (inputs.down)
		newPos.y = cmpHitbox->y - moveSpeed;
	if (inputs.right)
		newPos.x = cmpHitbox->x + moveSpeed;
	if (inputs.left)
		newPos.x = cmpHitbox->x - moveSpeed;
}

void mmdcActPlayer::OnCollision(std::shared_ptr<mmdcActor> otherActor)
{
	std::cout << "Collided with actor ID: " << otherActor->GetID() << std::endl;
}

void mmdcActPlayer::Think(int dt)
{
	
}
