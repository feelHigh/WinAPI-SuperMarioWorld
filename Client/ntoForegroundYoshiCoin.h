#pragma once
#include "GameObject.h"

namespace nto
{
	class ForegroundYoshiCoin : public GameObject
	{
	public:
		ForegroundYoshiCoin();
		virtual ~ForegroundYoshiCoin();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetHandledStatus(bool handled) { cHandled = handled; }
		bool GetHandledStatus() { return cHandled; }

	private:
		bool cHandled;
	};
}
