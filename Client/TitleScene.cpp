#include "TitleScene.h"
#include "Player.h"
#include "SpriteRenderer.h"
#include "Object.h"

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
		Player* player = object::Instantiate<Player>(eLayerType::Player);
		player->AddComponent<SpriteRenderer>();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
