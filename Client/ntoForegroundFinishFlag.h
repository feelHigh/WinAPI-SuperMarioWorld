#pragma once
#include "GameObject.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	class ForegroundFinishFlag : public GameObject
	{
	public:
		ForegroundFinishFlag();
		virtual ~ForegroundFinishFlag();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetHit(bool hit) { bHit = hit; }
		bool GetHit() { return bHit; }

		void SetExitStage(int exit) { bExitStage = exit; }
		bool GetExitStage() { return bExitStage; }

	private:
		float bTimer;
		bool bTick;
		bool bHit;
		int bExitStage;

		Sound* m_bgSound;
	};
}
