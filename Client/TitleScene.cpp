#include "TitleScene.h"
#include "Player.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "Controller.h"
#include "Texture.h"
#include "Transform.h"
#include "ntoResources.h"
#include "Background.h"
#include "Camera.h"

namespace nto
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Texture* image = Resources::Load<Texture>(L"TitleBackGroundImage"
			, L"..\\Assets\\Image\\Background\\Title-1-alpha.bmp");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(4.0f, 4.0f));
		bgsr->SetAffectCamera(false);
		bg->GetComponent<Transform>()->SetPosition(Vector2(512.0f, 448.0f));
	}

	void TitleScene::Update()
	{
		Scene::Update();


		if (Controller::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
		if (Controller::GetKeyDown(eKeyCode::W))
		{
			SceneManager::LoadScene(L"StageWorldMap");
		}
		if (Controller::GetKeyDown(eKeyCode::E))
		{
			SceneManager::LoadScene(L"Stage1");
		}
		if (Controller::GetKeyDown(eKeyCode::R))
		{
			SceneManager::LoadScene(L"Stage2");
		}
		if (Controller::GetKeyDown(eKeyCode::T))
		{
			SceneManager::LoadScene(L"Stage3");
		}
		if (Controller::GetKeyDown(eKeyCode::Y))
		{
			SceneManager::LoadScene(L"StageBoss");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
