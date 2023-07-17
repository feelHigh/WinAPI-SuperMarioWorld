#include "Background.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"
#include "SpriteRenderer.h"

namespace nto
{
	BackGround::BackGround()
	{
	}

	BackGround::~BackGround()
	{
	}

	void BackGround::Initialize()
	{
	}

	void BackGround::Update()
	{
		GameObject::Update();

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();

		//float alpha = sr->GetAlpha();
		//alpha -= 0.2f * Time::DeltaTime();
		//sr->SetAlpha(alpha);
	}

	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
