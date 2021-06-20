#pragma once

class Point {
    public:
    Point() {};
    Point(double x, double y): x(x), y(y) {};
    double x, y;
};

Point mid(const Point &p1, const Point &p2);
double dist(const Point &p1, const Point &p2);