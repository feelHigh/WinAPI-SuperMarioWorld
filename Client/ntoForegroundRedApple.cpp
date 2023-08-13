#include "ntoForegroundRedApple.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"

namespace nto
{
	ForegroundRedApple::ForegroundRedApple()
	{
	}

	ForegroundRedApple::~ForegroundRedApple()
	{
	}

	void ForegroundRedApple::Initialize()
	{
	}

	void ForegroundRedApple::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();

	}

	void ForegroundRedApple::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ForegroundRedApple::OnCollisionEnter(Collider* other)
	{
	}

	void ForegroundRedApple::OnCollisionStay(Collider* other)
	{
	}

	void ForegroundRedApple::OnCollisionExit(Collider* other)
	{
	}
}
