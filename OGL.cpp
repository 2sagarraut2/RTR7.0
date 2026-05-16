#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "MyWork.h"

bool bIsFullScreen = false;

// function declarations
void initialize(void);
void uninitialize(void);
void resize(int, int);
void display(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);

int main(int argc, char *argv[])
{
    // code
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Happy Birthday Vikram");

    initialize();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    // flow should not come here
    return (0);
}

void initialize(void)
{
    // code
    glClearColor(0.69f, 0.77f, 0.87f, 1.0f);
}

// COMPLETE REPAIR FOR LINE 49:
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
    displayTriangles(0.8f, 2.0f, 1.0f, -0.3f, 0.5f);
    displayTriangles(0.0f, 2.0f, 0.5f, 0.4f, 0.4f);

    glEnd();

    // float x, float y, float width, float height, float r, float g, float b
    displayGiftBox(-0.9f, -0.5f, 0.15f, 0.4f, 0.0f, 0.0f, 1.0f);

    // float x, float y, float width, float height, float r, float g, float b
    letterM(-0.4f, 0.0f, 0.08f, 0.5f, 0.0f, 0.6f, 0.0f);

    // float x, float y, float width, float height, float r, float g, float b
    letterK(0.5f, 0.0f, 0.05f, 0.8f, 0.0f, 0.6f, 0.0f);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    // code
    switch (key)
    {
    case 27:
        uninitialize();
        exit(0);
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
            glutReshapeWindow(800, 600);
            glutPositionWindow(100, 100);
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
        if (state == GLUT_DOWN)
        {
            uninitialize();
            exit(0);
        }
        break;
    default:
        break;
    }
}

void uninitialize(void)
{
}
