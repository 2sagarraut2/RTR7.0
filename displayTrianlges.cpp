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

void displayTriangles(float startX, float endX, float startHeight, float slope, float flagHeight)
{
    float step = 0.2f;

    for (float x = startX; x < endX; x += step)
    {
        float x2 = -1.0f + x;

        float y2 = startHeight + (slope * (x2 - (-1.0f + startX)));
        glColor3f(x * 2.0f, x * 1.0f, 0.0f);
        glVertex3f(x2, y2, 0.0f);

        float x3 = -0.8f + x;
        float y3 = startHeight + (slope * (x3 - (-1.0f + startX)));
        glColor3f(x / 1.0f, x * 1.0f, 0.0f);
        glVertex3f(x3, y3, 0.0f);

        float x1 = -0.9f + x;
        float centerBaselineY = startHeight + (slope * (x1 - (-1.0f + startX)));
        float tipY = centerBaselineY - flagHeight;
        glColor3f(x / 2.0f, x * 1.0f, 0.0f);
        glVertex3f(x1, tipY, 0.0f);
    }
}