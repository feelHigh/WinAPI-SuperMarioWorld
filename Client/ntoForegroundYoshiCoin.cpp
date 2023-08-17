#include "ntoForegroundYoshiCoin.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "ntoResources.h"
#include "ntoSound.h"

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
			Sound* sound = Resources::Load<Sound>(L"sfxYoshiCoin", L"..\\Assets\\Sound\\SFX\\WAV\\coin-special.wav");
			sound->Play(false);
			Destroy(this);
		}
	}

	void ForegroundYoshiCoin::OnCollisionExit(Collider* other)
	{
	}
}
