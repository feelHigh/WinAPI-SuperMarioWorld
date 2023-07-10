#include "Player.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"

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

		if (Controller::GetKey(eKeyCode::W))
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::A))
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::S))
		{
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::D))
		{
			pos.x += 300.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
