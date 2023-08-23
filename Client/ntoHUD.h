#pragma once
#include "GameObject.h"
#include <string>

namespace nto
{
	class HUD : public GameObject
	{
	public:
		HUD();
		virtual ~HUD();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		static void DrawCoinCount(HDC hdc, int x, int y, int count);

	private:
		static Vector2 mResolution;        // Screen resolution
		static Vector2 mLookPosition;      // Camera focus position
		static Vector2 mDistance;          // Distance moved from the center
		static GameObject* mTarget;        // The GameObject the camera is focusing on

		static int coinCount;              // The count of coins collected
	};
}
