#include "StageWorldMap.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "Controller.h"
#include "Texture.h"
#include "Transform.h"
#include "ntoResources.h"
#include "Camera.h"
#include "Animator.h"
#include "ntoCollider.h"
#include "ntoCollisionManager.h"
#include "ntoRigidbody.h"
#include "ntoSound.h"

namespace nto
{
	StageWorldMap::StageWorldMap()
	{
	}

	StageWorldMap::~StageWorldMap()
	{
	}

	void StageWorldMap::Initialize()
	{
		#pragma region Background Layer
		Texture* WorldMap_Border_Image = Resources::Load<Texture>(L"WorldMap_Border"
			, L"..\\Assets\\Image\\WorldMap\\WorldMap_Border.bmp");
		Texture* WorldMap_World_1_Image = Resources::Load<Texture>(L"WorldMap_World_1"
			, L"..\\Assets\\Image\\WorldMap\\WorldMap_World_1.bmp");

		WorldMap_Border_Entity = object::Instantiate<BackGround>(eLayerType::Background);
		WorldMap_World_1_Entity = object::Instantiate<BackGround>(eLayerType::Background);

		SpriteRenderer* WorldMap_Border_Renderer = WorldMap_Border_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* WorldMap_World_1_Renderer = WorldMap_World_1_Entity->AddComponent<SpriteRenderer>();

		WorldMap_Border_Renderer->SetImage(WorldMap_Border_Image);
		WorldMap_World_1_Renderer->SetImage(WorldMap_World_1_Image);

		WorldMap_Border_Renderer->SetScale(Vector2(4.0f, 4.0f));
		WorldMap_World_1_Renderer->SetScale(Vector2(4.0f, 4.0f));

		WorldMap_Border_Entity->GetComponent<Transform>()->SetPosition(Vector2(512.0f, 448.0f));
		WorldMap_World_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(512.0f, 496.0f));
		#pragma endregion

		#pragma region Player Layer
		Texture* Mario_Left_Image = Resources::Load<Texture>(L"Direction_Left"
			, L"..\\Assets\\Mario\\Mario_Left.bmp");
		Texture* Mario_Right_Image = Resources::Load<Texture>(L"Direction_Right"
			, L"..\\Assets\\Mario\\Mario_Right.bmp");

		player = object::Instantiate<StageDirector>(eLayerType::Player);
		Transform* trPlayer = player->GetComponent<Transform>();

		trPlayer->SetPosition(Vector2(488.0f, 668.0f)); // 500

		Animator* atPlayer = player->AddComponent<Animator>();
		// 방향 = 왼쪽
		// <Small Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Small_Idle_Left", Mario_Left_Image, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Run_Left", Mario_Left_Image, Vector2(48.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);

		// <Super Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Super_Idle_Left", Mario_Left_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Run_Left", Mario_Left_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		// <Fire Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Fire_Idle_Left", Mario_Left_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Run_Left", Mario_Left_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 96.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		// 방향 = 오른쪽
		// <Small Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Small_Idle_Right", Mario_Right_Image, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Run_Right", Mario_Right_Image, Vector2(48.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);

		// <Super Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Super_Idle_Right", Mario_Right_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);

		// <Fire Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Fire_Idle_Right", Mario_Right_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Run_Right", Mario_Right_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 96.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		atPlayer->SetScale(Vector2(4.0f, 4.0f));

		atPlayer->PlayAnimation(L"Animation_Small_Idle_Right", true);

		atPlayer->SetAffectedCamera(true);

		Collider* colPlayer = player->AddComponent<Collider>();

		colPlayer->SetSize(Vector2(64.0f, 80.0f)); // Small Mario

		//colPlayer->SetSize(Vector2(64.0f, 112.0f)); // Super, Fire Mario
		//player->AddComponent<Rigidbody>();
		#pragma endregion

		#pragma region Foreground Layer
		StagePlate1_Entity = object::Instantiate<StagePlate>(eLayerType::Foreground);
		StagePlate2_Entity = object::Instantiate<StagePlate>(eLayerType::Foreground);
		StagePlate3_Entity = object::Instantiate<StagePlate>(eLayerType::Foreground);
		StagePlate4_Entity = object::Instantiate<StagePlate>(eLayerType::Foreground);

		StagePlate1_Entity->SetStageNum(1);
		StagePlate2_Entity->SetStageNum(2);
		StagePlate3_Entity->SetStageNum(3);
		StagePlate4_Entity->SetStageNum(4);

		Transform* trStagePlate1 = StagePlate1_Entity->GetComponent<Transform>();
		Transform* trStagePlate2 = StagePlate2_Entity->GetComponent<Transform>();
		Transform* trStagePlate3 = StagePlate3_Entity->GetComponent<Transform>();
		Transform* trStagePlate4 = StagePlate4_Entity->GetComponent<Transform>();

		trStagePlate1->SetPosition(Vector2(678.0f, 716.0f));
		trStagePlate2->SetPosition(Vector2(678.0f, 588.0f));
		trStagePlate3->SetPosition(Vector2(806.0f, 460.0f));
		trStagePlate4->SetPosition(Vector2(688.0f, 332.0f));

		Collider* colStagePlate1 = StagePlate1_Entity->AddComponent<Collider>();
		Collider* colStagePlate2 = StagePlate2_Entity->AddComponent<Collider>();
		Collider* colStagePlate3 = StagePlate3_Entity->AddComponent<Collider>();
		Collider* colStagePlate4 = StagePlate4_Entity->AddComponent<Collider>();

		colStagePlate1->SetSize(Vector2(64.0f, 64.0f));
		colStagePlate2->SetSize(Vector2(64.0f, 64.0f));
		colStagePlate3->SetSize(Vector2(64.0f, 64.0f));
		colStagePlate4->SetSize(Vector2(64.0f, 64.0f));
		#pragma endregion

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Foreground, true);

		bgSound = Resources::Load<Sound>(L"bgmYoshiIsland", L"..\\Assets\\Sound\\BGM\\WAV\\02.Map_1(Yoshi's Island).wav");
		bgSound->Play(true);
	}

	void StageWorldMap::Update()
	{
		Scene::Update();
		Camera::SetTarget(WorldMap_Border_Entity);
		Camera::SetOffset(Vector2(0.0f, 0.0f));

		if (StagePlate1_Entity->GetStageEnter())
		{
			bgSound->Stop(true);
		}
		if (StagePlate2_Entity->GetStageEnter())
		{
			bgSound->Stop(true);
		}
		if (StagePlate3_Entity->GetStageEnter())
		{
			bgSound->Stop(true);
		}
		if (StagePlate4_Entity->GetStageEnter())
		{
			bgSound->Stop(true);
		}
		if (Controller::GetKeyDown(eKeyCode::O))
		{
			bgSound->Play(true);
		}
	}

	void StageWorldMap::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
