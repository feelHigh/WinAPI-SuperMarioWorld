#pragma once
#include "GameObject.h"
#include <string>

namespace nto
{
	using namespace math;

	class HUDCoins : public GameObject
	{
	public:
		HUDCoins();
		virtual ~HUDCoins();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetType(int type) { hcType = type; }
		int GetType() { return hcType; }

	private:
		static Vector2 hcResolution;        // Screen resolution
		static Vector2 hcLookPosition;      // Camera focus position
		static Vector2 hcDistance;          // Distance moved from the center
		static GameObject* hcTarget;        // The GameObject the camera is focusing on

		int hcCoins;
		int hcType;
	};
}
