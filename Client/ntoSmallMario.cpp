#include "ntoSmallMario.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"
#include "Camera.h"
#include "ntoResources.h"
#include "Texture.h"
#include "Animator.h"

namespace nto
{
	SmallMario::SmallMario()
		: mState(eState::Idle)
		, mDir(eMarioDirection::Right)
	{
	}

	SmallMario::~SmallMario()
	{
	}

	void SmallMario::Initialize()
	{

	}

	void SmallMario::Update()
	{
	}

	void SmallMario::Render(HDC hdc)
	{
	}

	void SmallMario::OnCollisionEnter(Collider* other)
	{
	}

	void SmallMario::OnCollisionStay(Collider* other)
	{
	}

	void SmallMario::OnCollisionExit(Collider* other)
	{
	}
}