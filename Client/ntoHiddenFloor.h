#pragma once
#include "GameObject.h"

namespace nto
{
	class HiddenFloor : public GameObject
	{
	public:
		HiddenFloor();
		virtual ~HiddenFloor();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:

	};
}
