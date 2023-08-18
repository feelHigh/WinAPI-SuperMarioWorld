#include "ntoForegroundCoin.h"
#include "Player.h"
#include "ntoItemPSwitch.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	ForegroundCoin::ForegroundCoin()
		: cType(1)
        , cStatus(false)
	{
	}

	ForegroundCoin::~ForegroundCoin()
	{
	}

	void ForegroundCoin::Initialize()
	{
		this->cType = GetType();
	}

	void ForegroundCoin::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();

        if (cType == 2 && cStatus)
        {
            this->GetComponent<Animator>()->PlayAnimation(L"Foreground_Animation_EmptyBox", true);
        }

	}

	void ForegroundCoin::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ForegroundCoin::OnCollisionEnter(Collider* other)
	{
        Player* player = dynamic_cast<Player*>(other->GetOwner());

        if (player)
        {
            if (cType == 2 && cStatus)
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
                        }
                        trPlayer->SetPosition(playerPos);
                    }
                }
            }
        }
	}

	void ForegroundCoin::OnCollisionStay(Collider* other)
	{
        Player* player = dynamic_cast<Player*>(other->GetOwner());
        if (player)
        {
            if (cType == 1 && !cStatus)
            {
                Sound* sound = Resources::Load<Sound>(L"sfxCoin", L"..\\Assets\\Sound\\SFX\\WAV\\smw_coin.wav");
                sound->Play(false);
                Destroy(this);
            }
        }
	}

	void ForegroundCoin::OnCollisionExit(Collider* other)
	{
	}
}
