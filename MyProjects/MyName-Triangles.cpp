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

// function declarations
void drawCoverBox(float startingPointX, float startingPointY, float width);
void letterS(float startingPoint, float startingPointY, float width, float thickness);
void letterA(float startingPointX, float startingPointY, float width, float thickness);
void letterG(float startingPointX, float startingPointY, float width, float thickness);
void letterR(float startingPointX, float startingPointY, float width, float thickness);

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
    glutCreateWindow("Sagar Raut");

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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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

    float startingPointX = -0.9f; // -0.9
    float width = 0.32f;
    float thickness = 0.10f;

    drawCoverBox(startingPointX, 0.5f, width);

    // TODO: ADD WAIT TO ADD ANIMATIONS

    // float startingPoint, float startingPointY, float width, float thickness
    letterS(startingPointX, 0.5f, width, thickness);
    startingPointX = startingPointX + width;
    letterA(startingPointX, 0.5f, width, thickness);
    startingPointX = startingPointX + width + thickness / 1.3f;
    letterG(startingPointX, 0.5f, width, thickness);
    startingPointX = startingPointX + width;
    letterA(startingPointX, 0.5f, width, thickness);
    startingPointX = startingPointX + width + thickness / 1.3f;
    letterR(startingPointX, 0.5f, width, thickness);

    glutSwapBuffers();
}

void drawCoverBox(float startingPointX, float startingPointY, float width)
{
    glColor3f(1.0f, 0.0f, 1.0f);
    glLineWidth(10.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(startingPointX - 0.04f, startingPointY + 0.04f);                         // Top-Left
    glVertex2f(startingPointX + (width * 5.5f) + 0.04f, startingPointY + 0.04f);        // Top-Right
    glVertex2f(startingPointX + (width * 5.5f) + 0.04f, startingPointY - width * 1.4f); // Bottom-Right
    glVertex2f(startingPointX - 0.04f, startingPointY - width * 1.4f);                  // Bottom-Left
    glEnd();

    glLineWidth(0.5f);
}

void letterS(float startingPointX, float startingPointY, float width, float thickness)
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 1.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + width, startingPointY);
    glVertex2f(startingPointX + width, startingPointY - thickness);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + width, startingPointY - thickness);
    glVertex2f(startingPointX, startingPointY - thickness);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 2.5f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 2.5f);
    glVertex2f(startingPointX, startingPointY - thickness * 2.5f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY - thickness - 0.06f);
    glVertex2f(startingPointX + width, startingPointY - thickness - 0.06f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 2.5f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY - thickness - 0.06f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 2.5f);
    glVertex2f(startingPointX, startingPointY - thickness * 2.5f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX + width / 1.4f, startingPointY - thickness - 0.06f);
    glVertex2f(startingPointX + width, startingPointY - thickness - 0.06f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 4.0f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX + width / 1.4f, startingPointY - thickness - 0.06f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 4.0f);
    glVertex2f(startingPointX + width / 1.4f, startingPointY - thickness * 4.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY - (thickness * 3));
    glVertex2f(startingPointX + width, startingPointY - (thickness * 3));
    glVertex2f(startingPointX + width, startingPointY - thickness - (thickness * 3));
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY - (thickness * 3));
    glVertex2f(startingPointX + width, startingPointY - thickness - (thickness * 3));
    glVertex2f(startingPointX, startingPointY - thickness - (thickness * 3));
    glEnd();
}

void letterA(float startingPointX, float startingPointY, float width, float thickness)
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 1.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX + width / 2.0f, startingPointY);
    glVertex2f(startingPointX + width / 2.0f + thickness / 1.3f, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4.0f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX + width / 2.0f, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4.0f);
    glVertex2f(startingPointX, startingPointY - thickness * 4.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX - width / 2.0f + width, startingPointY);
    glVertex2f(startingPointX - width / 2.0f + width + thickness / 1.3f, startingPointY);
    glVertex2f(startingPointX + width + thickness / 1.3f, startingPointY - thickness * 4.0f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX - width / 2.0f + width, startingPointY);
    glVertex2f(startingPointX + width + thickness / 1.3f, startingPointY - thickness * 4.0f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 4.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX + 0.16f, startingPointY - thickness - 0.09f);
    glVertex2f(startingPointX - 0.082f + width, startingPointY - thickness - 0.09f);
    glVertex2f(startingPointX - 0.045f + width, startingPointY - thickness * 2.8f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX + 0.16f, startingPointY - thickness - 0.09f);
    glVertex2f(startingPointX - 0.045f + width, startingPointY - thickness * 2.8f);
    glVertex2f(startingPointX + 0.125f, startingPointY - thickness * 2.8f);
    glEnd();
}

void letterG(float startingPointX, float startingPointY, float width, float thickness)
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 1.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + width, startingPointY);
    glVertex2f(startingPointX + width, startingPointY - thickness);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + width, startingPointY - thickness);
    glVertex2f(startingPointX, startingPointY - thickness);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4.0f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4.0f);
    glVertex2f(startingPointX, startingPointY - thickness * 4.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX + (thickness + 0.05f), startingPointY - width / 2.0f);
    glVertex2f(startingPointX + width, startingPointY - width / 2.0f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 2.5f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX + (thickness + 0.05f), startingPointY - width / 2.0f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 2.5f);
    glVertex2f(startingPointX + (thickness + 0.05f), startingPointY - thickness * 2.5f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX + width - thickness / 1.3f, startingPointY - width / 1.8f);
    glVertex2f(startingPointX + width, startingPointY - width / 1.8f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 4.0f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX + width - thickness / 1.3f, startingPointY - width / 1.8f);
    glVertex2f(startingPointX + width, startingPointY - thickness * 4.0f);
    glVertex2f(startingPointX + width - thickness / 1.3f, startingPointY - thickness * 4.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY - (thickness * 3.0f));
    glVertex2f(startingPointX + width, startingPointY - (thickness * 3.0f));
    glVertex2f(startingPointX + width, startingPointY - thickness - (thickness * 3.0f));
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY - (thickness * 3.0f));
    glVertex2f(startingPointX + width, startingPointY - thickness - (thickness * 3.0f));
    glVertex2f(startingPointX, startingPointY - thickness - (thickness * 3.0f));
    glEnd();
}

void letterR(float startingPointX, float startingPointY, float width, float thickness)
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 1.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4.0f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4.0f);
    glVertex2f(startingPointX, startingPointY - thickness * 4.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + width / 0.98f, startingPointY);
    glVertex2f(startingPointX + width / 0.98f, startingPointY - thickness);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY);
    glVertex2f(startingPointX + width / 0.98f, startingPointY - thickness);
    glVertex2f(startingPointX, startingPointY - thickness);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX + width - thickness + 0.02f, startingPointY);
    glVertex2f(startingPointX + width + 0.006f, startingPointY);
    glVertex2f(startingPointX + width + 0.006f, startingPointY - thickness * 2.0f);
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX + width - thickness + 0.02f, startingPointY);
    glVertex2f(startingPointX + width + 0.006f, startingPointY - thickness * 2.0f);
    glVertex2f(startingPointX + width - thickness + 0.02f, startingPointY - thickness * 2.0f);

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY - (width / 2.0f));
    glVertex2f(startingPointX + width / 0.98f, startingPointY - (width / 2.0f));
    glVertex2f(startingPointX + width / 0.98f, startingPointY - thickness - (width / 2.0f));
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY - (width / 2.0f));
    glVertex2f(startingPointX + width / 0.98f, startingPointY - thickness - (width / 2.0f));
    glVertex2f(startingPointX, startingPointY - thickness - (width / 2.0f));

    // Tri 1
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(startingPointX, startingPointY - (width / 2.0f));
    glVertex2f(startingPointX + width, startingPointY - (width));
    glVertex2f(startingPointX + width, startingPointY - thickness - (width));
    // Tri 2
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(startingPointX, startingPointY - (width / 2.0f));
    glVertex2f(startingPointX + width, startingPointY - thickness - (width));
    glVertex2f(startingPointX, startingPointY - (width - 0.05f));
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
