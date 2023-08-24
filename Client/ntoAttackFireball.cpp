#include "ntoAttackFireball.h"
#include "ntoLayerHeaders.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "CustomTime.h"

namespace nto
{
	AttackFireball::AttackFireball()
		: mDeathTime(2.0f)  // Set an initial value for the death time
		, mVelocity(Vector2(600.0f, 0.0f))  // Set the initial velocity of the fireball
		, mIsBouncing(false) // Flag to track if the fireball is currently bouncing
		, mBounceSpeed(800.0f) // Speed of the bounce
		, mGravity(-1500.0f) // Gravity to simulate fall after bounce
	{
	}

	AttackFireball::~AttackFireball()
	{
	}

	void AttackFireball::Initialize()
	{
	}

	void AttackFireball::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos += mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);

		if (mIsBouncing)
		{
			// Apply gravity to simulate fall after bounce
			mVelocity.y += mGravity * Time::DeltaTime();
		}

		// Check for death time
		mDeathTime -= Time::DeltaTime();
		if (mDeathTime < 0.0f)
		{
			Destroy(this);
		}
	}

	void AttackFireball::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void AttackFireball::OnCollisionEnter(Collider* other)
	{
		//Floor* floor = dynamic_cast<Floor*>(other->GetOwner());
		//if (floor)
		//{
		//	if (!mIsBouncing)
		//	{
		//		// Set the vertical velocity to achieve the bounce effect
		//		mVelocity.y = -mBounceSpeed;
		//		mIsBouncing = true;
		//	}
		//}
	}

	void AttackFireball::OnCollisionStay(Collider* other)
	{
	}

	void AttackFireball::OnCollisionExit(Collider* other)
	{
	}
}
