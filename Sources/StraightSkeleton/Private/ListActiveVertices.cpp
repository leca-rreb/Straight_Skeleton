#include "../Public/ListActiveVertices.h"

#include "../Public/Vertex.h"
#include "../Public/SetLAV.h"

ListActiveVertices::ListActiveVertices(const std::vector<Vector>& vertices, SetLAV* SLAV)
    : SLAV(SLAV), Size(vertices.size())
{
    Head = new Vertex(vertices.front(), 
                      { vertices.back(), vertices.front() }, 
                      { vertices.front(), vertices[1] });

    for (size_t i = 0; i < Size; i++)
    {
        size_t prevVertexIndex { (i - 1 + Size) % Size };
        size_t nextVertexIndex { (i + 1)        % Size };

        Edge prevEdge { vertices[prevVertexIndex], vertices[i] };
        Edge nextEdge { vertices[i], vertices[nextVertexIndex] };

        Vertex* newVertex = new Vertex(vertices[i], prevEdge, nextEdge);
        newVertex->SetLAV(this);
    
        newVertex->InsertBefore(Head);
    }
    
}

const std::vector<Vertex> ListActiveVertices::GetVertices() const
{
    std::vector<Vertex> vertices;

    Vertex* currVertex { Head };
    do
    {
        vertices.emplace_back(*currVertex);
        currVertex = Head->GetNext();
    } while (currVertex != Head);
    
    return vertices;
}