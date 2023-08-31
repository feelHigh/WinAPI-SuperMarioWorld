#include "ntoHiddenFloor.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"

namespace nto
{
	HiddenFloor::HiddenFloor()
	{
	}

	HiddenFloor::~HiddenFloor()
	{
	}

	void HiddenFloor::Initialize()
	{
	}

	void HiddenFloor::Update()
	{
		GameObject::Update();

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void HiddenFloor::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void HiddenFloor::OnCollisionEnter(Collider* other)
	{
	}

	void HiddenFloor::OnCollisionStay(Collider* other)
	{
	}

	void HiddenFloor::OnCollisionExit(Collider* other)
	{
	}
}
