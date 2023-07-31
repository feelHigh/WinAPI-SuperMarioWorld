#include "ntoMonster.h"
#include "Transform.h"
#include "CustomTime.h"
#include "Animator.h"

namespace nto
{
	Monster::Monster()
		: mDeathTime(1.0f)
	{
	}

	Monster::~Monster()
	{
	}

	void Monster::Initialize()
	{
	}

	void Monster::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		//pos.x += 300.0f * Time::DeltaTime();
		tr->SetPosition(pos);

		//mDeathTime -= Time::DeltaTime();
		//if (mDeathTime < 0.0f)
		//{
		//	Destroy(this);
		//}
	}

	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Monster::OnCollisionEnter(Collider* other)
	{
	}

	void Monster::OnCollisionStay(Collider* other)
	{
	}

	void Monster::OnCollisionExit(Collider* other)
	{
	}
}
