#include "ntoHUDCoins.h"
#include "Application.h"
#include "Player.h"
#include "Camera.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "CustomTime.h"
#include "CustomMath.h"

extern nto::Application application;

namespace nto
{
	Vector2 HUDCoins::hcResolution = Vector2::Zero;
	Vector2 HUDCoins::hcLookPosition = Vector2::Zero;
	Vector2 HUDCoins::hcDistance = Vector2::Zero;
	GameObject* HUDCoins::hcTarget = nullptr;

	HUDCoins::HUDCoins()
		: hcCoins(0)
	{
	}

	HUDCoins::~HUDCoins()
	{
	}

	void HUDCoins::Initialize()
	{
		hcResolution.x = application.GetWidth();
		hcResolution.y = application.GetHeight();
		hcLookPosition = hcResolution / 2.0f;
	}

	void HUDCoins::Update()
	{
		GameObject::Update();

		// Get the camera's look position
		Vector2 cameraLookPosition = Camera::GetLookPosition();
		Transform* hudTransform = GetComponent<Transform>();

		if (hcType == 1)
		{
			hudTransform->SetPositionX(cameraLookPosition.x - (hcResolution.x / 2.0f) + 400.0f); // Set HUD position based on the camera's look position and screen resolution
			hudTransform->SetPositionY(cameraLookPosition.y - 380.0f);
		}
		else if (hcType == 2)
		{
			hudTransform->SetPositionX(cameraLookPosition.x - (hcResolution.x / 2.0f) + 432.0f); // Set HUD position based on the camera's look position and screen resolution
			hudTransform->SetPositionY(cameraLookPosition.y - 380.0f);
		}
	}

	void HUDCoins::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
