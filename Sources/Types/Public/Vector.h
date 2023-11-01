#pragma once

#include <cmath>

struct Vector
{
/* ------------------------------- Functions -------------------------------- */
public:
    inline Vector(): X(0.0), Y(0.0) { }

    inline Vector(double inValue): X(inValue), Y(inValue) { }

    inline Vector(double inX, double inY): X(inX), Y(inY) { }

    inline Vector(const Vector& v) : X(v.X), Y(v.Y) { }

    inline Vector& operator=(const Vector& v)
    {
        if (&v == this)
        {
            return *this;
        }

        X = v.X;
        Y = v.Y;

        return *this;        
    }

    inline Vector operator+(const Vector& v) const
    {
        return Vector(X + v.X, Y + v.Y);
    }

    inline Vector operator-(const Vector& v) const
    {
        return Vector(X - v.X, Y - v.Y);
    }

    inline Vector operator*(const Vector& v) const
    {
        return Vector(X * v.X, Y * v.Y);
    }

    inline Vector operator/(const Vector& v) const
    {
        return Vector(X / v.X, Y / v.Y);
    }

    inline Vector operator+(double scalar) const
    {
        return Vector(X + scalar, Y + scalar);
    }

    inline Vector operator-(double scalar) const
    {
        return Vector(X - scalar, Y - scalar);
    }

    inline Vector operator*(double scalar) const
    {
        return Vector(X * scalar, Y * scalar);
    }

    inline Vector operator/(double scalar) const
    {
        return Vector(X / scalar, Y / scalar);
    }

    inline Vector operator-() const
    {
        return Vector(-X, -Y);
    }

    inline Vector operator+=(const Vector& v)
    {
        X += v.X;
        Y += v.Y;
        return *this;
    }

    inline Vector operator-=(const Vector& v)
    {
        X -= v.X;
        Y -= v.Y;
        return *this;
    }

    inline Vector operator*=(const Vector& v)
    {
        X *= v.X;
        Y *= v.Y;
        return *this;
    }

    inline Vector operator/=(const Vector& v)
    {
        X /= v.X;
        Y /= v.Y;
        return *this;
    }

    inline Vector operator*=(double scalar)
    {
        X *= scalar;
        Y *= scalar;
        return *this;
    }

    inline Vector operator/=(double scalar)
    {
        X /= scalar;
        Y /= scalar;
        return *this;
    }

    inline double Dot(const Vector& v) const
    {
        return X * v.X + Y * v.Y;
    }

    inline double Cross(const Vector& v) const
    {
        return X * v.Y - Y * v.X;
    }

    inline static double DotProduct(const Vector& v1, const Vector& v2) 
    {
        return v1.X * v2.X + v1.Y * v2.Y;
    }

    inline static double CrossProduct(const Vector& v1, const Vector& v2)
    {
        return v1.X * v2.Y - v1.Y * v2.X;
    }

    inline Vector GetNormal()
    {
        const double length { std::sqrt(X * X + Y * Y) };
        if (length > 0.0)
        {
            return { X / length, Y / length };
        }
        return { 0.0, 0.0 };
    }

    inline void Normalize()
    {
        const double length { std::sqrt(X * X + Y * Y) };
        if (length > 0.0)
        {
            X /= length;
            Y /= length;
        }
        
    }

protected:

private:

/* --------------------------------- Members -------------------------------- */
public:
    double X;
    double Y;

protected:

private:
};
