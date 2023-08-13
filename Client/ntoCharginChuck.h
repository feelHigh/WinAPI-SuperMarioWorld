#pragma once
#include "GameObject.h"

namespace nto
{
	class CharginChuck : public GameObject
	{
	public:
		CharginChuck();
		~CharginChuck();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	private:
		bool eAttacked;
		int ePhase;
		int tmpPhase;
		float eTimer;
		float tmpTimer;
		float hitTimer;
		float eDeathTime;
	};
}
