#include "ntoForegroundYoshiCoin.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"

namespace nto
{
	ForegroundYoshiCoin::ForegroundYoshiCoin()
	{
	}

	ForegroundYoshiCoin::~ForegroundYoshiCoin()
	{
	}

	void ForegroundYoshiCoin::Initialize()
	{
	}

	void ForegroundYoshiCoin::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();

	}

	void ForegroundYoshiCoin::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ForegroundYoshiCoin::OnCollisionEnter(Collider* other)
	{
	}

	void ForegroundYoshiCoin::OnCollisionStay(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		if (player)
		{
			Destroy(this);
		}
	}

	void ForegroundYoshiCoin::OnCollisionExit(Collider* other)
	{
	}
}
