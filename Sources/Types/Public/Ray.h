#pragma once

#include "Vector.h"

struct Ray
{
/* ------------------------------- Functions -------------------------------- */
public:
    Ray(const Vector& origin = {}, const Vector& direction = {});

protected:

private:

/* --------------------------------- Members -------------------------------- */
public:
    Vector Origin;

    Vector Direction;

protected:

private:
};
