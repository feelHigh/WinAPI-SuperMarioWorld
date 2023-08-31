#include "Camera.h"
#include "Application.h"
#include "Transform.h"
#include "ntoRigidbody.h"
#include "Controller.h"
#include "CustomTime.h"
#include "CustomMath.h"

extern nto::Application application;

namespace nto
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;
	Vector2 Camera::mOffset = Vector2::Zero;
	float Camera::mThresholdX = 50.0f; // Set threshold size in the x-axis
	float Camera::mThresholdY = 100.0f; // Set threshold size in the y-axis
    float Camera::speed = 5.0f;

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight(); 
		mLookPosition = mResolution / 2.0f;
	}

	void Camera::Update()
	{
        if (mTarget && mTarget->HasComponent<Transform>())
        {
            Transform* tr = mTarget->GetComponent<Transform>();

            // Calculate the target position with the offset
            Vector2 targetPosition = tr->GetPosition() + mOffset;

            // Calculate the distance between the target position and the camera look position
            Vector2 lookDistance = targetPosition - mLookPosition;

            // Check if the distance exceeds the threshold values
            bool isXExceeded = abs(lookDistance.x) > mThresholdX;
            bool isYExceeded = abs(lookDistance.y) > mThresholdY;

            // Perform camera movement only if the distance exceeds the threshold
            if (isXExceeded || isYExceeded)
            {
                // Smoothly move the camera towards the target position based on the distance and speed
                mLookPosition += lookDistance * (speed * Time::DeltaTime());
            }

            // Constraints based on background dimensions
            float bgWidth = 22528;
            float bgHeight = 1720;

            // Apply constraints
            mLookPosition.x = math::Clamp(mLookPosition.x, mResolution.x / 2, bgWidth - mResolution.x / 2);
            mLookPosition.y = math::Clamp(mLookPosition.y, -360, bgHeight - mResolution.y / 2);
        }

        // Update the distance value after the movement
        mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::Reset()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = mResolution / 2.0f; // Set to initial value
		mDistance = Vector2::Zero; // Set to initial value
		mOffset = Vector2::Zero;
	}
}
