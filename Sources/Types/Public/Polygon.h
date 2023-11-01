#pragma once

#include <vector>
#include "Vector.h"

class Polygon
{
/* ------------------------------- Functions -------------------------------- */
public:
    Polygon(const std::vector<Vector>& outerContour, 
            const std::vector<std::vector<Vector>>& innerContours = {});

    Polygon(const Polygon& other);

    const std::vector<Vector>& GetOuter() const;

    const std::vector<std::vector<Vector>>& GetInners() const;

    size_t GetOuterSize() const;

    size_t GetInnerContoursNum() const;

    const std::vector<size_t>& GetInnerContoursSizes() const;

/* --------------------------------- Members -------------------------------- */
public:

protected:

private:
    std::vector<Vector> OuterContour;

    std::vector<std::vector<Vector>> InnerContours;

    size_t OuterSize;

    size_t InnerContoursNum;

    std::vector<size_t> InnerContoursSizes;
};