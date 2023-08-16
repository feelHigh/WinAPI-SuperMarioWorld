#include "ntoEnvironmentWoodBall.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"

namespace nto
{
	EnvironmentWoodBall::EnvironmentWoodBall()
		: pRadius(352.0f)
		, pAngle(-90.0f)
		, pSpeed(0.8f)
	{
	}

	EnvironmentWoodBall::~EnvironmentWoodBall()
	{
	}

	void EnvironmentWoodBall::Initialize()
	{
	}

	void EnvironmentWoodBall::Update()
	{
		GameObject::Update();

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Vector2 posCenter = this->GetCenter();
		pAngle += pSpeed * Time::DeltaTime();
		float newX = posCenter.x + pRadius * cos(pAngle);
		float newY = posCenter.y + pRadius * sin(pAngle);

		pos.x = newX;
		pos.y = newY;

		tr->SetPosition(pos);
	}

	void EnvironmentWoodBall::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void EnvironmentWoodBall::OnCollisionEnter(Collider* other)
	{
	}

	void EnvironmentWoodBall::OnCollisionStay(Collider* other)
	{
	}

	void EnvironmentWoodBall::OnCollisionExit(Collider* other)
	{
	}
}
