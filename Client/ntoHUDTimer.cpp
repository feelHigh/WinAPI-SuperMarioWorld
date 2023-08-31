#include "ntoHUDTimer.h"
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
	Vector2 HUDTimer::htResolution = Vector2::Zero;
	Vector2 HUDTimer::htLookPosition = Vector2::Zero;
	Vector2 HUDTimer::htDistance = Vector2::Zero;
	GameObject* HUDTimer::htTarget = nullptr;

	HUDTimer::HUDTimer()
		: htTimer(600)
	{
	}

	HUDTimer::~HUDTimer()
	{
	}

	void HUDTimer::Initialize()
	{
		htResolution.x = application.GetWidth();
		htResolution.y = application.GetHeight();
		htLookPosition = htResolution / 2.0f;
	}

	void HUDTimer::Update()
	{
		GameObject::Update();

		// Get the camera's look position
		Vector2 cameraLookPosition = Camera::GetLookPosition();
		Transform* hudTransform = GetComponent<Transform>();

		if (htType == 1)
		{
			hudTransform->SetPositionX(cameraLookPosition.x - (htResolution.x / 2.0f) + 112.0f); // Set HUD position based on the camera's look position and screen resolution
			hudTransform->SetPositionY(cameraLookPosition.y - 344.0f);
		}
		else if (htType == 2)
		{
			hudTransform->SetPositionX(cameraLookPosition.x - (htResolution.x / 2.0f) + 144.0f); // Set HUD position based on the camera's look position and screen resolution
			hudTransform->SetPositionY(cameraLookPosition.y - 344.0f);
		}
		else if (htType == 3)
		{
			hudTransform->SetPositionX(cameraLookPosition.x - (htResolution.x / 2.0f) + 176.0f); // Set HUD position based on the camera's look position and screen resolution
			hudTransform->SetPositionY(cameraLookPosition.y - 344.0f);
		}
	}

	void HUDTimer::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
