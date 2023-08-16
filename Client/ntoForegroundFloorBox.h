#pragma once
#include "GameObject.h"

namespace nto
{
	class ForegroundFloorBox : public GameObject
	{
	public:
		ForegroundFloorBox();
		virtual ~ForegroundFloorBox();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetType(int type) { bType = type; }
		int GetType() { return bType; }

	private:
		int bType;
		bool bSwitch;
	};
}
