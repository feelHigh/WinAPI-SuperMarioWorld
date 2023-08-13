#include "ntoItemPSwitch.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"

namespace nto
{
    ItemPSwitch::ItemPSwitch()
        : pStatus(false)
        , pOnGround(false)
        , pTimer(2.0f)
	{
	}

    ItemPSwitch::~ItemPSwitch()
	{
	}

	void ItemPSwitch::Initialize()
	{
	}

	void ItemPSwitch::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void ItemPSwitch::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ItemPSwitch::OnCollisionEnter(Collider* other)
	{
        Player* player = dynamic_cast<Player*>(other->GetOwner());

        if (player)
        {
            Transform* trPlayer = player->GetComponent<Transform>();
            Transform* trBox = GetComponent<Transform>();
            Collider* colPlayer = other;

            float lenX = fabs(trPlayer->GetPosition().x - trBox->GetPosition().x);
            float scaleX = (colPlayer->GetSize().x / 2.0f) + (GetComponent<Collider>()->GetSize().x / 2.0f);

            float lenY = fabs(trPlayer->GetPosition().y - trBox->GetPosition().y);
            float scaleY = (colPlayer->GetSize().y / 2.0f) + (GetComponent<Collider>()->GetSize().y / 2.0f);

            if (lenX < scaleX && lenY < scaleY)
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
                        // Bump the player Up
                        playerPos.y += overlapY;
                        Rigidbody* rb = player->GetComponent<Rigidbody>();
                        rb->SetGround(false);
                        rb->SetVelocity(Vector2(0.0f, -300.0f));
                        this->GetComponent<Animator>()->PlayAnimation(L"Foreground_Animation_PSwitch_On", true);
                    }
                    else
                    {
                        // Set the setGround to true when colliding on top of the box
                        //Rigidbody* rb = player->GetComponent<Rigidbody>();
                        //rb->SetGround(true);
                    }
                    trPlayer->SetPosition(playerPos);
                }
            }
        }
	}

	void ItemPSwitch::OnCollisionStay(Collider* other)
	{
	}

	void ItemPSwitch::OnCollisionExit(Collider* other)
	{
	}
}
