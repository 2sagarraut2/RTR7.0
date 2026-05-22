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
#include <math.h>

bool bIsFullScreen = false;

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

	glBegin(GL_TRIANGLES);

	float x;

	for (x = -1.0; x <= 1.0; x++)
	{
		// mountain
		glColor3f(0.0f, 0.5f, 0.0f); // Green
		glVertex3f(-0.5f + x, 0.4f, 0.0f);

		glColor3f(1.0f, 1.0f, 1.0f); // White
		glVertex3f(-0.0f + x, 1.0f, 0.0f);

		glColor3f(0.0f, 0.5f, 0.0f); // Green
		glVertex3f(0.5f + x, 0.4f, 0.0f);

		printf("%.1f\n", x);
	}

	// river
	// 1st triangle
	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.4f, 0.4f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.6f, 0.4f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(0.3f, 0.0f, 0.0f);

	// 2nd triangle
	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.6f, 0.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.6f, 0.4f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(0.3f, 0.0f, 0.0f);

	// 3rd triangle
	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.6f, 0.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // Blue
	glVertex3f(0.47f, -0.6f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(0.3f, 0.0f, 0.0f);

	// 4th triangle
	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.1f, -0.6f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // Blue
	glVertex3f(0.47f, -0.6f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(0.3f, 0.0f, 0.0f);

	// 5th triangle
	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.1f, -0.6f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(0.47f, -0.6f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(0.3f, -1.0f, 0.0f);

	// 6th triangle
	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.1f, -0.6f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(-1.0f, -1.6f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(0.3f, -1.0f, 0.0f);

	// house path triangle
	glColor3f(0.419f, 557.f, 0.137f); // Grass green
	glVertex3f(-0.40f, -1.0f, 0.0f);

	glColor3f(0.419f, 557.f, 0.137f); // Grass green
	glVertex3f(-0.8f, 0.0f, 0.0f);

	glColor3f(0.419f, 557.f, 0.137f); // Grass green
	glVertex3f(-0.9f, -1.0f, 0.0f);

	// house top triangle
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f(-0.9f, 0.1f, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f(-0.75f, 0.3f, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f(-0.6f, 0.1f, 0.0f);

	// house rectangle left triangle
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(-0.9f, 0.1f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(-0.9f, -0.3f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(-0.6f, -0.3f, 0.0f);

	// house rectangle right triangle
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(-0.6f, -0.3f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(-0.6f, 0.1f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex3f(-0.9f, 0.1f, 0.0f);

	// house square left triangle
	glColor3f(0.863f, 0.863f, 0.863f); // Gray
	glVertex3f(-0.6f, -0.3f, 0.0f);

	glColor3f(0.863f, 0.863f, 0.863f); // Gray
	glVertex3f(-0.6f, 0.1f, 0.0f);

	glColor3f(0.863f, 0.863f, 0.863f); // Gray
	glVertex3f(-0.15f, 0.1f, 0.0f);

	// house square right triangle
	glColor3f(0.863f, 0.863f, 0.863f); // Gray
	glVertex3f(-0.6f, -0.3f, 0.0f);

	glColor3f(0.863f, 0.863f, 0.863f); // Gray
	glVertex3f(-0.15f, -0.3f, 0.0f);

	glColor3f(0.863f, 0.863f, 0.863f); // Gray
	glVertex3f(-0.15f, 0.1f, 0.0f);

	// house roof right triangle
	glColor3f(0.886f, 0.447f, 0.357f); // roof
	glVertex3f(-0.6f, 0.1f, 0.0f);

	glColor3f(0.886f, 0.447f, 0.357f); // roof
	glVertex3f(-0.15f, 0.1f, 0.0f);

	glColor3f(0.886f, 0.447f, 0.357f); // roof
	glVertex3f(-0.25f, 0.3f, 0.0f);

	// house roof left triangle
	glColor3f(0.886f, 0.447f, 0.357f); // roof
	glVertex3f(-0.25f, 0.3f, 0.0f);

	glColor3f(0.886f, 0.447f, 0.357f); // roof
	glVertex3f(-0.6f, 0.1f, 0.0f);

	glColor3f(0.886f, 0.447f, 0.357f); // roof
	glVertex3f(-0.75f, 0.3f, 0.0f);

	for (float y = 0.0f; y <= 0.80f; y += 0.39f)
	{
		// tree head top
		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.2f + y, 0.60f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.07f + y, 0.30f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.32f + y, 0.30f, 0.0f);

		// tree head top
		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.2f + y, 0.45f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.03f + y, 0.15f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.35f + y, 0.15f, 0.0f);

		// tree head bottom
		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.2f + y, 0.3f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.0f + y, 0.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.4f + y, 0.0f, 0.0f);

		// tree trunk right
		glColor3f(0.0f, 0.5f, 0.0f); // Green
		glVertex3f(0.22f + y, 0.0f, 0.0f);

		glColor3f(0.0f, 0.5f, 0.0f); // Green
		glVertex3f(0.17f + y, -0.2f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.22f + y, -0.2f, 0.0f);

		// tree trunk left
		glColor3f(0.0f, 0.5f, 0.0f); // Green
		glVertex3f(0.22f + y, 0.0f, 0.0f);

		glColor3f(0.0f, 0.5f, 0.0f); // Green
		glVertex3f(0.17f + y, -0.2f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex3f(0.17f + y, 0.0f, 0.0f);

		printf("%f\n", y);
	}

	glEnd();

	glutSwapBuffers();
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