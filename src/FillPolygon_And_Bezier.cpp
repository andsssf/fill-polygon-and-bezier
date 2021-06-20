#include <iostream>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "BezierCurve/BezierCurve.h"
#include "FillPolygon/FillPolygon.h"

using namespace std;

int WIDTH = 800, HEIGHT = 600;

void render();

int main(int argc,char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Fill Polygon And Bezier curve Demo");
	
    glutDisplayFunc(render);

	gluOrtho2D(0, WIDTH, 0, HEIGHT);

    glutMainLoop();
    return 0;
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
    
    //定义Bezier 曲线的四个控制点，从p0-p3
    BezierCurve(Point(0, 0), Point(300, 300), Point(550, 400), Point(800, 100)).draw();

    //按课本示例测试，缩放扩大20倍
    FillPolygon({
        Point(2*20, 4*20 + 200), Point(5*20, 1*20 + 200), Point(7*20, 1*20 + 200), Point(12*20, 5*20 + 200), Point(12*20, 11*20 + 200), Point(7*20, 7*20 + 200), Point(2*20, 8*20 + 200)    
    }).draw();

	glFlush();
}