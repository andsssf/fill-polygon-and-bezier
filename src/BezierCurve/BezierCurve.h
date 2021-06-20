#pragma once

#include "Point.h"

#define DIST_ERROR 1    //误差
#define BEZIER_CURVE_COLOR 0.4f, 0.3f, 0.8f

class BezierCurve {
    public:
    BezierCurve(Point p0, Point p1, Point p2, Point p3): p0(p0), p1(p1), p2(p2), p3(p3) {};
    void draw();
    private:
    double compute_error();
    Point p0, p1, p2, p3;
};

