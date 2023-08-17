#include "ntoStageDirector.h"
#include "Transform.h"
#include "Controller.h"
#include "ntoCollider.h"
#include "Animator.h"
#include "ntoRigidbody.h"
#include "ntoCollisionManager.h"
#include "Object.h"
#include "Texture.h"
#include "ntoResources.h"
#include "CustomTime.h"

namespace nto
{
	StageDirector::StageDirector()
		: mPlayerClass(eMarioClass::Small)
		, mDir(eMarioDirection::Right)
		, mState(eState::Idle)
	{
	}

	StageDirector::~StageDirector()
	{
	}

	void StageDirector::Initialize()
	{
	}

	void StageDirector::Update()
	{
		GameObject::Update();

		switch (mPlayerClass)
		{
		case nto::StageDirector::eMarioClass::Small:
			switch (mState)
			{
			case nto::StageDirector::eState::Idle:
				SmallM_Idle();
				break;
			case nto::StageDirector::eState::Run:
				SmallM_Run();
				break;
			default:
				break;
			}
			break;
		case nto::StageDirector::eMarioClass::Super:
			switch (mState)
			{
			case nto::StageDirector::eState::SuperMIdle:
				SuperM_Idle();
				break;
			case nto::StageDirector::eState::SuperMRun:
				SuperM_Run();
				break;
			default:
				break;
			}
			break;
		case nto::StageDirector::eMarioClass::Fire:
			switch (mState)
			{
			case nto::StageDirector::eState::FireMIdle:
				FireM_Idle();
				break;
			case nto::StageDirector::eState::FireMRun:
				FireM_Run();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

	void StageDirector::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void StageDirector::OnCollisionEnter(Collider* other)
	{
	}

	void StageDirector::OnCollisionStay(Collider* other)
	{
	}

	void StageDirector::OnCollisionExit(Collider* other)
	{
	}

	#pragma region Small Mario Action
	void StageDirector::SmallM_Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::Up))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Run_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Run_Right", true);
			}
			mState = eState::Run;
		}
		// 왼쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::Left))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Small_Run_Left", true);
			mState = eState::Run;
		}
		if (Controller::GetKey(eKeyCode::Down))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Run_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Run_Right", true);
			}
			mState = eState::Run;
		}
		// 오른쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::Right))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Small_Run_Right", true);
			mState = eState::Run;
		}
	}

	void StageDirector::SmallM_Run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::Up))
		{
			pos.y -= DIRECTORSPEED * Time::DeltaTime();
		}
		// 플레이어 왼쪽 이동
		if (Controller::GetKey(eKeyCode::Left))
		{
			pos.x -= DIRECTORSPEED * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::Down))
		{
			pos.y += DIRECTORSPEED * Time::DeltaTime();
		}
		// 플레이어 오른쪽 이동
		if (Controller::GetKey(eKeyCode::Right))
		{
			pos.x += DIRECTORSPEED * Time::DeltaTime();
		}

		// 이동중 키 땔 때 Idle 상태로 복귀
		if (Controller::GetKeyUp(eKeyCode::Up)
			|| Controller::GetKeyUp(eKeyCode::Left)
			|| Controller::GetKeyUp(eKeyCode::Down)
			|| Controller::GetKeyUp(eKeyCode::Right))
		{

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Idle_Right", true);
			}
			mState = eState::Idle;
		}

		tr->SetPosition(pos);
	}
	#pragma endregion

	#pragma region Super Mario Action
	void StageDirector::SuperM_Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 왼쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Super_Run_Left", true);
			mState = eState::Run;
		}
		if (Controller::GetKey(eKeyCode::S))
		{
		}
		// 오른쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Super_Run_Right", true);
			mState = eState::Run;
		}
	}

	void StageDirector::SuperM_Run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 플레이어 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			pos.x -= DIRECTORSPEED * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::S))
		{
		}
		// 플레이어 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			pos.x += DIRECTORSPEED * Time::DeltaTime();
		}
		tr->SetPosition(pos);
	}
	#pragma endregion

	#pragma region Fire Mario Action
	void StageDirector::FireM_Idle()
	{
		Animator* animator = GetComponent<Animator>();

		// 위로 보기 애니메이션 재생
		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 왼쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Fire_Run_Left", true);
			mState = eState::Run;
		}
		// 구부리기 애니메이션 재생
		if (Controller::GetKey(eKeyCode::S))
		{
		}
		// 오른쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Fire_Run_Right", true);
			mState = eState::Run;
		}
	}

	void StageDirector::FireM_Run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 플레이어 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			pos.x -= DIRECTORSPEED * Time::DeltaTime();
		}
		// 플레이어 구부리기
		if (Controller::GetKey(eKeyCode::S))
		{
		}
		// 플레이어 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			pos.x += DIRECTORSPEED * Time::DeltaTime();
		}

		tr->SetPosition(pos);
	}
	#pragma endregion

}
