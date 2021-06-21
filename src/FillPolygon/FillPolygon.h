#pragma once
#include <vector>
#include "Point.h"

#define FILL_POLYGON_COLOR 1.0f, 0.4f, 0.6f

//定义边结构
struct Edge {
    int y_max;
    float x, delta_x;
    Edge *next;
};

class FillPolygon {
    public:
    FillPolygon(const std::vector<Point> points): points(points) {};
    void draw();
    private:
    void init_ET();
    void insert_ET(int y, Edge *e);
    void init_AEL();
    void delete_ET(int y);
    void insert_AEL(Edge *e);
    void update_AEL(int y);
    void sort_AEL();
    void fill(int y);
    bool checkET(int y);
    bool checkAEL();
    std::vector<Point> points;
    Edge ET[600];   //边分类表 窗口高度为600, 有600条扫描线。
    Edge AEL;      //活化边表（链表）
};


