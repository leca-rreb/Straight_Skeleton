#pragma once

#include <vector>

#include "../../Types/Public/Vector.h"

class Vertex;
class SetLAV;

class ListActiveVertices
{
/* ------------------------------- Functions -------------------------------- */
public:
    ListActiveVertices(const std::vector<Vector>& vertices, SetLAV* SLAV = nullptr);

    const std::vector<Vertex> GetVertices() const;

protected:

private:

/* --------------------------------- Members -------------------------------- */
public:

protected:

private:
    Vertex* Head;

    SetLAV* SLAV;

    size_t Size;
};
