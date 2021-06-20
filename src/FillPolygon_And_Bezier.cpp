#include <iostream>
#include "GL/glew.h"
#include "GL/freeglut.h"

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

}