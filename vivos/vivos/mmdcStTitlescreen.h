/* ============================================================
	Titlescreen
	Game state for the title screen
	===========================================================*/
#pragma once
#include <memory>
#include "mmdcGameState.h"
#include "mmdcActor.h"
#include "sigslot.h"

class mmdcStTitlescreen :
	public mmdcGameState
{
private:
	vec2_t<float> pos;
	std::shared_ptr<mmdcActor> testAct;
	sigslot::signal1<std::string> testSig;

public:
	void Start();
	void Update(int dt, inputs_t inputs);
	std::vector<drawable_t> Draw() const;
	void Stop();
};

