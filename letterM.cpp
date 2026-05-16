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

void letterM(float x, float y, float width, float height, float r, float g, float b)
{
    glColor3f(r, g, b); // Set the solid color
    glBegin(GL_QUADS);

    // left leg
    glVertex2f(x, y);                  // Top-Left corner
    glVertex2f(x, y - height);         // Bottom-Left corner
    glVertex2f(x + width, y - height); // Bottom-Right corner
    glVertex2f(x + width, y);          // Top-Right corner

    // left slanted
    glVertex2f(x, y);                                // Top-Left corner
    glVertex2f(x + 0.2, y - height + 0.2);           // Bottom-Left corner
    glVertex2f(x + width + 0.2f, y - height + 0.2f); // Bottom-Right corner
    glVertex2f(x + width, y);                        // Top-Right corner

    // right slanted
    glVertex2f(x + 0.4f, y);                                // Top-Left corner
    glVertex2f(x + 0.4f - 0.2f, y - height + 0.2f);         // Bottom-Left corner
    glVertex2f(x + 0.4f + width - 0.2f, y - height + 0.2f); // Bottom-Right corner
    glVertex2f(x + 0.4f + width, y);                        // Top-Right corner

    // right leg
    glVertex2f(x + 0.4f, y);                  // Top-Left corner
    glVertex2f(x + 0.4f, y - height);         // Bottom-Left corner
    glVertex2f(x + 0.4f + width, y - height); // Bottom-Right corner
    glVertex2f(x + 0.4f + width, y);          // Top-Right corner

    glEnd();

    // printf("Bottom-Left corner %.1f, %.1f\n", x, y - height);
    // printf("Bottom-Right corner %.1f, %.1f\n", x + width, y + height);
    // printf("Top-Right corner %.1f, %.1f\n", x + width, y);
    // printf("Top-Left corner %.1f, %.1f\n", x, y);
}