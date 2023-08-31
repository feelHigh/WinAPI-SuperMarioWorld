#include "ntoHUD.h"
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
	Vector2 HUD::hResolution = Vector2::Zero;
	Vector2 HUD::hLookPosition = Vector2::Zero;
	Vector2 HUD::hDistance = Vector2::Zero;
	GameObject* HUD::hTarget = nullptr;

	HUD::HUD()
	{
	}

	HUD::~HUD()
	{
	}

	void HUD::Initialize()
	{
		hResolution.x = application.GetWidth();
		hResolution.y = application.GetHeight();
		hLookPosition = hResolution / 2.0f;
	}

	void HUD::Update()
	{
		GameObject::Update();

		// Get the camera's look position
		Vector2 cameraLookPosition = Camera::GetLookPosition();

		// Calculate the HUD position based on the camera's look position and the screen resolution
		Transform* hudTransform = GetComponent<Transform>();
		hudTransform->SetPositionX(cameraLookPosition.x - (hResolution.x / 2.0f)); // Set HUD position based on the camera's look position and screen resolution
		hudTransform->SetPositionY(cameraLookPosition.y - 360.0f);
	}

	void HUD::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
