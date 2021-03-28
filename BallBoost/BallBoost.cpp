#include "pch.h"
#include "BallBoost.h"


BAKKESMOD_PLUGIN(BallBoost, "BallBoost Plugin", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

int addedBoost = 5;

void BallBoost::onLoad()
{
	_globalCvarManager = cvarManager;
	
	gameWrapper->HookEventWithCallerPost<CarWrapper>("Function TAGame.Car_TA.OnHitBall",
		[this](CarWrapper caller, void*, std::string) { 
			if (!caller) {
				return;
			}

			BoostWrapper boost = caller.GetBoostComponent();

			if (!boost) {
				return;
			}

			float currBoost = boost.GetCurrentBoostAmount();

			boost.SetBoostAmount(currBoost + addedBoost);
		});

	cvarManager->registerCvar("ball_boost_amount", "5", "amount of boost to add when hitting the ball")
		.addOnValueChanged([this](std::string, CVarWrapper cvar) {
			addedBoost = cvar.getIntValue();
			});
}

void BallBoost::onUnload()
{
}