#include "../Public/Event.h"

EVENT_TYPE Event::GetType() const
{
    return Type;
}

double Event::GetHeight()
{
    return Height;
}

Vertex* Event::GetVertexA() const
{
    return VertexA;
}

Vertex* Event::GetVertexB() const
{
    return VertexB;
}

Vertex* Event::GetEventVertex() const
{
    return EventVertex;
}