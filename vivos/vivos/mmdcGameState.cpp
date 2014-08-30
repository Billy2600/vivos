#include "mmdcGameState.h"

bool mmdcGameState::TryMove(int index, float x, float y)
{
	rect_t<float> newBox(x, y, actors[index]->GetHitbox()->w, actors[index]->GetHitbox()->h);

	if (rect_t<float>::Collision(newBox, *actors[1]->GetHitbox()))
		return false;
	actors[index]->Move(x, y);
	return true;
}