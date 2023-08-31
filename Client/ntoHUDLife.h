#pragma once
#include "GameObject.h"
#include <string>

namespace nto
{
	using namespace math;

	class HUDLife : public GameObject
	{
	public:
		HUDLife();
		virtual ~HUDLife();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		static Vector2 hlResolution;        // Screen resolution
		static Vector2 hlLookPosition;      // Camera focus position
		static Vector2 hlDistance;          // Distance moved from the center
		static GameObject* hlTarget;        // The GameObject the camera is focusing on

		int hlLife;
	};
}
