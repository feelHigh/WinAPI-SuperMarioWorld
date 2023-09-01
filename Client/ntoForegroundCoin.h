#pragma once
#include "GameObject.h"

namespace nto
{
	class ForegroundCoin : public GameObject
	{
	public:
		ForegroundCoin();
		virtual ~ForegroundCoin();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetType(int type) { cType = type; }
		int GetType() { return cType; }

		void SetSwitchStatus(bool status) { cStatus = status; }
		bool GetSwitchStatus() { return cStatus; }

		void SetHandledStatus(bool handled) { cHandled = handled; }
		bool GetHandledStatus() { return cHandled; }

	private:
		int cType;
		bool cStatus;
		bool cHandled;
	};
}
