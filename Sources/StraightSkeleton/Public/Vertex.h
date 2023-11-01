#pragma once

#include <array>

#include "../../Types/Public/DoublyLinkedListNode.h"
#include "../../Types/Public/Vector.h"
#include "../../Types/Public/Ray.h"

#include "Edge.h"
#include "Event.h"

class ListActiveVertices;

class Vertex: public DoublyLinkedListNode<Vertex>
{
/* ------------------------------- Functions -------------------------------- */
public:
    Vertex(const Vector& position = {}, 
           const Edge& prevEdge = {}, const Edge& nextEdge = {}, 
           const std::array<Vector, 2>& directionVectors = { });

    bool IsValid() const;

    Event NextEvent() const;

    const Edge& GetPrevEdge() const;

    const Edge& GetNextEdge() const;

    void SetLAV(ListActiveVertices* List);

protected:

private:

/* --------------------------------- Members -------------------------------- */
public:

protected:

private:
    Vector Position;

    Edge PrevEdge;

    Edge NextEdge;

    Ray Bisector;

    ListActiveVertices* LAV;

    bool Validity;
    
    bool Reflexity;
};
