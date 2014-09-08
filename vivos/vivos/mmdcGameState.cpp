#include "mmdcGameState.h"

bool mmdcGameState::TryMove(int index, float x, float y)
{
	std::shared_ptr<mmdcActor> curActor = std::dynamic_pointer_cast<mmdcActor>(actors[index]);
	rect_t<float> newBox(x, y, curActor->GetHitbox()->w, curActor->GetHitbox()->h);

	if (rect_t<float>::Collision(newBox, *std::dynamic_pointer_cast<mmdcActor>(actors[1])->GetHitbox()))
	{
		// Pass actor collision to actor, in case they need to do something with it
		actors[index]->OnCollision(actors[1]);
		return false;
	}
	// Move actor
	curActor->Move(x, y);
	return true;
}

//void mmdcGameState::RemoveActors()
//{
//	for (unsigned int i = 0; i < actors.size(); i++)
//	{
//		if (actors[i]->GetRemove()) // Wants to be removed
//		{
//			actors.erase(actors.begin() + i); // Remove'd!
//		}
//	}
//}