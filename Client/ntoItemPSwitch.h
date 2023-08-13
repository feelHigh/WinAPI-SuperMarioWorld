#pragma once
#include "GameObject.h"

namespace nto
{
	class ItemPSwitch : public GameObject
	{
	public:
		ItemPSwitch();
		virtual ~ItemPSwitch();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetType(bool status) { pStatus = status; }
		bool GetType() { return pStatus; }

	private:
		bool pStatus;
		bool pOnGround;
		float pTimer;
	};
}
