#pragma once

#include <tuple>
#include <vector>

#include "ListActiveVertices.h"
#include "../../Types/Public/Polygon.h"
#include "Edge.h"
#include "Event.h"

typedef std::tuple<Vector, std::vector<Vector>, double> Bone;

class SetLAV
{
/* ------------------------------- Functions -------------------------------- */
public:
    SetLAV(const Polygon& polygon);

    const std::vector<ListActiveVertices>& GetLAVs() const;

    bool IsEmpty() const;

    Bone ProcessEdgeEvent(const Event& oldEvent, std::vector<Event>& newEvents);

    Bone ProcessSplitEvent(const Event& oldEvent, std::vector<Event>& newEvents);

protected:

private:

/* --------------------------------- Members -------------------------------- */
public:

protected:

private:
    std::vector<ListActiveVertices> LAVs;

    std::vector<Edge> OriginalEdges;
};