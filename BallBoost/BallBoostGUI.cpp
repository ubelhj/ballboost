#include "pch.h"
#include "BallBoost.h"

/*
// Do ImGui rendering here
void BallBoost::Render()
{
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());
	}
}

// Name of the menu that is used to toggle the window.
std::string BallBoost::GetMenuName()
{
	return "BallBoost";
}

// Title to give the menu
std::string BallBoost::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void BallBoost::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool BallBoost::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool BallBoost::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void BallBoost::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void BallBoost::OnClose()
{
	isWindowOpen_ = false;
}
*/
