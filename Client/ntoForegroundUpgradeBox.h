#pragma once
#include "GameObject.h"

namespace nto
{
	class ForegroundUpgradeBox : public GameObject
	{
	public:
		ForegroundUpgradeBox();
		virtual ~ForegroundUpgradeBox();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:

	};
}
