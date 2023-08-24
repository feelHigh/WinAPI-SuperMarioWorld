#pragma once
#include "GameObject.h"
#include "ntoCollider.h"

namespace nto
{
	class AttackFireball : public GameObject
	{
	public:
		AttackFireball();
		virtual ~AttackFireball();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetDeathTime(float time) { mDeathTime = time; }
		float GetDeathTime() { return mDeathTime; }

		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		Vector2 GetVelocity() { return mVelocity; }

		void SetBounceSpeed(float speed) { mBounceSpeed = speed; }
		float GetBounceSpeed() { return mBounceSpeed; }

		void SetGravity(float gravity) { mGravity = gravity; }
		float GetGravity() { return mGravity; }

	private:
		float mDeathTime;
		Vector2 mVelocity;
		bool mIsBouncing;
		float mBounceSpeed;
		float mGravity;
	};
}
