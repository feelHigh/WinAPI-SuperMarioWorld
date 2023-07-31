#pragma once
#include "Player.h"

namespace nto
{
	class SmallMario : public Player
	{
	public:
		enum class eSate
		{
			Idle,
			Run,
			Duck,
			Jump,
			Fall,
			Kick,
			Dead,
		};

		SmallMario();
		virtual ~SmallMario();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:

		eState mState;
		eMarioDirection mDir;
	};
}
