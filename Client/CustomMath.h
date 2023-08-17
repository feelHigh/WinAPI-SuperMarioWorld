#pragma once
#include <cmath>

namespace nto::math
{
#define PI 3.141592f

    struct Vector2
    {
        static Vector2 Zero;
        static Vector2 One;
        static Vector2 Right;
        static Vector2 Up;

        float x;
        float y;

        Vector2()
            : x(0.0f)
            , y(0.0f)
        {

        }

        Vector2(float _x, float _y)
            : x(_x)
            , y(_y)
        {

        }

        Vector2 operator -()
        {
            return Vector2(-x, -y);
        }

        Vector2 operator+(const Vector2& other)
        {
            Vector2 temp;
            temp.x = x + other.x;
            temp.y = y + other.y;

            return temp;
        }

        Vector2 operator-(const Vector2& other)
        {
            Vector2 temp;
            temp.x = x - other.x;
            temp.y = y - other.y;

            return temp;
        }

        Vector2 operator*(const Vector2& other)
        {
            Vector2 temp;
            temp.x = x * other.x;
            temp.y = y * other.y;

            return temp;
        }

        Vector2 operator*(const float& value)
        {
            Vector2 temp;
            temp.x = x * value;
            temp.y = y * value;

            return temp;
        }

        Vector2 operator/(const float& value)
        {
            Vector2 temp;

            temp.x = x / value;
            temp.y = y / value;

            return temp;
        }

        Vector2& operator +=(const Vector2& other)
        {
            x += other.x;
            y += other.y;

            return *this;
        }

        Vector2& operator -=(const Vector2& other)
        {
            x -= other.x;
            y -= other.y;

            return *this;
        }

        Vector2& operator *=(const float& value)
        {
            x *= value;
            y *= value;

            return *this;
        }

        bool operator ==(const Vector2& other) const
        {
            return (x == other.x && y == other.y);
            /*const float epsilon = 1e-5;
            return (fabs(x - other.x) < epsilon && fabs(y - other.y) < epsilon);*/
        }

        void clear()
        {
            x = 0.0f;
            y = 0.0f;
        }

        float length()
        {
            return sqrtf(x * x + y * y);
        }

        Vector2 normalize()
        {
            float len = length();
            x /= len;
            y /= len;

            return *this;
            /*float len = length();
            if (len == 0)
                return Vector2(0.0f, 0.0f);
            return Vector2(x / len, y / len);*/
        }
        // added
        friend Vector2 operator-(const Vector2& left, const Vector2& right)
        {
            return Vector2(left.x - right.x, left.y - right.y);
        }

        friend Vector2 operator+(const Vector2& left, const Vector2& right)
        {
            return Vector2(left.x + right.x, left.y + right.y);
        }
        static float Distance(const Vector2& a, const Vector2& b)
        {
            return (b - a).length();
        }
        static Vector2 MoveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta)
        {
            Vector2 toVector = target - current;
            float distance = toVector.length();

            if (distance <= maxDistanceDelta || distance == 0)
                return target;

            return current + toVector * (maxDistanceDelta / distance);
        }
    };

    inline Vector2 Rotate(Vector2 vector, float degree)
    {
        float radian = (degree / 180.f) * PI;
        vector.normalize();
        float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
        float y = sinf(radian) * vector.x + cosf(radian) * vector.y;

        return Vector2(x, y);
    }

    inline float Dot(Vector2& v1, Vector2& v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }

    inline float Cross(Vector2 v1, Vector2 v2)
    {
        return v1.x * v2.y - v1.y * v2.x;
    }
}
