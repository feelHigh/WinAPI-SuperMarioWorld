#include "Background.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	BackGround::BackGround()
		: ePhase(0)
		, eTimer(0.6f)
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

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		//float alpha = sr->GetAlpha();
		//alpha -= 0.2f * Time::DeltaTime();
		//sr->SetAlpha(alpha);
	}

	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
