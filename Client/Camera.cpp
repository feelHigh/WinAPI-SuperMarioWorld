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
    float Camera::speed = 100.0f;

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = mResolution / 2.0f;
	}

	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();

			mLookPosition = tr->GetPosition() + mOffset;
		}
		
		mDistance = mLookPosition - (mResolution / 2.0f);
	}
    //void Camera::Update()
    //{
    //    if (mTarget)
    //    {
    //        Transform* tr = mTarget->GetComponent<Transform>();
    //        nto::Rigidbody* rb = mTarget->GetComponent<nto::Rigidbody>(); // Get Rigidbody component

    //        Vector2 follow = tr->GetPosition();

    //        // Calculate differences
    //        float xDifference = std::abs(mLookPosition.x - follow.x);
    //        float yDifference = std::abs(mLookPosition.y - follow.y);

    //        Vector2 threshold = CalculateThreshold();

    //        Vector2 newPosition = mLookPosition;
    //        if (xDifference >= threshold.x)
    //        {
    //            newPosition.x = follow.x + mOffset.x;
    //        }
    //        if (yDifference >= threshold.y)
    //        {
    //            newPosition.y = follow.y + mOffset.y;
    //        }

    //        float moveSpeed = rb ? (rb->GetVelocity().length() > speed ? rb->GetVelocity().length() : speed) : speed;


    //        // Move the camera towards the new position (assumes you have or will create a MoveTowards equivalent function)
    //        mLookPosition = MoveTowards(mLookPosition, newPosition, moveSpeed * Time::DeltaTime());
    //    }
    //}

    //Vector2 Camera::CalculateThreshold()
    //{
    //    // Replace these with appropriate values if different in your framework
    //    Vector2 aspect(mResolution.x / mResolution.y, 1);
    //    Vector2 t = Vector2(mResolution.x * aspect.x, mResolution.y * aspect.y);

    //    t.x -= mOffset.x;
    //    t.y -= mOffset.y;

    //    return t;
    //}

    //Vector2 Camera::MoveTowards(Vector2 current, Vector2 target, float maxDistanceDelta)
    //{
    //    Vector2 a = target - current;
    //    float magnitude = a.length();
    //    if (magnitude <= maxDistanceDelta || magnitude == 0.0f)
    //    {
    //        return target;
    //    }
    //    return current + a / magnitude * maxDistanceDelta;
    //}
}
