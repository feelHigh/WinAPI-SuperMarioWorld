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
			if (Controller::GetKeyDown(eKeyCode::I))
			{
				SceneManager::CreateScene<Stage1>(L"Stage1");
				SceneManager::LoadScene(L"Stage1");
			}
        }
	}

	void StagePlate::OnCollisionExit(Collider* other)
	{
	}
}
