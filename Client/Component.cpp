#include "Component.h"

namespace nto
{
	Component::Component(eComponentType type)
		: mType(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
	}

	void Component::Update()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}
