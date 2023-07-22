#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"

namespace nto
{
	Transform::Transform()
		: Component(eComponentType::Transform)
		, mRotation(0.0f)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
	}

	void Transform::Render(HDC hdc)
	{
	}
}
