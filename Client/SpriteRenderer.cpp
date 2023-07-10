#include "SpriteRenderer.h"
#include "Transform.h"
#include "GameObject.h"

namespace nto
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Ellipse(hdc, 100 + pos.x, 100 + pos.y
			, 200 + pos.x, 200 + pos.y);
	}
}
