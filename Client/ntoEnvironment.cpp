#include "ntoEnvironment.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"

namespace nto
{
	Environment::Environment()
	{
	}

	Environment::~Environment()
	{
	}

	void Environment::Initialize()
	{
	}

	void Environment::Update()
	{
        GameObject::Update();

        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        tr->SetPosition(pos);

        SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void Environment::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Environment::OnCollisionEnter(Collider* other)
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

            if (lenX < scaleX || lenY < scaleY)
            {
                float overlapX = scaleX - lenX;
                float overlapY = scaleY - lenY;

                // Separate the player from the box in the direction of the smallest overlap
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
                        // Set the setGround to true when colliding on top of the box
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

	void Environment::OnCollisionStay(Collider* other)
	{
	}

	void Environment::OnCollisionExit(Collider* other)
	{
        Player* player = dynamic_cast<Player*>(other->GetOwner());
        if (player)
        {
            player->GetComponent<Rigidbody>()->SetGround(false);
        }
	}
}
