#include "Point.h"
#include <math.h>

Point mid(const Point &p1, const Point &p2) {
    return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

double dist(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}