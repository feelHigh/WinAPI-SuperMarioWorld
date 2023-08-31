#include "TitleScene.h"
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
	TitleScene::TitleScene()
		: sTimer(1.0f)
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Texture* Intro_Part_0 = Resources::Load<Texture>(L"Intro_0"
			, L"..\\Assets\\Image\\Title\\Intro_Part_0.bmp");
		Texture* Intro_Part_1 = Resources::Load<Texture>(L"Intro_1"
			, L"..\\Assets\\Image\\Title\\Intro_Part_1.bmp");
		Texture* Intro_Part_2 = Resources::Load<Texture>(L"Intro_2"
			, L"..\\Assets\\Image\\Title\\Intro_Part_2.bmp");
		Texture* Intro_Part_3 = Resources::Load<Texture>(L"Intro_3"
			, L"..\\Assets\\Image\\Title\\Intro_Part_3.bmp");
		Texture* Intro_Part_4 = Resources::Load<Texture>(L"Intro_4"
			, L"..\\Assets\\Image\\Title\\Intro_Part_4.bmp");
		Texture* Intro_Part_5 = Resources::Load<Texture>(L"Intro_5"
			, L"..\\Assets\\Image\\Title\\Intro_Part_5.bmp");
		Texture* Intro_Part_6 = Resources::Load<Texture>(L"Intro_6"
			, L"..\\Assets\\Image\\Title\\Intro_Part_6.bmp");
		Texture* Intro_Part_7 = Resources::Load<Texture>(L"Intro_7"
			, L"..\\Assets\\Image\\Title\\Intro_Part_7.bmp");
		Texture* Intro_Part_8 = Resources::Load<Texture>(L"Intro_8"
			, L"..\\Assets\\Image\\Title\\Intro_Part_8.bmp");
		Texture* Intro_Part_9 = Resources::Load<Texture>(L"Intro_9"
			, L"..\\Assets\\Image\\Title\\Intro_Part_9.bmp");

		TitleIntro* Background_Intro_Entity = object::Instantiate<TitleIntro>(eLayerType::Background);

		Transform* trIntro = Background_Intro_Entity->GetComponent<Transform>();

		trIntro->SetPosition(Vector2(512.0f, 448.0f));

		Animator* atIntro = Background_Intro_Entity->AddComponent<Animator>();

		atIntro->CreateAnimation(L"Animation_Intro_Part_0", Intro_Part_0, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_1", Intro_Part_1, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_2", Intro_Part_2, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_3", Intro_Part_3, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_4", Intro_Part_4, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_5", Intro_Part_5, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_6", Intro_Part_6, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_7", Intro_Part_7, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_8", Intro_Part_8, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 32, Vector2(0.0f, 0.0f), 0.1f);
		atIntro->CreateAnimation(L"Animation_Intro_Part_9", Intro_Part_9, Vector2(0.0f, 0.0f), Vector2(512.0f, 448.0f), 12, Vector2(0.0f, 0.0f), 0.1f);

		atIntro->SetScale(Vector2(2.0f, 2.0f));

		bgSound = Resources::Load<Sound>(L"bgmTitle", L"..\\Assets\\Sound\\BGM\\WAV\\01.Title_Bgm.wav");
	}

	void TitleScene::Update()
	{
		Scene::Update();

		#pragma region Sound
		sTimer -= Time::DeltaTime();
		if (sTimer < 0.0f)
		{
		}

		if (Controller::GetKeyDown(eKeyCode::O))
		{
			bgSound->Play(true);
		}
		#pragma endregion

		if (Controller::GetKeyDown(eKeyCode::P))
		{
			bgSound->Stop(true);
			SceneManager::CreateScene<StageWorldMap>(L"StageWorldMap");
			SceneManager::LoadScene(L"StageWorldMap");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
