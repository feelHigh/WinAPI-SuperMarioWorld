#pragma once
#include "Component.h"

namespace nto
{
	using namespace math;
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		virtual ~Rigidbody();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		void AddForce(Vector2 force) { mForce += force; }
		void SetMass(float mass) { mMass = mass; }
		bool GetGround() { return mbGround; }
		void SetGround(bool ground) { mbGround = ground; }
		Vector2 GetVelocity() { return mVelocity; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }

	private:
		float mMass;

		float mFriction;
		float mStaticFriction;
		float mKineticFrction;
		float mCoefficentFrction;

		Vector2 mForce;
		Vector2 mAccelation;
		Vector2 mVelocity;
		Vector2 mGravity;
		Vector2 mLimitedVelocty;

		bool mbGround;
	};
}
