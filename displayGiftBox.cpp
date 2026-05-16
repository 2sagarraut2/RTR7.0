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

void displayGiftBox(float x, float y, float width, float height, float r, float g, float b)
{
    float totalWidth = (width * 2) + 0.03f;
    float ribbonThickness = 0.03f;
    float ribbonY = y - (height / 2);

    // Depth offsets
    float d = 0.08f;

    // Shading multipliers for 3D effect
    float topR = r * 1.1f, topG = g * 1.1f, topB = b * 1.1f;    // Brighter top
    float sideR = r * 0.7f, sideG = g * 0.7f, sideB = b * 0.7f; // Darker right side
    float sideRibbon = 0.85f;                                   // Darker white for side ribbon

    // FRONT FACE
    // Left Front Block
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x, y - height);
    glVertex2f(x + width, y - height);
    glVertex2f(x + width, y);
    glEnd();

    // Right Front Block
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x + width + 0.03f, y);
    glVertex2f(x + width + 0.03f, y - height);
    glVertex2f(x + totalWidth, y - height);
    glVertex2f(x + totalWidth, y);
    glEnd();

    // Vertical Front Ribbon
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y - height);
    glVertex2f(x + width + 0.03f, y - height);
    glVertex2f(x + width + 0.03f, y);
    glEnd();

    // Horizontal Front Ribbon
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x, ribbonY + (ribbonThickness / 2));
    glVertex2f(x, ribbonY - (ribbonThickness / 2));
    glVertex2f(x + totalWidth, ribbonY - (ribbonThickness / 2));
    glVertex2f(x + totalWidth, ribbonY + (ribbonThickness / 2));
    glEnd();

    // RIGHT SIDE FACE

    // Lower Right Side Block
    glColor3f(sideR, sideG, sideB);
    glBegin(GL_QUADS);
    glVertex2f(x + totalWidth, ribbonY - (ribbonThickness / 2));
    glVertex2f(x + totalWidth, y - height);
    glVertex2f(x + totalWidth + d, y - height + d);
    glVertex2f(x + totalWidth + d, ribbonY - (ribbonThickness / 2) + d);
    glEnd();

    // Upper Right Side Block
    glColor3f(sideR, sideG, sideB);
    glBegin(GL_QUADS);
    glVertex2f(x + totalWidth, y);
    glVertex2f(x + totalWidth, ribbonY + (ribbonThickness / 2));
    glVertex2f(x + totalWidth + d, ribbonY + (ribbonThickness / 2) + d);
    glVertex2f(x + totalWidth + d, y + d);
    glEnd();

    // Right Side Ribbon
    glColor3f(sideRibbon, sideRibbon, sideRibbon);
    glBegin(GL_QUADS);
    glVertex2f(x + totalWidth, ribbonY + (ribbonThickness / 2));
    glVertex2f(x + totalWidth, ribbonY - (ribbonThickness / 2));
    glVertex2f(x + totalWidth + d, ribbonY - (ribbonThickness / 2) + d);
    glVertex2f(x + totalWidth + d, ribbonY + (ribbonThickness / 2) + d);
    glEnd();

    // TOP FACE (With intersecting cross ribbons)

    // Top Base Blocks
    glColor3f(topR, topG, topB);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + totalWidth, y);
    glVertex2f(x + totalWidth + d, y + d);
    glVertex2f(x + d, y + d);
    glEnd();

    // Top Face: Front-to-Back Ribbon
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x + width, y);
    glVertex2f(x + width + 0.03f, y);
    glVertex2f(x + width + 0.03f + d, y + d);
    glVertex2f(x + width + d, y + d);
    glEnd();

    // Right side alignment matches the right side ribbon's top-left and bottom-left points
    glVertex2f(x + totalWidth + (d / 2), y + (d / 2) - (ribbonThickness / 2));
    glVertex2f(x + totalWidth + (d / 2), y + (d / 2) + (ribbonThickness / 2));
    glEnd();
}