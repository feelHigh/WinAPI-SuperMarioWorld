#pragma once
#include "GameObject.h"

namespace nto
{
	using namespace math;
	class EnvironmentWoodPlank : public GameObject
	{
	public:
		EnvironmentWoodPlank();
		virtual ~EnvironmentWoodPlank();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetCenter(Vector2 center) { pCenter = center; }
		Vector2 GetCenter() { return pCenter; }
		void SetAngle(float angle) { pAngle = angle; }
		float GetAngle() { return pAngle; }

	private:
		float pRadius;
		float pAngle;
		float pSpeed;
		Vector2 pCenter;
	};
}
