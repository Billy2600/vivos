#include "mmdcEventReader.h"

// Init incrementor
std::atomic<int> mmdcEventReader::sId = 1;

mmdcEventReader::mmdcEventReader()
{
	// Set ID
	aId = sId++;
}

void mmdcEventReader::ReadEvent(std::shared_ptr<event_t> inEvent)
{
	// What kind of type are you?
	// How do you do the things you do?
	if (std::dynamic_pointer_cast<ev_input_t>(inEvent) != 0) // Input
		this->OnInput(std::dynamic_pointer_cast<ev_input_t>(inEvent)->inputs);
	if (std::dynamic_pointer_cast<ev_remove_t>(inEvent) != 0) // Remove
		this->removeMe = true;
}
