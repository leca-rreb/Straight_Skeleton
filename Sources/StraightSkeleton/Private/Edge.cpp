#include "../Public/Edge.h"

Edge::Edge(const Vector& startPoint, const Vector& endPoint,
           const Ray& startBisector, const Ray& endBisector)
    : StartPoint(startPoint), EndPoint(endPoint), 
      StartBisector(startBisector), EndBisector(endBisector)
{
    Direction = (EndPoint - StartPoint).GetNormal();
}

const Vector& Edge::GetStart() const
{
    return StartPoint;
}

const Vector&  Edge::GetEnd() const
{
    return EndPoint;
}

const Vector& Edge::GetDirection() const
{
    return Direction;
}

const Ray& Edge::GetStartBisector() const
{
    return StartBisector;
}

const Ray& Edge::GetEndBisector() const
{
    return EndBisector;
}
