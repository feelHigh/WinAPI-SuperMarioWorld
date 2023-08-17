#include "ntoRedShell.h"
#include "Player.h"
#include "ntoRedKoopa.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"

namespace nto
{
    RedShell::RedShell()
        : mDeathTime(1.5f)
        , mCaught(false)
        , mThrow(false)
    {
    }

    RedShell::~RedShell()
    {
    }

    void RedShell::Initialize()
    {
    }

    void RedShell::Update()
    {
        GameObject::Update();

        /*Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();

        SpriteRenderer* sr = GetComponent<SpriteRenderer>();
        
        if (mThrow)
        {
            pos.x += 400.0f * Time::DeltaTime();
            tr->SetPosition(pos);

            mDeathTime -= Time::DeltaTime();
            if (mDeathTime < 0.0f)
            {
                Destroy(this);
            }
        }
        else
        {
            tr->SetPosition(pos);
        }*/

        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        pos.x += 600.0f * Time::DeltaTime();
        tr->SetPosition(pos);

        mDeathTime -= Time::DeltaTime();
        if (mDeathTime < 0.0f)
        {
            Destroy(this);
        }
    }

    void RedShell::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void RedShell::OnCollisionEnter(Collider* other)
    {
    }

    void RedShell::OnCollisionStay(Collider* other)
    {
    }

    void RedShell::OnCollisionExit(Collider* other)
    {
    }
}
