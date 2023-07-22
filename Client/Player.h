#pragma once
#include "GameObject.h"

namespace nto
{
	class Player : public GameObject
	{
	public:
		enum class eState
		{
			Direction,
			Idle,
			Move,
			Jump,
			Death,
		};

		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void Direction();
		void Idle();
		void Move();
		void Jump();
		void Dead();

	private:
		eState mState;
	};
}
