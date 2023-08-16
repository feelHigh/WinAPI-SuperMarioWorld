#include "StageWorldMap.h"
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
	StageWorldMap::StageWorldMap()
	{
	}

	StageWorldMap::~StageWorldMap()
	{
	}

	void StageWorldMap::Initialize()
	{
		Texture* image = Resources::Load<Texture>(L"StageWorldMapBackGroundImage"
			, L"..\\Assets\\Image\\Background\\StageWorldMap_Background.bmp");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(4.0f, 4.0f));
		bgsr->SetAffectCamera(false);
		bg->GetComponent<Transform>()->SetPosition(Vector2(512.0f, 448.0f));
	}

	void StageWorldMap::Update()
	{
		Scene::Update();


	}

	void StageWorldMap::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
