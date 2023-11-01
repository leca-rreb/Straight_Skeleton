#include "../Public/Vertex.h"

Vertex::Vertex(const Vector& position, 
               const Edge& prevEdge, const Edge& nextEdge, 
               const std::array<Vector, 2>& directionVectors)
    : Position(position), PrevEdge(prevEdge), NextEdge(nextEdge)
{
    Prev = nullptr;
    Next = nullptr;
    LAV  = nullptr;
    Validity = true;

    std::array<Vector, 2> _directionVectors;

    if (directionVectors.empty())
    {
        _directionVectors = 
            { -PrevEdge.GetDirection(), NextEdge.GetDirection() };
    }

    Vector bisectorDirection;
    if (_directionVectors[0].Cross(_directionVectors[1]) > 0.0)
    {
        Reflexity = true;
        bisectorDirection = -(_directionVectors[0] + _directionVectors[1]);
    }
    else
    {
        Reflexity = false;
        bisectorDirection = _directionVectors[0] + _directionVectors[1];
    }
    

    Bisector = Ray(Position, bisectorDirection);
}

bool Vertex::IsValid() const
{
    return Validity;
}

Event Vertex::NextEvent() const
{
    return { };
}

const Edge& Vertex::GetPrevEdge() const
{
    return PrevEdge;
}

const Edge& Vertex::GetNextEdge() const
{
    return NextEdge;
}

void Vertex::SetLAV(ListActiveVertices* List)
{
    LAV = List;
}
