#include "ntoStageBossEnter.h"
#include "StageWorldMap.h"
#include "StageBoss.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "Controller.h"
#include "Texture.h"
#include "Animator.h"
#include "Transform.h"
#include "ntoResources.h"
#include "ntoSound.h"
#include "Background.h"
#include "Camera.h"
#include "CustomTime.h"

namespace nto
{
	StageBossEnter::StageBossEnter()
	{
	}

	StageBossEnter::~StageBossEnter()
	{
	}
	
	void StageBossEnter::Initialize()
	{
		Texture* StageEnter_Image = Resources::Load<Texture>(L"StageEnter"
			, L"..\\Assets\\Image\\StageEnter\\StageEnter.bmp");

		StageEnter* StageEnter_Entity = object::Instantiate<StageEnter>(eLayerType::Background);

		Transform* trStageEnter = StageEnter_Entity->GetComponent<Transform>();

		trStageEnter->SetPosition(Vector2(512.0f, 448.0f));

		Animator* atStageEnter = StageEnter_Entity->AddComponent<Animator>();

		atStageEnter->CreateAnimation(L"Animation_StageEnter", StageEnter_Image, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 9, Vector2(0.0f, 0.0f), 0.1f);

		atStageEnter->PlayAnimation(L"Animation_StageEnter", false);

		atStageEnter->SetScale(Vector2(2.0f, 2.0f));
	}
	
	void StageBossEnter::Update()
	{
		Scene::Update();

		if (Controller::GetKeyDown(eKeyCode::P))
		{
			SceneManager::CreateScene<StageBoss>(L"StageBoss");
			SceneManager::LoadScene(L"StageBoss");
		}
	}
	
	void StageBossEnter::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
