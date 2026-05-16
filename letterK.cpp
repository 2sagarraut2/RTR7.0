#include "MyWork.h"

#ifdef __APPLE__
// macOS Headers
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif defined(_WIN32) || defined(_WIN64)
// Windows Headers
#include <windows.h> // Required on Windows before including GL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h> // Assumes you downloaded FreeGLUT/GLUT for Windows
#endif

void letterK(float x, float y, float width, float height, float r, float g, float b)
{
    glColor3f(r, g, b); // Set the solid color

    // 1. LEFT VERTICAL LEG (Your reference line)
    glBegin(GL_QUADS);
    glVertex2f(x, y);                  // Top-Left corner
    glVertex2f(x, y - height);         // Bottom-Left corner
    glVertex2f(x + width, y - height); // Bottom-Right corner
    glVertex2f(x + width, y);          // Top-Right corner
    glEnd();

    // Geometric references for diagonals
    float midY = y - (height / 2.0f);    // Middle point of the vertical leg
    float diagReachX = width * 3.5f;     // How far out the K legs stretch horizontally
    float slantThickness = width * 0.9f; // Controls the thickness of the diagonal rectangles

    // 2. UPPER RIGHT DIAGONAL LEG
    glBegin(GL_QUADS);
    // Connects to the vertical leg's right side near the middle
    glVertex2f(x + width, midY + (slantThickness / 2.0f));
    glVertex2f(x + width, midY - (slantThickness / 2.0f));
    // Extends to the top right
    glVertex2f(x + width + diagReachX, y - (slantThickness / 2.0f));
    glVertex2f(x + width + diagReachX, y + (slantThickness / 2.0f));
    glEnd();

    // 3. LOWER RIGHT DIAGONAL LEG
    glBegin(GL_QUADS);
    // Connects to the upper diagonal's base near the middle
    glVertex2f(x + width, midY + (slantThickness / 2.0f));
    glVertex2f(x + width, midY - (slantThickness / 2.0f));
    // Extends to the bottom right
    glVertex2f(x + width + diagReachX, (y - height) - (slantThickness / 2.0f));
    glVertex2f(x + width + diagReachX, (y - height) + (slantThickness / 2.0f));
    glEnd();

    // Print statements for your reference tracking
    // printf("Vertical Line - Top-Left: %.1f, %.1f\n", x, y);
    // printf("Vertical Line - Bottom-Left: %.1f, %.1f\n", x, y - height);
}