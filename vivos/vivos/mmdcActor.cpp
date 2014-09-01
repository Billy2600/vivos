#include "mmdcActor.h"

// Init incrementor
std::atomic<int> mmdcActor::sId = 1;

void mmdcActor::ReadEvent(std::shared_ptr<event_t> inEvent)
{
	// What kind of type are you?
	// How do you do the things you do?
	if (std::dynamic_pointer_cast<ev_input_t>(inEvent) != 0) // Input
		this->OnInput(std::dynamic_pointer_cast<ev_input_t>(inEvent)->inputs);
}

void mmdcActor::Move(float x, float y)
{
	// Move to new position
	if (x != 0) cmpHitbox->x = x;
	if (y != 0) cmpHitbox->y = y;

	// Move sprite to position
	if (cmpSprite != NULL)
		cmpSprite->pos = vec2_t<float>(cmpHitbox->x, cmpHitbox->y);
}