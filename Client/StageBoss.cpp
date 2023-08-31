#include "StageBoss.h"
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
#include "SceneManager.h"
#include "EndingScene.h"

namespace nto
{
	StageBoss::StageBoss()
		: stageTimer(600.0f)
	{
	}

	StageBoss::~StageBoss()
	{
	}

	void StageBoss::Initialize()
	{
		#pragma region Background Layer
		Texture* Background_Image = Resources::Load<Texture>(L"StageBoss_BackGround"
			, L"..\\Assets\\Image\\Background\\StageBoss_Background.bmp");

		BackGround* BackGround_Entity = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* BackGround_Renderer = BackGround_Entity->AddComponent<SpriteRenderer>();
		BackGround_Renderer->SetImage(Background_Image);
		BackGround_Renderer->SetScale(Vector2(4.0f, 4.0f));
		BackGround_Entity->GetComponent<Transform>()->SetPosition(Vector2(512.0f, 448.0f));
		#pragma endregion

		#pragma region Floor/Wall Layer
		Floor* Floor_Bottom_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Wall* Wall_Left_Entity = object::Instantiate<Wall>(eLayerType::Floor);
		Wall* Wall_Right_Entity = object::Instantiate<Wall>(eLayerType::Floor);

		Transform* trFloorBottom = Floor_Bottom_Entity->GetComponent<Transform>();
		Transform* trWallLeft = Wall_Left_Entity->GetComponent<Transform>();
		Transform* trWallRight = Wall_Right_Entity->GetComponent<Transform>();

		trFloorBottom->SetPosition(Vector2(512.0f, 740.0f));
		trWallLeft->SetPosition(Vector2(64.0f, 450.0f));
		trWallRight->SetPosition(Vector2(960.0f, 450.0f));

		Collider* Floor_Bottom_Collider = Floor_Bottom_Entity->AddComponent<Collider>();
		Collider* Wall_Left_Collider = Wall_Left_Entity->AddComponent<Collider>();
		Collider* Wall_Right_Collider = Wall_Right_Entity->AddComponent<Collider>();

		Floor_Bottom_Collider->SetSize(Vector2(832.0f, 64.0f));
		Wall_Left_Collider->SetSize(Vector2(64.0f, 512.0f));
		Wall_Right_Collider->SetSize(Vector2(64.0f, 512.0f));
		#pragma endregion

		#pragma region Player Layer
		Texture* Mario_Left_Image = Resources::Load<Texture>(L"Direction_Left"
			, L"..\\Assets\\Mario\\Mario_Left.bmp");
		Texture* Mario_Right_Image = Resources::Load<Texture>(L"Direction_Right"
			, L"..\\Assets\\Mario\\Mario_Right.bmp");

		player = object::Instantiate<Player>(eLayerType::Player);

		player->SetPlayerClass(Player::eMarioClass::Super);

		trPlayer = player->GetComponent<Transform>();

		trPlayer->SetPosition(Vector2(512.0f, 320.0f));

		Animator* atPlayer = player->AddComponent<Animator>();
		// 방향 = 왼쪽
		// <Small Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Small_Idle_Left", Mario_Left_Image, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Run_Left", Mario_Left_Image, Vector2(48.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Jump_Left", Mario_Left_Image, Vector2(192.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Fall_Left", Mario_Left_Image, Vector2(240.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_LookUp_Left", Mario_Left_Image, Vector2(288.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Duck_Left", Mario_Left_Image, Vector2(336.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Kick_Left", Mario_Left_Image, Vector2(384.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Swim_Left", Mario_Left_Image, Vector2(432.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);

		// <Super Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Super_Idle_Left", Mario_Left_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Run_Left", Mario_Left_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Jump_Left", Mario_Left_Image, Vector2(192.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Fall_Left", Mario_Left_Image, Vector2(240.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_LookUp_Left", Mario_Left_Image, Vector2(288.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Duck_Left", Mario_Left_Image, Vector2(336.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Kick_Left", Mario_Left_Image, Vector2(384.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Swim_Left", Mario_Left_Image, Vector2(432.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		// <Fire Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Fire_Idle_Left", Mario_Left_Image, Vector2(0.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Run_Left", Mario_Left_Image, Vector2(48.0f, 96.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Jump_Left", Mario_Left_Image, Vector2(192.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Fall_Left", Mario_Left_Image, Vector2(240.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_LookUp_Left", Mario_Left_Image, Vector2(288.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Duck_Left", Mario_Left_Image, Vector2(336.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Kick_Left", Mario_Left_Image, Vector2(384.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Swim_Left", Mario_Left_Image, Vector2(432.0f, 96.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		// 방향 = 오른쪽
		// <Small Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Small_Idle_Right", Mario_Right_Image, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Run_Right", Mario_Right_Image, Vector2(48.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Jump_Right", Mario_Right_Image, Vector2(192.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Fall_Right", Mario_Right_Image, Vector2(240.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_LookUp_Right", Mario_Right_Image, Vector2(288.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Duck_Right", Mario_Right_Image, Vector2(336.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Kick_Right", Mario_Right_Image, Vector2(384.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Swim_Right", Mario_Right_Image, Vector2(432.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);

		// <Super Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Super_Idle_Right", Mario_Right_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Run_Right", Mario_Right_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Jump_Right", Mario_Right_Image, Vector2(192.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Fall_Right", Mario_Right_Image, Vector2(240.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_LookUp_Right", Mario_Right_Image, Vector2(288.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Duck_Right", Mario_Right_Image, Vector2(336.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Kick_Right", Mario_Right_Image, Vector2(384.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Swim_Right", Mario_Right_Image, Vector2(432.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		// <Fire Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Fire_Idle_Right", Mario_Right_Image, Vector2(0.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Run_Right", Mario_Right_Image, Vector2(48.0f, 96.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Jump_Right", Mario_Right_Image, Vector2(192.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Fall_Right", Mario_Right_Image, Vector2(240.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_LookUp_Right", Mario_Right_Image, Vector2(288.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Duck_Right", Mario_Right_Image, Vector2(336.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Kick_Right", Mario_Right_Image, Vector2(384.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Swim_Right", Mario_Right_Image, Vector2(432.0f, 96.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		atPlayer->SetScale(Vector2(4.0f, 4.0f));

		if (player->GetPlayerClass() == Player::eMarioClass::Small)
		{
			atPlayer->PlayAnimation(L"Animation_Small_Idle_Right", true);
		}
		if (player->GetPlayerClass() == Player::eMarioClass::Super)
		{
			atPlayer->PlayAnimation(L"Animation_Super_Idle_Right", true);
		}
		if (player->GetPlayerClass() == Player::eMarioClass::Fire)
		{
			atPlayer->PlayAnimation(L"Animation_Fire_Idle_Right", true);
		}
		atPlayer->SetAffectedCamera(true);

		colPlayer = player->AddComponent<Collider>();
		player->AddComponent<Rigidbody>();
		#pragma endregion

		#pragma region Enemy Layer
		Texture* Morton_Ground_Image = Resources::Load<Texture>(L"Morton_Ground"
			, L"..\\Assets\\Image\\Enemies\\Morton_1.bmp");
		Texture* Morton_Left_Wall_Image = Resources::Load<Texture>(L"Morton_Left_Wall"
			, L"..\\Assets\\Image\\Enemies\\Morton_2.bmp");
		Texture* Morton_Ceiling_Image = Resources::Load<Texture>(L"Morton_Ceiling"
			, L"..\\Assets\\Image\\Enemies\\Morton_3.bmp");
		Texture* Morton_Right_Wall_Image = Resources::Load<Texture>(L"Morton_Right_Wall"
			, L"..\\Assets\\Image\\Enemies\\Morton_4.bmp");
		Texture* Morton_Fall_Image = Resources::Load<Texture>(L"Morton_Fall"
			, L"..\\Assets\\Image\\Enemies\\Morton_Fall.bmp");
		Texture* Morton_Hit_Image = Resources::Load<Texture>(L"Morton_Hit"
			, L"..\\Assets\\Image\\Enemies\\Morton_Hit.bmp");

		Morton_Entity = object::Instantiate<Morton>(eLayerType::Monster);

		Transform* trMorton = Morton_Entity->GetComponent<Transform>();

		trMorton->SetPosition(Vector2(864.0f, 644.0f));

		Animator* atMorton = Morton_Entity->AddComponent<Animator>();

		atMorton->CreateAnimation(L"Animation_Morton_Ground", Morton_Ground_Image, Vector2(0.0f, 0.0f), Vector2(24.0f, 32.0f), 3, Vector2(0.0f, 0.0f), 0.1f);
		atMorton->CreateAnimation(L"Animation_Morton_Ceiling", Morton_Ceiling_Image, Vector2(0.0f, 0.0f), Vector2(24.0f, 32.0f), 3, Vector2(0.0f, 0.0f), 0.1f);
		atMorton->CreateAnimation(L"Animation_Morton_Left_Wall", Morton_Left_Wall_Image, Vector2(0.0f, 0.0f), Vector2(32.0f, 24.0f), 3, Vector2(0.0f, 0.0f), 0.1f);
		atMorton->CreateAnimation(L"Animation_Morton_Right_Wall", Morton_Right_Wall_Image, Vector2(0.0f, 0.0f), Vector2(32.0f, 24.0f), 3, Vector2(0.0f, 0.0f), 0.1f);
		atMorton->CreateAnimation(L"Animation_Morton_Fall", Morton_Fall_Image, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		//atMorton->CreateAnimation(L"Animation_Morton_Hit", Morton_Hit_Image, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), 1, Vector2(0.0f, 0.0f), 0.1f);

		atMorton->SetScale(Vector2(4.0f, 4.0f));

		atMorton->PlayAnimation(L"Animation_Morton_Ground", true);

		Collider* colMorton = Morton_Entity->AddComponent<Collider>();

		colMorton->SetSize(Vector2(96.0f, 120.0f));
		colMorton->SetOffset(Vector2(0.0f, 8.0f));
		#pragma endregion

		#pragma region UI Layer
		Texture* HUD_Base_Image = Resources::Load<Texture>(L"StageBoss_HUD_Base"
			, L"..\\Assets\\HUD\\HUD_Base.bmp");
		Texture* HUD_NormalNum_Image = Resources::Load<Texture>(L"StageBoss_HUD_NormalNum"
			, L"..\\Assets\\HUD\\NormalNum.bmp");
		Texture* HUD_CountdownNum_Image = Resources::Load<Texture>(L"StageBoss_HUD_Coundown"
			, L"..\\Assets\\HUD\\CountdownNum.bmp");

		HUD_Base_Entity = object::Instantiate<HUD>(eLayerType::UI);
		HUD_Life_Entity = object::Instantiate<HUDLife>(eLayerType::UI);
		HUD_Timer_Entity_1 = object::Instantiate<HUDTimer>(eLayerType::UI);
		HUD_Timer_Entity_2 = object::Instantiate<HUDTimer>(eLayerType::UI);
		HUD_Timer_Entity_3 = object::Instantiate<HUDTimer>(eLayerType::UI);
		HUD_Coins_Entity_1 = object::Instantiate<HUDCoins>(eLayerType::UI);
		HUD_Coins_Entity_2 = object::Instantiate<HUDCoins>(eLayerType::UI);

		HUD_Timer_Entity_1->SetType(1);
		HUD_Timer_Entity_2->SetType(2);
		HUD_Timer_Entity_3->SetType(3);
		HUD_Coins_Entity_1->SetType(1);
		HUD_Coins_Entity_2->SetType(2);

		trHUD_Base = HUD_Base_Entity->GetComponent<Transform>();
		trHUD_Life = HUD_Life_Entity->GetComponent<Transform>();
		trHUD_Timer_1 = HUD_Timer_Entity_1->GetComponent<Transform>();
		trHUD_Timer_2 = HUD_Timer_Entity_2->GetComponent<Transform>();
		trHUD_Timer_3 = HUD_Timer_Entity_3->GetComponent<Transform>();
		trHUD_Coins_1 = HUD_Coins_Entity_1->GetComponent<Transform>();
		trHUD_Coins_2 = HUD_Coins_Entity_2->GetComponent<Transform>();

		atHUD_Base = HUD_Base_Entity->AddComponent<Animator>();
		atHUD_Life = HUD_Life_Entity->AddComponent<Animator>();
		atHUD_Timer_1 = HUD_Timer_Entity_1->AddComponent<Animator>();
		atHUD_Timer_2 = HUD_Timer_Entity_2->AddComponent<Animator>();
		atHUD_Timer_3 = HUD_Timer_Entity_3->AddComponent<Animator>();
		atHUD_Coins_1 = HUD_Coins_Entity_1->AddComponent<Animator>();
		atHUD_Coins_2 = HUD_Coins_Entity_2->AddComponent<Animator>();

		atHUD_Base->CreateAnimation(L"Animation_HUD_Base", HUD_Base_Image, Vector2(0.0f, 0.0f), Vector2(256.0f, 47.0f), 1);
		atHUD_Life->CreateAnimation(L"Animation_HUD_Life", HUD_NormalNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Timer_1->CreateAnimation(L"Animation_HUD_Timer_1", HUD_CountdownNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Timer_2->CreateAnimation(L"Animation_HUD_Timer_2", HUD_CountdownNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Timer_3->CreateAnimation(L"Animation_HUD_Timer_3", HUD_CountdownNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Coins_1->CreateAnimation(L"Animation_HUD_Coins_1", HUD_NormalNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Coins_2->CreateAnimation(L"Animation_HUD_Coins_2", HUD_NormalNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);

		atHUD_Base->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Life->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Timer_1->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Timer_2->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Timer_3->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Coins_1->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Coins_2->SetScale(Vector2(4.0f, 4.0f));

		atHUD_Base->PlayAnimation(L"Animation_HUD_Base", false);
		atHUD_Life->PlayAnimation(L"Animation_HUD_Life", true);
		atHUD_Timer_1->PlayAnimation(L"Animation_HUD_Timer_1", true);
		atHUD_Timer_2->PlayAnimation(L"Animation_HUD_Timer_2", true);
		atHUD_Timer_3->PlayAnimation(L"Animation_HUD_Timer_3", true);
		atHUD_Coins_1->PlayAnimation(L"Animation_HUD_Coins_1", true);
		atHUD_Coins_2->PlayAnimation(L"Animation_HUD_Coins_2", true);
		#pragma endregion

		#pragma region Collision Manager
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Environment, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Foreground, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Item, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::PlayerAttack, eLayerType::HiddenFloor, true);
		#pragma endregion

		#pragma region Sound
		bgSound = Resources::Load<Sound>(L"bgmBoss", L"..\\Assets\\Sound\\BGM\\WAV\\20.Koopa_Junior_Bgm.wav");
		bgSound->Play(true);
		#pragma endregion

		/*Camera::SetTarget(BackGround_Entity);
		Camera::SetOffset(Vector2(0.0f, -218.0f));*/
	}

	void StageBoss::Update()
	{
		Scene::Update();

		#pragma region Mario Class
		if (player->GetPlayerClass() == Player::eMarioClass::Small)
		{
			colPlayer->SetSize(Vector2(64.0f, 80.0f)); // Small Mario
		}
		if (player->GetPlayerClass() == Player::eMarioClass::Super)
		{
			colPlayer->SetSize(Vector2(64.0f, 112.0f)); // Super, Fire Mario
		}
		if (player->GetPlayerClass() == Player::eMarioClass::Fire)
		{
			colPlayer->SetSize(Vector2(64.0f, 112.0f)); // Super, Fire Mario
		}
		#pragma endregion

		#pragma region HUD Update
		stageTimer -= Time::DeltaTime();

		int hundreds = (int)stageTimer / 100;
		int tens = ((int)stageTimer % 100) / 10;
		int ones = (int)stageTimer % 10;

		atHUD_Timer_1->SetFrame(hundreds);
		atHUD_Timer_2->SetFrame(tens);
		atHUD_Timer_3->SetFrame(ones);

		atHUD_Life->SetFrame(3);
		atHUD_Coins_1->SetFrame(0);
		atHUD_Coins_2->SetFrame(0);
		#pragma endregion

		killCount = Morton_Entity->GetHitCount();

		if (Controller::GetKeyDown(eKeyCode::P))
		{
			bgSound->Stop(true);
			SceneManager::LoadScene(L"StageWorldMap");
		}
		if (Controller::GetKeyDown(eKeyCode::L) || killCount == 3)
		{
			bgSound->Stop(true);
			SceneManager::CreateScene<EndingScene>(L"EndingScene");
			SceneManager::LoadScene(L"EndingScene");
		}
	}

	void StageBoss::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
