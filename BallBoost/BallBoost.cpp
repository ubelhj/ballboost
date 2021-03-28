#include "pch.h"
#include "BallBoost.h"


BAKKESMOD_PLUGIN(BallBoost, "BallBoost Plugin", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

float addedBoost = 0.025;

void BallBoost::onLoad()
{
	_globalCvarManager = cvarManager;

	cvarManager->registerCvar("ball_boost_enabled", "0", "enable ball boost plugin")
		.addOnValueChanged([this](std::string, CVarWrapper cvar) {
			if (cvar.getBoolValue()) {
				hookEvents();
			} else {
				unhookEvents();
			}});	

	cvarManager->registerCvar("ball_boost_amount", "5", "amount of boost to add when hitting the ball")
		.addOnValueChanged([this](std::string, CVarWrapper cvar) {
			addedBoost = (cvar.getIntValue() / 100.0) / 2.0;
			});
}

void BallBoost::onUnload()
{
}

void BallBoost::hookEvents()
{
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
}

void BallBoost::unhookEvents()
{
	gameWrapper->UnhookEventPost("Function TAGame.Car_TA.OnHitBall");
}
