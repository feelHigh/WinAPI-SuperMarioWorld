#include "Player.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"
#include "Animator.h"
#include "ntoRigidbody.h"
#include "ntoCollisionManager.h"

namespace nto
{
	Player::Player()
		: mState(eState::Idle)
		, mDir(eMarioDirection::Right)
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
		case nto::Player::eState::Idle:
			Idle();
			break;
		case nto::Player::eState::Run:
			Run();
			break;
		case nto::Player::eState::Duck:
			Duck();
			break;
		case nto::Player::eState::Jump:
			Jump();
			break;
		case nto::Player::eState::Fall:
			Fall();
			break;
		case nto::Player::eState::Kick:
			Kick();
			break;
		case nto::Player::eState::Dead:
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

	void Player::OnCollisionEnter(Collider* other)
	{
	}

	void Player::OnCollisionStay(Collider* other)
	{
	}

	void Player::OnCollisionExit(Collider* other)
	{
	}

	void Player::Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKeyDown(eKeyCode::W))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Small_Jump_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Small_Jump_Right", true);
			}
			mState = eState::Jump;
		}
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Small_Run_Left", true);
			mState = eState::Run;
		}
		if (Controller::GetKey(eKeyCode::S))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Small_Duck_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Small_Duck_Right", true);
			}

			mState = eState::Duck;
		}
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Small_Run_Right", true);
			mState = eState::Run;
		}
		if (Controller::GetKeyDown(eKeyCode::Z))
		{
			mState = eState::Kick;
		}
		if (Controller::GetKeyDown(eKeyCode::X))
		{
			mState = eState::Dead;
		}
	}

	void Player::Run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Controller::GetKey(eKeyCode::W))
		{
			mState = eState::Jump;
		}
		if (Controller::GetKey(eKeyCode::A))
		{
			pos.x -= 250.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::S))
		{
			mState = eState::Duck;
		}
		if (Controller::GetKey(eKeyCode::D))
		{
			pos.x += 250.0f * Time::DeltaTime();
		}

		if (Controller::GetKeyUp(eKeyCode::W)
			|| Controller::GetKeyUp(eKeyCode::A)
			|| Controller::GetKeyUp(eKeyCode::S)
			|| Controller::GetKeyUp(eKeyCode::D))
		{
			Animator* animator = GetComponent<Animator>();

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Small_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Small_Idle_Right", true);
			}
			mState = eState::Idle;
		}

		tr->SetPosition(pos);
	}

	void Player::Duck()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Small_Duck_Left", true);
		}
		if (Controller::GetKey(eKeyCode::S))
		{
		}
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Small_Duck_Right", true);
		}

		if (Controller::GetKeyUp(eKeyCode::S))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Small_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Small_Idle_Right", true);
			}
			mState = eState::Idle;
		}
	}

	void Player::Jump()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();

		if (Controller::GetKey(eKeyCode::W))
		{
			//pos.y -= 2000.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -2000.0f));
		}

		if (Controller::GetKeyUp(eKeyCode::W))
		{

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Small_Fall_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Small_Fall_Right", true);
			}
			mState = eState::Fall;
		}

		tr->SetPosition(pos);
	}

	void Player::Fall()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();

		if (Controller::GetKey(eKeyCode::A))
		{
			pos.x -= 250.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::S))
		{
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, +2000.0f));
		}
		if (Controller::GetKey(eKeyCode::D))
		{
			pos.x += 250.0f * Time::DeltaTime();
		}

		// Fall 즉시 Idle상태로
		mState = eState::Idle;
	}

	void Player::Kick()
	{
		Animator* animator = GetComponent<Animator>();

		if (mDir == eMarioDirection::Left)
		{
			animator->PlayAnimation(L"Small_Kick_Left", false);
		}
		else
		{
			animator->PlayAnimation(L"Small_Kick_Right", false);
		}

		if (Controller::GetKeyUp(eKeyCode::Z))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Small_Idle_Left", false);
				mState = eState::Idle;
			}
			else
			{
				animator->PlayAnimation(L"Small_Idle_Right", false);
				mState = eState::Idle;
			}
		}
	}

	void Player::Dead()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();

		if (Controller::GetKeyUp(eKeyCode::X))
		{
			//GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -1000.0f));
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Small_Swim_Left", true);
				mState = eState::Idle;
			}
			else
			{
				animator->PlayAnimation(L"Small_Swim_Right", true);
				mState = eState::Idle;
			}
		}
		tr->SetPosition(pos);
	}
}
