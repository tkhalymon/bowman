#include <GL/glut.h>
#include "bowman.hpp"

void initGLUT(int argc, char** argv);
void display();
void timer(int);
void mousePressed(int button, int state, int x, int y);
void mouseMove(int x, int y);
void mousePressedMove(int x, int y);
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	glutInit(&argc, argv);
	int w = glutGet(GLUT_SCREEN_WIDTH) - 200;
	int h = glutGet(GLUT_SCREEN_HEIGHT) - 200;
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(w, h);
	glutCreateWindow("Bowman");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -2, 2);
	glMatrixMode(GL_MODELVIEW);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(display);
	glutTimerFunc(20, timer, 0);
	glutMouseFunc(mousePressed);
	glutPassiveMotionFunc(mouseMove);
	glutMotionFunc(mousePressedMove);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	static Bowman bowman;
	bowman.advance();
	bowman.render();
	glutSwapBuffers();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(2, timer, 0);
}

void mousePressed(int button, int state, int x, int y)
{

}

void mouseMove(int x, int y)
{

}

void mousePressedMove(int x, int y)
{

}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:
		glutDestroyWindow(1);
		exit(0);
		break;
	}
}

void specialKeyboard(int key, int x, int y)
{

}
