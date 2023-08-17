#pragma once
#include "GameObject.h"

namespace nto
{
	class StageDirector : public GameObject
	{
	public:
#define DIRECTORSPEED 200.0f

		enum class eState
		{
			Idle,
			Run,

			SuperMIdle,
			SuperMRun,

			FireMIdle,
			FireMRun,
		};

		enum class eMarioDirection
		{
			Left,
			Right,
		};

		enum class eMarioClass
		{
			Small,
			Super,
			Fire,
		};

		StageDirector();
		virtual ~StageDirector();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		// Small Mario Action
		void SmallM_Idle();
		void SmallM_Run();

		// Super Mario Action
		void SuperM_Idle();
		void SuperM_Run();

		// Fire Mario Action
		void FireM_Idle();
		void FireM_Run();

	private:
		eMarioClass mPlayerClass;
		eMarioDirection mDir;
		eState mState;

	};
}
