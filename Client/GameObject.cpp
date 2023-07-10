#include "GameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace nto
{
	GameObject::GameObject()
	{
		AddComponent<Transform>();
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
}
