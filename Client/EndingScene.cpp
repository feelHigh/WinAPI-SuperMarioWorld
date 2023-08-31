#include "EndingScene.h"
#include "StageWorldMap.h"
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
	EndingScene::EndingScene()
	{
	}

	EndingScene::~EndingScene()
	{
	}

	void EndingScene::Initialize()
	{
		Texture* Outro_Part_0 = Resources::Load<Texture>(L"Outro_0"
			, L"..\\Assets\\Image\\Ending\\Outro_Part_0.bmp");
		Texture* Outro_Part_1 = Resources::Load<Texture>(L"Outro_1"
			, L"..\\Assets\\Image\\Ending\\Outro_Part_1.bmp");
		Texture* Outro_Part_2 = Resources::Load<Texture>(L"Outro_2"
			, L"..\\Assets\\Image\\Ending\\Outro_Part_2.bmp");
		Texture* Outro_Part_3 = Resources::Load<Texture>(L"Outro_3"
			, L"..\\Assets\\Image\\Ending\\Outro_Part_3.bmp");
		Texture* Outro_Part_4 = Resources::Load<Texture>(L"Outro_4"
			, L"..\\Assets\\Image\\Ending\\Outro_Part_4.bmp");
		Texture* Outro_Part_5 = Resources::Load<Texture>(L"Outro_5"
			, L"..\\Assets\\Image\\Ending\\Outro_Part_5.bmp");
		Texture* Outro_Part_6 = Resources::Load<Texture>(L"Outro_6"
			, L"..\\Assets\\Image\\Ending\\Outro_Part_6.bmp");

		EndingOutro* Background_Outro_Entity = object::Instantiate<EndingOutro>(eLayerType::Background);

		Transform* trOutro = Background_Outro_Entity->GetComponent<Transform>();

		trOutro->SetPosition(Vector2(512.0f, 448.0f));

		Animator* atOutro = Background_Outro_Entity->AddComponent<Animator>();

		atOutro->CreateAnimation(L"Animation_Outro_Part_0", Outro_Part_0, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atOutro->CreateAnimation(L"Animation_Outro_Part_1", Outro_Part_1, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atOutro->CreateAnimation(L"Animation_Outro_Part_2", Outro_Part_2, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atOutro->CreateAnimation(L"Animation_Outro_Part_3", Outro_Part_3, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atOutro->CreateAnimation(L"Animation_Outro_Part_4", Outro_Part_4, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atOutro->CreateAnimation(L"Animation_Outro_Part_5", Outro_Part_5, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atOutro->CreateAnimation(L"Animation_Outro_Part_6", Outro_Part_6, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 30, Vector2(0.0f, 0.0f), 0.1f);

		atOutro->SetScale(Vector2(2.0f, 2.0f));

		bgSound = Resources::Load<Sound>(L"bgmEnding", L"..\\Assets\\Sound\\BGM\\WAV\\21.Koopa_Junior_Castle_Clear_Demo_Bgm.wav");
	}

	void EndingScene::Update()
	{
		Scene::Update();

		if (Controller::GetKeyDown(eKeyCode::O))
		{
			bgSound->Play(false);
		}
	}

	void EndingScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
