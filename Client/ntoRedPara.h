#pragma once
#include "GameObject.h"
#include "ntoRigidbody.h"

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

		void SetType(int type) { mType = type; }
		int GetType() { return mType; }

		void SetDeathTime(float time) { mDeathTime = time; }
		float SetDeathTIme() { return mDeathTime; }

	private:
		float mRotateTime;
		float mDeathTime;
		bool mAttacked;
		bool mTick;
		int mState;
		int mType;
	};
}
