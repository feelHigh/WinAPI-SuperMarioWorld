#include "ntoWall.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"

namespace nto
{
	Wall::Wall()
	{
	}

	Wall::~Wall()
	{
	}

	void Wall::Initialize()
	{
	}

	void Wall::Update()
	{
		GameObject::Update();

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void Wall::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Wall::OnCollisionEnter(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());

		if (player)
		{
			Transform* trPlayer = player->GetComponent<Transform>();
			Transform* trBox = GetComponent<Transform>();
			Collider* colPlayer = other;

			float lenX = fabs(trPlayer->GetPosition().x - trBox->GetPosition().x);
			float scaleX = (colPlayer->GetSize().x / 2.0f) + (GetComponent<Collider>()->GetSize().x / 2.0f) + trBox->GetScale().x;

			float lenY = fabs(trPlayer->GetPosition().y - trBox->GetPosition().y);
			float scaleY = (colPlayer->GetSize().y / 2.0f) + (GetComponent<Collider>()->GetSize().y / 2.0f) + trBox->GetScale().y;

			if (lenX < scaleX && lenY < scaleY)
			{
				float overlapX = scaleX - lenX;
				float overlapY = scaleY - lenY;

				if (overlapX < overlapY)
				{
					Vector2 playerPos = trPlayer->GetPosition();
					if (trPlayer->GetPosition().x < trBox->GetPosition().x)
						playerPos.x -= overlapX;
					else
						playerPos.x += overlapX;
					trPlayer->SetPosition(playerPos);
				}
				else
				{
					Vector2 playerPos = trPlayer->GetPosition();
					if (trPlayer->GetPosition().y < trBox->GetPosition().y)
					{
						Rigidbody* rb = player->GetComponent<Rigidbody>();
						rb->SetGround(true);
					}
					else
					{
					}

					trPlayer->SetPosition(playerPos);
				}
			}
		}
	}

	void Wall::OnCollisionStay(Collider* other)
	{
	}

	void Wall::OnCollisionExit(Collider* other)
	{
	}
}
