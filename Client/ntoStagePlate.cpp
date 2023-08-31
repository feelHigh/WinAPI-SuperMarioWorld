#include "ntoStagePlate.h"
#include "ntoStageDirector.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "SceneManager.h"
#include "StageWorldMap.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "StageBoss.h"
#include "Controller.h"
#include "ntoSound.h"

namespace nto
{
	StagePlate::StagePlate()
		: StageNum(1)
		, StageEnter(false)
	{
	}

	StagePlate::~StagePlate()
	{
	}

	void StagePlate::Initialize()
	{
	}

	void StagePlate::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);
	}

	void StagePlate::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void StagePlate::OnCollisionEnter(Collider* other)
	{
	}

	void StagePlate::OnCollisionStay(Collider* other)
	{
        StageDirector* player = dynamic_cast<StageDirector*>(other->GetOwner());

        if (player)
        {
			if (StageNum == 1)
			{
				StageEnter = true;
				if (Controller::GetKeyDown(eKeyCode::I))
				{
					SceneManager::CreateScene<Stage1>(L"Stage1");
					SceneManager::LoadScene(L"Stage1");
				}
			}
			if (StageNum == 2)
			{
				StageEnter = true;
				if (Controller::GetKeyDown(eKeyCode::I))
				{
					SceneManager::CreateScene<Stage2>(L"Stage2");
					SceneManager::LoadScene(L"Stage2");
				}
			}
			if (StageNum == 3)
			{
				StageEnter = true;
				if (Controller::GetKeyDown(eKeyCode::I))
				{
					//SceneManager::CreateScene<Stage3>(L"Stage3");
					//SceneManager::LoadScene(L"Stage3");
				}
			}
			if (StageNum == 4)
			{
				StageEnter = true;
				if (Controller::GetKeyDown(eKeyCode::I))
				{
					SceneManager::CreateScene<StageBoss>(L"StageBoss");
					SceneManager::LoadScene(L"StageBoss");
				}
			}
        }
	}

	void StagePlate::OnCollisionExit(Collider* other)
	{
	}
}
