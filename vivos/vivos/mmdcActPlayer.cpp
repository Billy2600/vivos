#include "mmdcActPlayer.h"

mmdcActPlayer::mmdcActPlayer(float x, float y)
	: mmdcActor(x,y)
{
	// Initialize components

	// Sprite
	cmpSprite = std::shared_ptr<drawable_t>(new drawable_t(x,y));
	cmpSprite->texPosition = rect_t<int>(0, 0, 48, 48);
	cmpSprite->origin = vec2_t<int>(12, 12); // align sprite to hitbox
	cmpSprite->texFilename = "winchester.png";

	// Hitbox
	cmpHitbox = std::shared_ptr<rect_t<float>>(new rect_t<float>(x,y,20,30));
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

void mmdcActPlayer::OnCollision(std::shared_ptr<mmdcEventReader> otherActor)
{
	//std::cout << "Collided with actor ID: " << otherActor->GetID() << std::endl;

	std::shared_ptr<ev_remove_t> removeObj = std::shared_ptr<ev_remove_t>(new ev_remove_t);
	removeObj->sourceId = aId;
	removeObj->poop = 0;
	removeObj->targetId = otherActor->GetID();
	mmdcActorEvents::AddEvent(removeObj);
}

void mmdcActPlayer::Think(int dt)
{
	
}
