#include "Camera.h"
#include "Application.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"

extern nto::Application application;

namespace nto
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	void Camera::Initalize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = mResolution / 2.0f;
	}

	void Camera::Update()
	{
		if (Controller::GetKey(eKeyCode::Up))
		{
			mLookPosition.y -= 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::Left))
		{
			mLookPosition.x -= 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::Down))
		{
			mLookPosition.y += 300.0f * Time::DeltaTime();
		}
		if (Controller::GetKey(eKeyCode::Right))
		{
			mLookPosition.x += 300.0f * Time::DeltaTime();
		}
		
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		
		mDistance = mLookPosition - (mResolution / 2.0f);
		
	}
}
