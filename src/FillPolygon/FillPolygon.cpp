#include "FillPolygon.h"
#include "GL/glew.h"
// #include <iostream>
// using namespace std;

void FillPolygon::draw() {
    init_ET();
    int Y = 0;
    while (ET[Y].next == nullptr) Y++;
    init_AEL();
    while(Y < 600) {
        if (ET[Y].next != nullptr) {
            insert_AEL(ET[Y].next);
            delete_ET(Y);
        }
        fill(Y);
        Y++;
        update_AEL(Y);
    }
}

void FillPolygon::update_AEL(int y) {
    Edge *p = AEL.next, *old = &AEL;
    while (p != nullptr) {
        if (p->y_max == y) {
            Edge *temp = p;
            old->next = p->next;
            p = old->next;
            delete temp;
        } else {
            p->x += p->delta_x;
            old = p;
            p = p->next;
        }
        
    }
}

void FillPolygon::fill(int y) {
    Edge *p = AEL.next;
    glBegin(GL_LINES);
    glColor3f(FILL_POLYGON_COLOR);
    while(p != nullptr) {
        glVertex2d(p->x, y);
        glVertex2d(p->next->x, y);
        p = p->next->next;
    }
    glEnd();
}

// 冒泡排序
void FillPolygon::sort_AEL() {
    bool flag = true;
    while (flag) {
        Edge *p = AEL.next;
        flag = false;
        while (p != nullptr && p->next != nullptr) {
            if (p->x > p->next->x || (p->x == p->next->x && p->delta_x > p->next->delta_x)) {
                Edge temp = *p;
                p->x = p->next->x;
                p->y_max = p->next->y_max;
                p->delta_x = p->next->delta_x;

                p->next->x = temp.x;
                p->next->y_max = temp.y_max;
                p->next->delta_x = temp.delta_x;

                flag = true;
            }
            p = p->next;
        }
    }
}

void FillPolygon::insert_AEL(Edge *e) {
    Edge *p = &AEL;
    while(p->next != nullptr) p = p->next;
    p->next = e;
    sort_AEL();
}

void FillPolygon::init_AEL() {
    Edge head;
    head.next = nullptr;
    AEL = head;
}

void FillPolygon::delete_ET(int y) {
    ET[y].next = nullptr;
}

void FillPolygon::init_ET() {
    for (int i = 0; i < 600; i++) {
        Edge head;
        head.next = nullptr;
        ET[i] = head;
    }
    for (int i = 0; i < points.size(); i++) {
        Point *p1, *p2;
        if (i != points.size() - 1) {
            p1 = &(points[i]);
            p2 = &(points[i+1]);
        } else {
            p1 = &(points[i]);
            p2 = &(points[0]);
        }
        if (p1->y == p2->y) continue;   //拒绝水平边
        float delta_x = (p1->x - p2->x) / (p1->y - p2->y);
        int y_max, y_min;
        float x;
        if (p1->y > p2->y) {
            y_max = p1->y;
            y_min = p2->y;
            x = p2->x;
        } else {
            y_max = p2->y;
            y_min = p1->y;
            x = p1->x;
        }
        Edge *e = new Edge;
        e->y_max = y_max;
        e->x = x;
        e->delta_x = delta_x;
        e->next = nullptr;
        insert_ET(y_min, e);
    }
}

void FillPolygon::insert_ET(int y, Edge *e) {
    if (y < 0 || y >= 600) return;

    Edge *p = ET[y].next;
    Edge *old = &ET[y];
    
    while (p != nullptr && (e->x > p->x || (e->x == p->x && e->delta_x > p->delta_x))) {
        old = p;
        p = p->next;
    }

    e->next = old->next;
    old->next = e;

}