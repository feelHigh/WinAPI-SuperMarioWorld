#pragma once
#include "GameObject.h"
#include <string>

namespace nto
{
	using namespace math;

	class HUDTimer : public GameObject
	{
	public:
		HUDTimer();
		virtual ~HUDTimer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetType(int type) { htType = type; }
		int GetType() { return htType; }

	private:
		static Vector2 htResolution;        // Screen resolution
		static Vector2 htLookPosition;      // Camera focus position
		static Vector2 htDistance;          // Distance moved from the center
		static GameObject* htTarget;        // The GameObject the camera is focusing on

		int htTimer;
		int htType;
	};
}
