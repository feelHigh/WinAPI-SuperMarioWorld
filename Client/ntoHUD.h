#pragma once
#include "GameObject.h"
#include <string>

namespace nto
{
	using namespace math;

	class HUD : public GameObject
	{
	public:
		HUD();
		virtual ~HUD();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		static Vector2 hResolution;        // Screen resolution
		static Vector2 hLookPosition;      // Camera focus position
		static Vector2 hDistance;          // Distance moved from the center
		static GameObject* hTarget;        // The GameObject the camera is focusing on
	};
}
