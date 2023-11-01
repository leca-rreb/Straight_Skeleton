#include "../Public/Polygon.h"


Polygon::Polygon(const std::vector<Vector>& outerContour, 
        const std::vector<std::vector<Vector>>& innerContours)
    : OuterContour(outerContour), InnerContours(innerContours)
{
    OuterSize = OuterContour.size();
    InnerContoursNum = InnerContours.size();

    for (const auto& innerContour : InnerContours)
    {
        InnerContoursSizes.push_back(innerContour.size());
    }
}

Polygon::Polygon(const Polygon& other) {}

const std::vector<Vector>& Polygon::GetOuter() const
{
    return OuterContour;
}

const std::vector<std::vector<Vector>>& Polygon::GetInners() const
{
    return InnerContours;
}

size_t Polygon::GetOuterSize() const
{
    return OuterSize;
}

size_t Polygon::GetInnerContoursNum() const
{
    return InnerContoursNum;
}

const std::vector<size_t>& Polygon::GetInnerContoursSizes() const
{
    return InnerContoursSizes;
}
