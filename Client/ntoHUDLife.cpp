#include "ntoHUDLife.h"
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
	Vector2 HUDLife::hlResolution = Vector2::Zero;
	Vector2 HUDLife::hlLookPosition = Vector2::Zero;
	Vector2 HUDLife::hlDistance = Vector2::Zero;
	GameObject* HUDLife::hlTarget = nullptr;

	HUDLife::HUDLife()
		: hlLife(3)
	{
	}

	HUDLife::~HUDLife()
	{
	}

	void HUDLife::Initialize()
	{
		hlResolution.x = application.GetWidth();
		hlResolution.y = application.GetHeight();
		hlLookPosition = hlResolution / 2.0f;
	}

	void HUDLife::Update()
	{
		GameObject::Update();

		// Get the camera's look position
		Vector2 cameraLookPosition = Camera::GetLookPosition();

		// Calculate the HUD position based on the camera's look position and the screen resolution
		Transform* hudTransform = GetComponent<Transform>();
		hudTransform->SetPositionX(cameraLookPosition.x - (hlResolution.x / 2.0f) - 334.f); // Set HUD position based on the camera's look position and screen resolution
		hudTransform->SetPositionY(cameraLookPosition.y - 348.0f);
	}

	void HUDLife::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
