#pragma once
#include "GameObject.h"

namespace nto
{
	class Player : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Run,
			Duck,
			Jump,
			Fall,
			Kick,
			Dead,
		};

		enum class eMarioDirection
		{
			Left = 0,
			Right = 1,
		};

		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void Idle();
		void Run();
		void Duck();
		void Jump();
		void Fall();
		void Kick();
		void Dead();

	private:
		eState mState;
		eMarioDirection mDir;
	};
}
