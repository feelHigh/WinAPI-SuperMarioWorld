#include "ntoFloor.h"
#include "Transform.h"
#include "CustomTime.h"
#include "Animator.h"
#include "SpriteRenderer.h"

namespace nto
{
	Floor::Floor()
	{
	}

	Floor::~Floor()
	{
	}

	void Floor::Initialize()
	{
	}

	void Floor::Update()
	{
		GameObject::Update();

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();

	}

	void Floor::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
