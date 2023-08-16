#include "ntoEnvironmentGrayPlank.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"

namespace nto
{
	EnvironmentGrayPlank::EnvironmentGrayPlank()
        : gTick(true)
        , gType(1)
        , gTimer(3.0f)
	{
	}

	EnvironmentGrayPlank::~EnvironmentGrayPlank()
	{
	}

	void EnvironmentGrayPlank::Initialize()
	{
	}

	void EnvironmentGrayPlank::Update()
	{
        GameObject::Update();

        SpriteRenderer* sr = GetComponent<SpriteRenderer>();
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();

        if (gType == 1)
        {
            if (gTick)
            {
                pos.x -= 128.0f * Time::DeltaTime();
                gTimer -= Time::DeltaTime();
                if (gTimer < 0.0f)
                {
                    gTimer = 3.0f;
                    gTick = false;
                }
            }
            else
            {
                pos.x += 128.0f * Time::DeltaTime();
                gTimer -= Time::DeltaTime();
                if (gTimer < 0.0f)
                {
                    gTimer = 3.0f;
                    gTick = true;
                }
            }
        }
        else
        {
            if (gTick)
            {
                pos.y -= 128.0f * Time::DeltaTime();
                gTimer -= Time::DeltaTime();
                if (gTimer < 0.0f)
                {
                    gTimer = 3.0f;
                    gTick = false;
                }
            }
            else
            {
                pos.y += 128.0f * Time::DeltaTime();
                gTimer -= Time::DeltaTime();
                if (gTimer < 0.0f)
                {
                    gTimer = 3.0f;
                    gTick = true;
                }
            }
        }


        tr->SetPosition(pos);
	}

	void EnvironmentGrayPlank::Render(HDC hdc)
	{
        GameObject::Render(hdc);
	}

	void EnvironmentGrayPlank::OnCollisionEnter(Collider* other)
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

	void EnvironmentGrayPlank::OnCollisionStay(Collider* other)
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
                        // Bump the player up
                        playerPos.y += overlapY;
                        //Rigidbody* rb = player->GetComponent<Rigidbody>();
                        //rb->SetGround(false);
                        //rb->SetVelocity(Vector2(0.0f, -1.0f));
                        //// Set the setGround to true when colliding on top of the box
                        //Rigidbody* rb = player->GetComponent<Rigidbody>();
                        //rb->SetGround(true);
                    }
                    else
                    {
                    }
                    trPlayer->SetPosition(playerPos);
                }
            }
        }
	}

	void EnvironmentGrayPlank::OnCollisionExit(Collider* other)
	{
        Player* player = dynamic_cast<Player*>(other->GetOwner());
        player->GetComponent<Rigidbody>()->SetGround(false);
	}
}
