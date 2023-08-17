#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"

namespace nto
{
	Transform::Transform()
		: Component(eComponentType::Transform)
		, mRotation(0.0f)
		, mScale(4.0f, 4.0f) // Initialize scale to (1, 1)
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
