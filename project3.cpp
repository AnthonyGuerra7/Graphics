//
//  project3.cpp
//  
//
//  Created by Anthony Lopez-Guerra on 3/1/21.
//

#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Global constants
#define MIN_X_VIEW -50
#define MAX_X_VIEW 50
#define MIN_Y_VIEW -50
#define MAX_Y_VIEW 50
#define MIN_Z_VIEW -50
#define MAX_Z_VIEW 50
#define MIN_X_SCREEN 0
#define MAX_X_SCREEN 500
#define MIN_Y_SCREEN 0
#define MAX_Y_SCREEN 500
#define LINE_COUNT 1000

// Define global variables
#define SIZE 32
float Px[SIZE + 1][SIZE + 1];
float Py[SIZE + 1][SIZE + 1];
float Pz[SIZE + 1][SIZE + 1];
int xangle = 0;
int yangle = 0;
int zangle = 0;
int mode = 2;
int count = 0;
float point[LINE_COUNT][4];

//---------------------------------------
// Define vase surface
//---------------------------------------
void define_vase()
{
   // Create X-Y profile
   for (int i = 0; i <= SIZE; i++)
   {
      float theta = i * 2 * M_PI / SIZE;
      Px[i][0] = 40*(0.2 * sin(theta) + 0.5);
      Py[i][0] = 40*((float) i / (float) SIZE - 0.5);
      Pz[i][0] = 0.0;
   }

   // Perform rotation around Y axis
   for (int j = 1; j <= SIZE; j++)
   {
      float theta = j * 2 * M_PI / SIZE;
      float cos_theta = cos(theta);
      float sin_theta = sin(theta);
      for (int i = 0; i <= SIZE; i++)
      {
     Px[i][j] = Px[i][0] * cos_theta - Pz[i][0] * sin_theta;
     Py[i][j] = Py[i][0];
     Pz[i][j] = Px[i][0] * sin_theta + Pz[i][0] * cos_theta;
      }
   }
}


//---------------------------------------
// Init function for OpenGL
//---------------------------------------
void init()
{
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(MIN_X_VIEW, MAX_X_VIEW,
      MIN_Y_VIEW, MAX_Y_VIEW,
      MIN_Z_VIEW, MAX_Z_VIEW);
   xangle = (xangle + 5) % 360;
   yangle = (yangle + 5) % 360;
   zangle = (zangle + 5) % 360;
   glEnable(GL_DEPTH_TEST);
   define_vase();
}

//---------------------------------------
// Function to draw a zero thickness wall
//---------------------------------------
void wall(float x1, float y1, float x2, float y2)
{
   float z1 = 0;

   // Draw wall outline
   glBegin(GL_LINES);
   glVertex3f(x1, y1, z1);
   glVertex3f(x2, y2, z1);
   glEnd();
}

//---------------------------------------
// Keyboard callback for OpenGL
//---------------------------------------
void keyboard(unsigned char key, int x, int y)
{
   // Update angles
   if (key == 'x')
      xangle -= 5;
   else if (key == 'X')
      xangle += 5;
   else if (key == 'y')
      yangle -= 5;
   else if (key == 'Y')
      yangle += 5;
   else if (key == 'z')
      zangle -= 5;
   else if (key == 'Z')
      zangle += 5;

   // Redraw objects
   glutPostRedisplay();
}
//---------------------------------------
// Mouse callback for OpenGL
//---------------------------------------
void mouse(int button, int state, int x, int y)
{
   // Calculate scale factors
   if (mode != 2) return;
   float x_scale = (MAX_X_VIEW - MIN_X_VIEW) /
      (float)(MAX_X_SCREEN - MIN_X_SCREEN);
   float y_scale = (MIN_Y_VIEW - MAX_Y_VIEW) /
      (float)(MAX_Y_SCREEN - MIN_Y_SCREEN);

   // Handle mouse down
   if (state == GLUT_DOWN)
   {
      point[count][0] = MIN_X_VIEW + (x - MIN_X_SCREEN) * x_scale;
      point[count][1] = MAX_Y_VIEW + (y - MIN_Y_SCREEN) * y_scale;
   }

   // Handle mouse up
   else if (state == GLUT_UP)
   {
      point[count][2] = MIN_X_VIEW + (x - MIN_X_SCREEN) * x_scale;
      point[count][3] = MAX_Y_VIEW + (y - MIN_Y_SCREEN) * y_scale;
      count++;
      glutPostRedisplay();
   }
}

//---------------------------------------
// Motion callback for OpenGL
//---------------------------------------
void motion(int x, int y)
{
   // Calculate scale factors
   if (mode != 2) return;
   float x_scale = (MAX_X_VIEW - MIN_X_VIEW) /
      (float)(MAX_X_SCREEN - MIN_X_SCREEN);
   float y_scale = (MIN_Y_VIEW - MAX_Y_VIEW) /
      (float)(MAX_Y_SCREEN - MIN_Y_SCREEN);

   // Handle mouse motion
   point[count][2] = MIN_X_VIEW + (x - MIN_X_SCREEN) * x_scale;
   point[count][3] = MAX_Y_VIEW + (y - MIN_Y_SCREEN) * y_scale;
   glutPostRedisplay();
}


//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display()
{
   // Incrementally rotate objects
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glRotatef(xangle, 1.0, 0.0, 0.0);
   glRotatef(yangle, 0.0, 1.0, 0.0);
   glRotatef(zangle, 0.0, 1.0, 0.0);
    
    // Draw object surface
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i <= SIZE; i++)
    {
       glBegin(GL_LINE_STRIP);
       for (int j = 0; j <= SIZE; j++)
      glVertex3f(Px[i][j], Py[i][j], Pz[i][j]);
       glEnd();
    }
    for (int j = 0; j <= SIZE; j++)
    {
       glBegin(GL_LINE_STRIP);
       for (int i = 0; i <= SIZE; i++)
      glVertex3f(Px[i][j], Py[i][j], Pz[i][j]);
       glEnd();
    }

   // Draw all walls
   for (int i=0; i<=count; i++)
      if ((point[i][0] != point[i][2]) || (point[i][1] != point[i][3]))
         wall(point[i][0], point[i][1], point[i][2], point[i][3]);
   glFlush();
}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitWindowSize(MAX_Y_SCREEN, MAX_X_SCREEN);
   glutInitWindowPosition(MAX_Y_SCREEN/2, MAX_X_SCREEN/2);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
   glutCreateWindow("project3");
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   init();
   printf("Keyboard commands:\n");
   printf("   'x' - rotate x-axis -5 degrees\n");
   printf("   'X' - rotate x-axis +5 degrees\n");
   printf("   'y' - rotate y-axis -5 degrees\n");
   printf("   'Y' - rotate y-axis +5 degrees\n");
   printf("   'z' - rotate z-axis -5 degrees\n");
   printf("   'Z' - rotate z-axis +5 degrees\n");
   printf("Mouse operations:\n");
   printf("   'mouse down' - start drawing line\n");
   printf("   'mouse motion' - draw rubber-band line\n");
   printf("   'mouse up' - finish drawing line\n");
   glutMainLoop();
   return 0;
}
