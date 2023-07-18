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
		// 바닥 만들 예정
		Texture* floorImage = Resources::Load<Texture>(L"Stage1_FloorImage"
			, L"..\\Assets\\Image\\Floor-Tiles\\ground_Middle.bmp");

		Floor* fl = object::Instantiate<Floor>(eLayerType::Floor);
		SpriteRenderer* flsr = fl->AddComponent<SpriteRenderer>();
		flsr->SetImage(floorImage);
		flsr->SetScale(Vector2(2.0f, 2.0f));
		flsr->SetAffectCamera(false);
		fl->GetComponent<Transform>()->SetPosition(Vector2(500.0f, 850.0f));
		#pragma endregion

		#pragma region Player Layer
		Texture* image = Resources::Load<Texture>(L"SmallMario_RunLeft"
			, L"..\\Assets\\Image\\Mario\\SmallMario\\RunLeft.bmp");
		Texture* image2 = Resources::Load<Texture>(L"SmallMario_RunRight"
			, L"..\\Assets\\Image\\Mario\\SmallMario\\RunRight.bmp");
		Texture* image3 = Resources::Load<Texture>(L"SmallMario_DuckDown"
			, L"..\\Assets\\Image\\Mario\\SmallMario\\DuckDown_Right.bmp");

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();

		tr->SetPosition(Vector2(400.0f, 710.0f));

		Animator* at = player->AddComponent<Animator>();
		at->CreateAnimation(L"SmallMario_RunLeft", image, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"SmallMario_RunRight", image2, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, 0.0f), 0.2f);
		at->CreateAnimation(L"SmallMario_DuckDown", image3, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1);
		at->SetScale(Vector2(2.0f, 2.0f));
		at->SetAffectedCamera(true);
		#pragma endregion

		#pragma region Monster Layer
		Texture* koopaGreen_Right = Resources::Load<Texture>(L"koopaGreen_Right"
			, L"..\\Assets\\Image\\Enemies\\KoopaTroopa_Green_Right.bmp");
		Texture* paraGreen_Right = Resources::Load<Texture>(L"paraGreen_Right"
			, L"..\\Assets\\Image\\Enemies\\ParaTroopa_Green_Right.bmp");
		Texture* charginChuck_Right = Resources::Load<Texture>(L"charginChuck_Right"
			, L"..\\Assets\\Image\\Enemies\\Chargin_Chuck_Right.bmp");
		Texture* piranhaPlant_Jump = Resources::Load<Texture>(L"piranha_Jump"
			, L"..\\Assets\\Image\\Enemies\\Jumping_Piranha_Plant.bmp");
		Texture* iggyBoss_Right = Resources::Load<Texture>(L"iggy_Right"
			, L"..\\Assets\\Image\\Enemies\\Iggy_Base.bmp");

		Monster* koopaGreen = object::Instantiate<Monster>(eLayerType::Monster);
		Monster* paraGreen = object::Instantiate<Monster>(eLayerType::Monster);
		Monster* charginChuck = object::Instantiate<Monster>(eLayerType::Monster);
		Monster* piranhaPlant = object::Instantiate<Monster>(eLayerType::Monster);
		Monster* iggyBoss = object::Instantiate<Monster>(eLayerType::Monster);
		Transform* kgTr = koopaGreen->GetComponent<Transform>();
		Transform* pgTr = paraGreen->GetComponent<Transform>();
		Transform* ccTr = charginChuck->GetComponent<Transform>();
		Transform* pirTr = piranhaPlant->GetComponent<Transform>();
		Transform* ibossTr = iggyBoss->GetComponent<Transform>();

		kgTr->SetPosition(Vector2(500.0f, 100.0f));
		pgTr->SetPosition(Vector2(500.0f, 200.0f));
		ccTr->SetPosition(Vector2(500.0f, 300.0f));
		pirTr->SetPosition(Vector2(500.0f, 400.0f));
		ibossTr->SetPosition(Vector2(500.0f, 500.0f));

		Animator* kgAni = koopaGreen->AddComponent<Animator>();
		Animator* pgAni = paraGreen->AddComponent<Animator>();
		Animator* ccAni = charginChuck->AddComponent<Animator>();
		Animator* pirAni = piranhaPlant->AddComponent<Animator>();
		Animator* ibossAni = iggyBoss->AddComponent<Animator>();
		kgAni->CreateAnimation(L"koopaGreen_Right", koopaGreen_Right, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.3f);
		pgAni->CreateAnimation(L"paraGreen_Right", paraGreen_Right, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.3f);
		ccAni->CreateAnimation(L"charginChuck_Right", charginChuck_Right, Vector2(0.0f, 0.0f), Vector2(26.0f, 26.0f), 6, Vector2(0.0f, 0.0f), 0.2f);
		pirAni->CreateAnimation(L"piranha_Jump", piranhaPlant_Jump, Vector2(0.0f, 0.0f), Vector2(16.0f, 21.0f), 2, Vector2(0.0f, 0.0f), 0.3f);
		ibossAni->CreateAnimation(L"iggy_Right", iggyBoss_Right, Vector2(0.0f, 0.0f), Vector2(25.0f, 30.0f), 3, Vector2(0.0f, 0.0f), 0.1f);

		kgAni->SetScale(Vector2(2.0f, 2.0f));
		pgAni->SetScale(Vector2(2.0f, 2.0f));
		ccAni->SetScale(Vector2(2.0f, 2.0f));
		pirAni->SetScale(Vector2(2.0f, 2.0f));
		ibossAni->SetScale(Vector2(2.0f, 2.0f));

		kgAni->PlayAnimation(L"koopaGreen_Right", true);
		pgAni->PlayAnimation(L"paraGreen_Right", true);
		ccAni->PlayAnimation(L"charginChuck_Right", true);
		pirAni->PlayAnimation(L"piranha_Jump", true);
		ibossAni->PlayAnimation(L"iggy_Right", true);
		#pragma endregion
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
