#include "BezierCurve.h"
#include "GL/glew.h"

void BezierCurve::draw() {
    if (this->compute_error() < DIST_ERROR) {
        glBegin(GL_LINE_STRIP);
        glColor3f(BEZIER_CURVE_COLOR);
        glVertex2d(p0.x, p0.y);
        glVertex2d(p1.x, p1.y);
        glVertex2d(p2.x, p2.y);
        glVertex2d(p3.x, p3.y);
        glEnd();
    } else {
        Point key_point = mid(
            mid(
                mid(p0, p1),
                mid(p1, p2)
            ),
            mid(
                mid(p1, p2),
                mid(p2, p3)
            )
        );
        BezierCurve(p0, mid(p0, p1), mid(mid(p0, p1), mid(p1, p2)), key_point).draw();
        BezierCurve(key_point, mid(mid(p1, p2), mid(p2, p3)), mid(p2, p3), p3).draw();
    }
}

double BezierCurve::compute_error() {
    return dist(mid(p0, p3), mid(p1, p2));
}