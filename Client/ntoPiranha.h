#pragma once
#include "GameObject.h"

namespace nto
{
	class Piranha : public GameObject
	{
	public:
		Piranha();
		~Piranha();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	private:
		bool eTick;
		bool eAttacked;
		float eTimer;
		float eDeathTime;
	};
}
