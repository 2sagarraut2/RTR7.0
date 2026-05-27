#ifdef __APPLE__
// macOS Headers
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// Functional macros that absorb the empty parentheses ()
#ifndef glutCloseFunc
#define glutCloseFunc glutWMCloseFunc
#endif
#ifndef glutLeaveMainLoop
#define glutLeaveMainLoop() exit(0)
#endif
#ifndef glutLeaveFullScreen
#define glutLeaveFullScreen()         \
	do                                \
	{                                 \
		glutReshapeWindow(800, 600);  \
		glutPositionWindow(100, 100); \
	} while (0)
#endif
#elif defined(_WIN32) || defined(_WIN64)
// Windows Headers
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h> // Required for exit()

bool bIsFullScreen = false;
float xPosition = -0.99f;
float yPosition = -0.99f;

// func declarations
void moveMyRectangleOnX(float xPosition);
void moveMyRectangleOnY(float YPosition);

int main(int argc, char *argv[])
{
	// function declarations
	void initialize(void);
	void uninitialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);

	// code
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First RTR7 Program : Sagar Sambhaji Raut");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	// flow should not come here
	return (0);
}

void initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
		height = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	moveMyRectangleOnX(xPosition);
	moveMyRectangleOnY(yPosition);

	if (xPosition <= 1.0f || yPosition <= 1.0f)
	{
		xPosition += 0.001f;
		yPosition += 0.001f;
	}

	glutSwapBuffers();
	glutPostRedisplay();
}

void moveMyRectangleOnX(float xPosition)
{
	glBegin(GL_QUADS);

	// 1st triangle
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f(xPosition, 0.2f, 0.0f);
	glVertex3f(xPosition + 0.4f, 0.2f, 0.0f);
	glVertex3f(xPosition + 0.4f, -0.2f, 0.0f);
	glVertex3f(xPosition, -0.2f, 0.0f);

	glEnd();
}

void moveMyRectangleOnY(float yPosition)
{
	glBegin(GL_QUADS);

	// 1st triangle
	glColor3f(1.0f, 0.0f, 0.0f); // Red

	glVertex3f(-0.2f, yPosition, 0.0f);
	glVertex3f(0.2f, yPosition, 0.0f);
	glVertex3f(0.2f, yPosition + 0.4f, 0.0f);
	glVertex3f(-0.2f, yPosition + 0.4f, 0.0f);

	glEnd();
}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (bIsFullScreen == false)
		{
			glutFullScreen();
			bIsFullScreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			bIsFullScreen = false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_RIGHT_BUTTON:
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}