#pragma once

#include "../../Types/Public/Vector.h"
#include "../../Types/Public/Ray.h"

class Edge
{
/* ------------------------------- Functions -------------------------------- */
public: 
    Edge(const Vector& startPoint = {}, const Vector& endPoint = {}, 
         const Ray& startBisector = {}, const Ray& endBisector = {});

    const Vector& GetStart() const;

    const Vector& GetEnd() const;
    
    const Vector& GetDirection() const;

    const Ray& GetStartBisector() const;
    
    const Ray& GetEndBisector() const;

protected:

private:

/* --------------------------------- Members -------------------------------- */
public:

protected:

private:
    Vector StartPoint;

    Vector EndPoint;

    Vector Direction;

    Ray StartBisector;

    Ray EndBisector;
};