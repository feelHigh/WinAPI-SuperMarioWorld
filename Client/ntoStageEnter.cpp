#include "ntoStageEnter.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	StageEnter::StageEnter()
	{
	}

	StageEnter::~StageEnter()
	{
	}

	void StageEnter::Initialize()
	{
	}

	void StageEnter::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
	}

	void StageEnter::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
