/* ============================================================
	Event data types
	Data types used for passing data along events
	===========================================================*/
#pragma once
#include <memory>
#include "mmdcDataTypes.h"

// Super class for all data types
// All will derive from this class
struct event_t
{
	unsigned int targetId; // ID of the target
	unsigned int sourceId; // Id of the source

	virtual void Test() {} // Just to make it polymorphic type
};

// Input
struct ev_input_t
	: event_t
{
	inputs_t inputs;
};