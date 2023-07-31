#include "Stage1.h"
#include "Player.h"
#include "ntoMonster.h"
#include "ntoFloor.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "Controller.h"
#include "Texture.h"
#include "Transform.h"
#include "ntoResources.h"
#include "Background.h"
#include "Camera.h"
#include "Animator.h"
#include "ntoCollider.h"
#include "ntoCollisionManager.h"
#include "ntoRigidbody.h"

namespace nto
{
	Stage1::Stage1()
	{
	}

	Stage1::~Stage1()
	{
	}

	void Stage1::Initialize()
	{
		#pragma region Background Layer
		Texture* bgImage = Resources::Load<Texture>(L"Stage1_BackGroundImage"
			, L"..\\Assets\\Image\\Background\\Stage1_Background.bmp");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(bgImage);
		bgsr->SetScale(Vector2(4.0f, 4.0f));
		bgsr->SetAffectCamera(false);
		bg->GetComponent<Transform>()->SetPosition(Vector2(1010.0f, 40.0f));
		#pragma endregion

		#pragma region Floor Layer
		Texture* Stage1_Floor_FrontHalf_Image = Resources::Load<Texture>(L"Stage1_Floor_FrontHalf"
			, L"..\\Assets\\Image\\Floor\\Stage1_FrontHalf.bmp");
		Texture* Stage1_Floor_Stair1_1_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair1_1"
			, L"..\\Assets\\Image\\Floor\\Stage1_Stair1_1_4.bmp");
		Texture* Stage1_Floor_Stair1_2_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair1_2"
			, L"..\\Assets\\Image\\Floor\\Stage1_Stair1_2_4.bmp");
		Texture* Stage1_Floor_Stair1_3_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair1_3"
			, L"..\\Assets\\Image\\Floor\\Stage1_Stair1_3_4.bmp");
		Texture* Stage1_Floor_Stair1_4_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair1_4"
			, L"..\\Assets\\Image\\Floor\\Stage1_Stair1_4_4.bmp");
		Texture* Stage1_Floor_Stair2_1_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair2_1"
			, L"..\\Assets\\Image\\Floor\\Stage1_Stair2_1_2.bmp");
		Texture* Stage1_Floor_Stair2_2_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair2_2"
			, L"..\\Assets\\Image\\Floor\\Stage1_Stair2_2_2.bmp");

		Floor* Stage1_Floor_FrontHalf_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair1_1_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair1_2_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair1_3_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair1_4_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair2_1_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair2_2_Entity = object::Instantiate<Floor>(eLayerType::Floor);

		SpriteRenderer* FrontHalf_Renderer = Stage1_Floor_FrontHalf_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair1_1_Renderer = Stage1_Floor_Stair1_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair1_2_Renderer = Stage1_Floor_Stair1_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair1_3_Renderer = Stage1_Floor_Stair1_3_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair1_4_Renderer = Stage1_Floor_Stair1_4_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair2_1_Renderer = Stage1_Floor_Stair2_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair2_2_Renderer = Stage1_Floor_Stair2_2_Entity->AddComponent<SpriteRenderer>();

		FrontHalf_Renderer->SetImage(Stage1_Floor_FrontHalf_Image);
		Stair1_1_Renderer->SetImage(Stage1_Floor_Stair1_1_Image);
		Stair1_2_Renderer->SetImage(Stage1_Floor_Stair1_2_Image);
		Stair1_3_Renderer->SetImage(Stage1_Floor_Stair1_3_Image);
		Stair1_4_Renderer->SetImage(Stage1_Floor_Stair1_4_Image);
		Stair2_1_Renderer->SetImage(Stage1_Floor_Stair2_1_Image);
		Stair2_2_Renderer->SetImage(Stage1_Floor_Stair2_2_Image);

		FrontHalf_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair1_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair1_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair1_3_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair1_4_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair2_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair2_2_Renderer->SetScale(Vector2(4.0f, 4.0f));

		FrontHalf_Renderer->SetAffectCamera(false);
		Stair1_1_Renderer->SetAffectCamera(false);
		Stair1_2_Renderer->SetAffectCamera(false);
		Stair1_3_Renderer->SetAffectCamera(false);
		Stair1_4_Renderer->SetAffectCamera(false);
		Stair2_1_Renderer->SetAffectCamera(false);
		Stair2_2_Renderer->SetAffectCamera(false);

		Stage1_Floor_FrontHalf_Entity->GetComponent<Transform>()->SetPosition(Vector2(7296.0f, 824.0f));
		Stage1_Floor_Stair1_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(8320.0f, 696.0f));
		Stage1_Floor_Stair1_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(8480.0f, 632.0f));
		Stage1_Floor_Stair1_3_Entity->GetComponent<Transform>()->SetPosition(Vector2(8608.0f, 568.0f));
		Stage1_Floor_Stair1_4_Entity->GetComponent<Transform>()->SetPosition(Vector2(8704.0f, 504.0f));
		Stage1_Floor_Stair2_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(14272.0f, 696.0f));
		Stage1_Floor_Stair2_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(14272.0f, 632.0f));

		Collider* FrontHalf_Collider = Stage1_Floor_FrontHalf_Entity->AddComponent<Collider>();
		Collider* Stair1_1_Collider = Stage1_Floor_Stair1_1_Entity->AddComponent<Collider>();
		Collider* Stair1_2_Collider = Stage1_Floor_Stair1_2_Entity->AddComponent<Collider>();
		Collider* Stair1_3_Collider = Stage1_Floor_Stair1_3_Entity->AddComponent<Collider>();
		Collider* Stair1_4_Collider = Stage1_Floor_Stair1_4_Entity->AddComponent<Collider>();
		Collider* Stair2_1_Collider = Stage1_Floor_Stair2_1_Entity->AddComponent<Collider>();
		Collider* Stair2_2_Collider = Stage1_Floor_Stair2_2_Entity->AddComponent<Collider>();

		FrontHalf_Collider->SetSize(Vector2(14592.0f, 192.0f));
		Stair1_1_Collider->SetSize(Vector2(1664.0f, 64.0f));
		Stair1_2_Collider->SetSize(Vector2(1344.0f, 64.0f));
		Stair1_3_Collider->SetSize(Vector2(1088.0f, 64.0f));
		Stair1_4_Collider->SetSize(Vector2(896.0f, 64.0f));
		Stair2_1_Collider->SetSize(Vector2(640.0f, 64.0f));
		Stair2_2_Collider->SetSize(Vector2(640.0f, 64.0f));
		#pragma endregion

		#pragma region Player Layer
		Texture* mario_Left = Resources::Load<Texture>(L"Direction_Left"
			, L"..\\Assets\\Mario\\Mario_Left.bmp");
		Texture* mario_Right = Resources::Load<Texture>(L"Direction_Right"
			, L"..\\Assets\\Mario\\Mario_Right.bmp");

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();

		tr->SetPosition(Vector2(400.0f, 690.0f));

		Animator* at = player->AddComponent<Animator>();
		// Dir = Left
		at->CreateAnimation(L"Small_Idle_Left", mario_Left, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Run_Left", mario_Left, Vector2(48.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Jump_Left", mario_Left, Vector2(192.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Fall_Left", mario_Left, Vector2(240.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_LookUp_Left", mario_Left, Vector2(288.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Duck_Left", mario_Left, Vector2(336.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Kick_Left", mario_Left, Vector2(384.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Swim_Left", mario_Left, Vector2(432.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, 0.0f), 0.2f);
		// Dir = Right
		at->CreateAnimation(L"Small_Idle_Right", mario_Right, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Run_Right", mario_Right, Vector2(48.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Jump_Right", mario_Right, Vector2(192.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Fall_Right", mario_Right, Vector2(240.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_LookUp_Right", mario_Right, Vector2(288.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Duck_Right", mario_Right, Vector2(336.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Kick_Right", mario_Right, Vector2(384.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"Small_Swim_Right", mario_Right, Vector2(432.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, 0.0f), 0.2f);

		at->SetScale(Vector2(2.0f, 2.0f));
		at->PlayAnimation(L"Small_Idle_Right", true);
		at->SetAffectedCamera(true);

		Collider* col = player->AddComponent<Collider>();
		col->SetSize(Vector2(96.0f, 96.0f));
		//col->SetOffset(Vector2(0.0f, 0.0f));
		player->AddComponent<Rigidbody>();
		#pragma endregion

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);

		Camera::SetTarget(player);
	}

	void Stage1::Update()
	{
		Scene::Update();
	}

	void Stage1::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
