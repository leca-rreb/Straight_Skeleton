#include "../Public/SetLAV.h"

#include "../Public/Vertex.h"

SetLAV::SetLAV(const Polygon& polygon)
{
    LAVs.push_back(polygon.GetOuter());

    for (auto &&innerContour : polygon.GetInners())
    {
        LAVs.push_back(innerContour);
    }

    for (auto &&contour : LAVs)
    {
        for (auto &&vertex : contour.GetVertices())
        {
            // TODO: Create the set of original edges correctly.
        }
    }
}

const std::vector<ListActiveVertices>& SetLAV::GetLAVs() const
{
    return LAVs;
}

bool SetLAV::IsEmpty() const
{
    return LAVs.empty();
}

Bone SetLAV::ProcessEdgeEvent(const Event& oldEvent, std::vector<Event>& newEvents)
{
    return { };
}

Bone SetLAV::ProcessSplitEvent(const Event& oldEvent, std::vector<Event>& newEvents)
{
    return { };
}