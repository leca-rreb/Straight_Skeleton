#pragma once

#include "../../Types/Public/Vector.h"

class Vertex;

enum class EVENT_TYPE
{
    NONE, 
    EDGE, 
    SPLIT
};

class Event
{
/* ------------------------------- Functions -------------------------------- */
public:
    struct PriorityComparison
    {
        bool operator()(const Event& eventA, const Event& eventB) const
        {
            return eventA.Height < eventB.Height;
        }
    };

    EVENT_TYPE GetType() const;

    double GetHeight();

    Vertex* GetVertexA() const;

    Vertex* GetVertexB() const;

    Vertex* GetEventVertex() const;

protected:

private:
/* --------------------------------- Members -------------------------------- */
public:

protected:

private:
    EVENT_TYPE Type;

    Vector Position;
    double Height;

    Vertex* VertexA;
    Vertex* VertexB;

    Vertex* EventVertex;
};