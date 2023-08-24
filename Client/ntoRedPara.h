#pragma once
#include "GameObject.h"

namespace nto
{
	class RedPara : public GameObject
	{
	public:
		RedPara();
		~RedPara();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	private:
		float mRotateTime;
		float mDeathTime;
		bool mAttacked;
	};
}
