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
    glutCreateWindow("My Name : Sagar Raut");

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
    glLineWidth(8.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(startingPointX - 0.04f, startingPointY + 0.04f);                         // Top-Left
    glVertex2f(startingPointX + (width * 5.5f) + 0.04f, startingPointY + 0.04f);        // Top-Right
    glVertex2f(startingPointX + (width * 5.5f) + 0.04f, startingPointY - width * 1.4f); // Bottom-Right
    glVertex2f(startingPointX - 0.04f, startingPointY - width * 1.4f);                  // Bottom-Left
    glEnd();

    glLineWidth(1.0f);
}

void letterS(float startingPointX, float startingPointY, float width, float thickness)
{

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY);                     // Top-Left
    glVertex2f(startingPointX + width, startingPointY);             // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness);         // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY);                                       // Top-Left
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY);                    // Top-Right
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 2.5f); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness * 2.5);                     // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY - thickness - 0.06f);         // Top-Left
    glVertex2f(startingPointX + width, startingPointY - thickness - 0.06f); // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness * 2.5f);  // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness * 2.5f);          // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX + width / 1.4f, startingPointY - thickness - 0.06f); // Top-Left
    glVertex2f(startingPointX + width, startingPointY - thickness - 0.06);         // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness * 4.0f);         // Bottom-Right
    glVertex2f(startingPointX + width / 1.4f, startingPointY - thickness * 4.0f);  // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY - (thickness * 3));                     // Top-Left
    glVertex2f(startingPointX + width, startingPointY - (thickness * 3));             // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness - (thickness * 3)); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness - (thickness * 3));         // Bottom-Left

    glEnd();
}

void letterA(float startingPointX, float startingPointY, float width, float thickness)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX + width / 2, startingPointY);                        // Top-Left
    glVertex2f(startingPointX + width / 2 + thickness / 1.3f, startingPointY);     // Top-Right
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness * 4);                    // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX - width / 2 + width, startingPointY);                        // Top-Left
    glVertex2f(startingPointX - width / 2 + width + thickness / 1.3f, startingPointY);     // Top-Right
    glVertex2f(startingPointX + width + thickness / 1.3f, startingPointY - thickness * 4); // Bottom-Right
    glVertex2f(startingPointX + width, startingPointY - thickness * 4);                    // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX + 0.16f, startingPointY - thickness - 0.09f);          // Top-Left
    glVertex2f(startingPointX - 0.082f + width, startingPointY - thickness - 0.09f); // Top-Right
    glVertex2f(startingPointX - 0.045f + width, startingPointY - thickness * 2.8f);  // Bottom-Right
    glVertex2f(startingPointX + 0.125f, startingPointY - thickness * 2.8f);          // Bottom-Left

    // printf("Top-Left - %f, %f\t", startingPointX + width / 2, startingPointY);
    // printf("Top-Right - %f, %f\t", startingPointX + width / 2 + thickness / 1.3f, startingPointY);
    // printf("Bottom-Right - %f, %f\t", startingPointX + thickness / 1.3f, startingPointY - thickness * 4);
    // printf("Bottom-Left - %f, %f\n", startingPointX, startingPointY - thickness * 4);

    // printf("Top-Left - %f, %f\t", startingPointX - width / 2 + width, startingPointY);
    // printf("Top-Right - %f, %f\t", startingPointX - width / 2 + width + thickness / 1.3f, startingPointY);
    // printf("Bottom-Right - %f, %f\t", startingPointX + width + thickness / 1.3f, startingPointY - thickness * 4);
    // printf("Bottom-Left - %f, %f\n", startingPointX + width, startingPointY - thickness * 4);

    glEnd();
}

void letterG(float startingPointX, float startingPointY, float width, float thickness)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY);                     // Top-Left
    glVertex2f(startingPointX + width, startingPointY);             // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness);         // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY);                                    // Top-Left
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY);                 // Top-Right
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness * 4);                    // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX + (thickness + 0.05f), startingPointY - width / 2.0f);    // Top-Left
    glVertex2f(startingPointX + width, startingPointY - width / 2.0f);                  // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness * 2.5);               // Bottom-Right
    glVertex2f(startingPointX + (thickness + 0.05f), startingPointY - thickness * 2.5); // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX + width - thickness / 1.3f, startingPointY - width / 1.8f);  // Top-Left
    glVertex2f(startingPointX + width, startingPointY - width / 1.8f);                     // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness * 4);                    // Bottom-Right
    glVertex2f(startingPointX + width - thickness / 1.3f, startingPointY - thickness * 4); // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY - (thickness * 3));                     // Top-Left
    glVertex2f(startingPointX + width, startingPointY - (thickness * 3));             // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness - (thickness * 3)); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness - (thickness * 3));         // Bottom-Left

    glEnd();
}

void letterR(float startingPointX, float startingPointY, float width, float thickness)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY);                                    // Top-Left
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY);                 // Top-Right
    glVertex2f(startingPointX + thickness / 1.3f, startingPointY - thickness * 4); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness * 4);                    // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY);                             // Top-Left
    glVertex2f(startingPointX + width / 0.98f, startingPointY);             // Top-Right
    glVertex2f(startingPointX + width / 0.98f, startingPointY - thickness); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness);                 // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX + width - thickness + 0.02f, startingPointY);                 // Top-Left
    glVertex2f(startingPointX + width + 0.006f, startingPointY);                            // Top-Right
    glVertex2f(startingPointX + width + 0.006f, startingPointY - thickness * 2);            // Bottom-Right
    glVertex2f(startingPointX + width - thickness + 0.02f, startingPointY - thickness * 2); // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY - (width / 2));                             // Top-Left
    glVertex2f(startingPointX + width / 0.98f, startingPointY - (width / 2));             // Top-Right
    glVertex2f(startingPointX + width / 0.98f, startingPointY - thickness - (width / 2)); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - thickness - (width / 2));                 // Bottom-Left

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(startingPointX, startingPointY - (width / 2));                 // Top-Left
    glVertex2f(startingPointX + width, startingPointY - (width));             // Top-Right
    glVertex2f(startingPointX + width, startingPointY - thickness - (width)); // Bottom-Right
    glVertex2f(startingPointX, startingPointY - (width - 0.05f));             // Bottom-Left

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
