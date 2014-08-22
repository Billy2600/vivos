/* ============================================================
	Gameplay
	Game state for the main gameplay
	===========================================================*/
#pragma once
#include "mmdcGameState.h"
#include "mmdcDataTypes.h"
#include "mmdcActor.h"
#include "sigslot.h"

class mmdcStGameplay :
	public mmdcGameState
{
private:
	vec2_t<float>					pos;
	std::shared_ptr<mmdcActor>		testAct;
	sigslot::signal2<inputs_t, int> testSig;

public:
	void Start();
	void Update(int dt, inputs_t inputs);
	std::vector<drawable_t> Draw() const;
	void Stop();
};

