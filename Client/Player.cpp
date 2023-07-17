#include "Player.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"
#include "Animator.h"

namespace nto
{
	Player::Player()
	{
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
	}

	void Player::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* anim = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::W))
		{
			//anim->PlayAnimation(L"JumpLeft", true);
			//pos.y -= 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::A))
		{
			anim->PlayAnimation(L"SmallMario_RunLeft", true);
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::S))
		{
			//anim->PlayAnimation(L"JumpRight", true);
			//pos.y += 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::D))
		{
			anim->PlayAnimation(L"SmallMario_RunRight", true);
			pos.x += 300.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
