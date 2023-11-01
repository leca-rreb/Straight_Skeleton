#include "../Public/Ray.h"

Ray::Ray(const Vector& origin, const Vector& direction): 
    Origin(origin), Direction(direction)
{
    Direction.Normalize();
}