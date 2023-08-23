#include "ntoHUD.h"
#include "Application.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "CustomTime.h"
#include "CustomMath.h"

extern nto::Application application;

namespace nto
{
	int HUD::coinCount = 0;

	HUD::HUD()
	{
	}

	HUD::~HUD()
	{
	}

	void HUD::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}

	void HUD::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void HUD::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void HUD::DrawCoinCount(HDC hdc, int x, int y, int count)
	{
	}
}
