#include "Player.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"
#include "Animator.h"
#include "ntoRigidbody.h"

namespace nto
{
	Player::Player()
		: mState(eState::Idle)
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

		switch (mState)
		{
		case nto::Player::eState::Direction:
			Direction();
			break;
		case nto::Player::eState::Idle:
			Idle();
			break;
		case nto::Player::eState::Move:
			Move();
			break;
		case nto::Player::eState::Jump:
			Jump();
			break;
		case nto::Player::eState::Death:
			Dead();
			break;
		default:
			break;
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Player::Direction()
	{
	}

	void Player::Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::W))
		{
			//animator->PlayAnimation(L"PlayerUpMove", true);
			//mState = eState::Move;
		}
		if (Controller::GetKey(eKeyCode::A))
		{
			animator->PlayAnimation(L"SmallMario_RunLeft", true);
			mState = eState::Move;
		}
		if (Controller::GetKey(eKeyCode::S))
		{
			animator->PlayAnimation(L"SmallMario_DuckDown", true);
			mState = eState::Move;
		}
		if (Controller::GetKey(eKeyCode::D))
		{
			animator->PlayAnimation(L"SmallMario_RunRight", true);
			mState = eState::Move;
		}
	}

	void Player::Move()
	{
		Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();
		if (Controller::GetKey(eKeyCode::W))
		{
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -200.0f));
			//pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::A))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Controller::GetKey(eKeyCode::S))
		{
			//pos.y += 100.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, 200.0f));
		}
		if (Controller::GetKey(eKeyCode::D))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(200.0f, 0.0f));
		}
		//tr->SetPosition(pos);

		if (Controller::GetKeyUp(eKeyCode::W)
			|| Controller::GetKeyUp(eKeyCode::A)
			|| Controller::GetKeyUp(eKeyCode::S)
			|| Controller::GetKeyUp(eKeyCode::D))
		{
			Animator* animator = GetComponent<Animator>();
			//animator->PlayAnimation(L"PlayerIdle", true);
			mState = eState::Idle;
		}
	}

	void Player::Jump()
	{
	}

	void Player::Dead()
	{
	}
}
