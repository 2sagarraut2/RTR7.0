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
const float SSR_square_size = 0.25f;

// function declarations
void drawBuilding(float x, float y, float width, float height);
void drawWindows(float x, float y, float width, float height);
void drawLine(float x, float y, float width, float heigt);
void drawLampPost(float x, float y);
void drawCircle(float centerX, float centerY, float radius);

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
	glutCreateWindow("City Scene : Sagar Sambhaji Raut");

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
	glClearColor(0.184f, 0.310f, 0.533f, 1.0f);
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

	// float x, float y, float width, float height
	drawBuilding(-0.97f, 0.7f, 0.33f, 1.2f);

	// float x, float y, float width, float height
	drawBuilding(-0.5f, 0.5f, 0.3f, 1.0f);

	// float x, float y, float width, float height
	drawBuilding(-0.05f, 0.5f, 0.4f, 1.0f);

	drawBuilding(0.5f, 0.7f, 0.2f, 1.2f);

	// drawn lines for road
	drawLine(-0.5f, 0.5f, 0.3f, 1.0f);
	drawLine(0.5f, 0.4f, 0.2f, 1.2f);

	glutSwapBuffers();
}

void drawBuilding(float x, float y, float width, float height)
{
	glBegin(GL_QUADS);

	// building face
	glColor3f(0.361f, 0.670f, 0.553f);

	glVertex2f(x, y);				   // Top-Left
	glVertex2f(x + width, y);		   // Top-Right
	glVertex2f(x + width, y - height); // Bottom-Right
	glVertex2f(x, y - height);		   // Bottom-Left

	// building side
	glColor3f(0.227f, 0.471f, 0.380f);

	glVertex2f(x + width, y);				  // Top-Left
	glVertex2f(x + width + 0.10, y - 0.1f);	  // Top-Right
	glVertex2f(x + width + 0.10, y - height); // Bottom-Right
	glVertex2f(x + width, y - height);		  // Bottom-Left

	glEnd();

	// printf("X, Y = %f, %f \n", x, y);

	drawWindows(x, y, width, height);
}

void drawWindows(float x, float y, float width, float height)
{
	// printf("X, Y = %f, %f \n", x, y);

	float winWidth = 0.03f;
	float winHeight = 0.04f;
	float padding = 0.04f;

	for (float currY = y - padding; currY - winHeight > y - height + 0.2; currY -= (winHeight + padding))
	{
		for (float currX = x + padding; currX + winWidth < x + width; currX += (winWidth + padding))
		{

			glBegin(GL_QUADS);
			glColor3f(0.984f, 0.977f, 0.333f); // Warm yellow glow

			glVertex2f(currX, currY);						 // Top-Left
			glVertex2f(currX + winWidth, currY);			 // Top-Right
			glVertex2f(currX + winWidth, currY - winHeight); // Bottom-Right
			glVertex2f(currX, currY - winHeight);			 // Bottom-Left
			glEnd();
		}
	}
}

void drawLine(float x, float y, float width, float height)
{
	// bottom line
	glColor3f(0.0f, 0.0f, 0.0f);

	glLineWidth(3.0f);

	glBegin(GL_LINES);

	glVertex2f(x + width - 2.0f, y - height); // Line 1 Start
	glVertex2f(x + width + 2.0f, y - height); // Line 1 End

	glEnd();

	glLineWidth(1.0f);

	drawLampPost(x, y - height);

	drawLampPost(x + 0.4f, y - height);
}

void drawLampPost(float x, float y)
{
	glColor3f(0.0f, 0.0f, 0.0f);

	glLineWidth(9.0f);

	glBegin(GL_LINES);

	glVertex2f(x + 0.03, y + 0.2f); // Line 1 Start
	glVertex2f(x + 0.03, y);		// Line 1 End

	glEnd();

	// float centerX, float centerY, float radius
	drawCircle(x + 0.03, y + 0.2f, 0.090f);
	drawCircle(x + 0.03, y + 0.3f, 0.070f);

	glLineWidth(1.0f);
}

void drawCircle(float centerX, float centerY, float radius)
{
	glColor3f(0.471f, 0.784f, 0.310f);

	glBegin(GL_TRIANGLE_FAN);
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 360; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * radius);
		float y = centerY + (sin(angle) * radius);

		glVertex2f(x, y);
	}
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
