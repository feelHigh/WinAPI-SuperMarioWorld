#include "ntoForegroundSpinBox.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"

namespace nto
{
	ForegroundSpinBox::ForegroundSpinBox()
        : bType(1)
        , bSwitch(false)
	{
	}

	ForegroundSpinBox::~ForegroundSpinBox()
	{
	}

	void ForegroundSpinBox::Initialize()
	{
        this->bType = GetType();
	}

	void ForegroundSpinBox::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void ForegroundSpinBox::Render(HDC hdc)
	{
        GameObject::Render(hdc);
	}

	void ForegroundSpinBox::OnCollisionEnter(Collider* other)
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
                        // Set the setGround to true when colliding on top of the box
                        Rigidbody* rb = player->GetComponent<Rigidbody>();
                        rb->SetGround(true);
                    }
                    else
                    {
                        // Bump the player down
                        playerPos.y -= overlapY;
                        Rigidbody* rb = player->GetComponent<Rigidbody>();
                        rb->SetGround(false);
                        rb->SetVelocity(Vector2(0.0f, 600.0f));
                        // ¼öÁ¤
                        if (bType == 1)
                        {
                            this->GetComponent<Animator>()->PlayAnimation(L"Foreground_Animation_EmptyBox", true);
                        }
                        else if (bType == 2)
                        {
                            this->GetComponent<Animator>()->PlayAnimation(L"Foreground_Animation_SpinBox_Spin", true);
                            bSwitch = true;
                            Collider* boxCollider = GetComponent<Collider>();
                            boxCollider->SetActive(false);
                        }
                    }
                    trPlayer->SetPosition(playerPos);
                }
            }
        }
	}

	void ForegroundSpinBox::OnCollisionStay(Collider* other)
	{
	}

	void ForegroundSpinBox::OnCollisionExit(Collider* other)
	{
	}
}
