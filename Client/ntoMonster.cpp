#include "ntoMonster.h"
#include "Transform.h"
#include "CustomTime.h"
#include "Animator.h"

namespace nto
{
	Monster::Monster()
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
		Animator* anim = GetComponent<Animator>();

		tr->SetPosition(pos);
	}

	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
