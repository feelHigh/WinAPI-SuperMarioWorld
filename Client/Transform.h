#pragma once
#pragma once
#include "Component.h"
#include "CustomMath.h"

namespace nto
{
    using namespace math;

    class Transform : public Component
    {
    public:
        Transform();
        virtual ~Transform();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        void SetPosition(Vector2 position) { mPosition = position; }
        Vector2 GetPosition() { return mPosition; }
        void SetRotation(float rotate) { mRotation = rotate; }
        float GetRotation() { return mRotation; }
        void SetType(int type) { mType = type; }
        int GetType() { return mType; }
        void SetScale(Vector2 scale) { mScale = scale; } // Add setter for scale
        Vector2 GetScale() { return mScale; } // Add getter for scale

        void SetPositionX(float x) { mPosition.x = x; } // Add setter for x position
        void SetPositionY(float y) { mPosition.y = y; } // Add setter for y position

    private:
        Vector2 mPosition;
        Vector2 mScale; // Add scale member variable
        float mRotation;
        int mType;
    };
}
