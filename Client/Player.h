#pragma once
#include "GameObject.h"

namespace nto
{
	class Player : public GameObject
	{
	public:
#define RUNSPEED 600.0f // 600 Àû±â
#define JUMPFORCE -1200.f

		enum class eState
		{
			Idle,
			Run,
			Duck,
			Jump,
			Fall,
			Kick,
			Attack,
			Dead,
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

		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		// Small Mario Action
		void SmallM_Idle();
		void SmallM_Run();
		void SmallM_Duck();
		void SmallM_Jump();
		void SmallM_Fall();
		void SmallM_Kick();
		void SmallM_Dead();

		// Super Mario Action
		void SuperM_Idle();
		void SuperM_Run();
		void SuperM_Duck();
		void SuperM_Jump();
		void SuperM_Fall();
		void SuperM_Kick();
		void SuperM_Dead();

		// Fire Mario Action
		void FireM_Idle();
		void FireM_Run();
		void FireM_Duck();
		void FireM_Jump();
		void FireM_Fall();
		void FireM_Kick();
		void FireM_Attack();
		void FireM_Dead();

		void SetPlayerClass(eMarioClass playerClass) { mPlayerClass = playerClass; }
		eMarioClass GetPlayerClass() const { return mPlayerClass; }

	private:
		eMarioClass mPlayerClass;
		eMarioDirection mDir;
		eState mState;

		bool onGround;
		
		int mLife;
		
	};
}
