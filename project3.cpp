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
#define SIZE 36
float Px[SIZE + 1][SIZE + 1];
float Py[SIZE + 1][SIZE + 1];
float Pz[SIZE + 1][SIZE + 1];
int xangle = 0;
int yangle = 0;
int zangle = 0;
int mode = 2;
int lineCount = 0;
float point[LINE_COUNT][4];
bool drawLine = false;

//---------------------------------------
// Define vase surface borrowed from Gauch's source code. Modified the orientation from drawing around the Y-axis to drawing on the X-axis and changed the equation drawing the "vase shape" to my own.
//---------------------------------------
void define_vase()
{
   // Create X-Y profile
   for (int i = 0; i <= SIZE; i++)
   {
      float theta = i * 2 * M_PI / SIZE;
      Px[i][0] = 30*((float) i / (float) SIZE - 0.5);
       Py[i][0]= 30*((abs(sin(theta*theta)/pow(2,((theta*theta) - M_PI/2)/M_PI)))+0.25);
      Pz[i][0] = 0.0;
   }

   // Perform rotation around X axis
   for (int j = 1; j <= SIZE; j++)
   {
      float theta = j * 2 * M_PI / SIZE;
      float cos_theta = cos(theta);
      float sin_theta = sin(theta);
      for (int i = 0; i <= SIZE; i++)
      {
          Px[i][j] = Px[i][0];
          Py[i][j] = Py[i][0] * cos_theta - Pz[i][0] * sin_theta;
          Pz[i][j] = Py[i][0] * sin_theta + Pz[i][0] * cos_theta;
      }
   }
}

//---------------------------------------
// Define gatherDataPoints this method takes the data points that were gathered from drawing the shape manually and doing the same calculations as in the define vase method except for the rotation around the X-axis for the shape drawn.
//---------------------------------------

void gatherDataPoints(){
    int samplePoints = lineCount/36;
    for(int i = 0; i <= SIZE; i++){
        Px[i][0] = point[i*samplePoints][0];
        Py[i][0] = point[i*samplePoints][1];
        Pz[i][0] = 0;
    }
        
    for (int j = 1; j <= SIZE; j++)
    {
        float theta = j * 2 * M_PI / SIZE;
        float cos_theta = cos(theta);
        float sin_theta = sin(theta);
        for (int i = 0; i <= SIZE; i++)
        {
            Px[i][j] = Px[i][0];
            Py[i][j] = Py[i][0] * cos_theta - Pz[i][0] * sin_theta;
            Pz[i][j] = Py[i][0] * sin_theta + Pz[i][0] * cos_theta;
        }
    }
}


//---------------------------------------
// Init function for OpenGL borrowed from Gauch's source code
//---------------------------------------
void init()
{
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(MIN_X_VIEW, MAX_X_VIEW,
      MIN_Y_VIEW, MAX_Y_VIEW,
      MIN_Z_VIEW, MAX_Z_VIEW);
   xangle = (xangle) % 360;
   yangle = (yangle) % 360;
   zangle = (zangle) % 360;
   glEnable(GL_DEPTH_TEST);
   define_vase();
}

//---------------------------------------
// Function to draw a zero thickness line. created a line with 0 thickness. borrowed from Gauch's source code
//---------------------------------------
void createLine(float x1, float y1, float x2, float y2)
{
   float z1 = 0;

   // Draw wall outline
   glBegin(GL_LINES);
   glVertex3f(x1, y1, z1);
   glVertex3f(x2, y2, z1);
   glEnd();
}

//---------------------------------------
// Keyboard callback for OpenGL borrowed from Gauch's source code
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
    printf("x-angle: %d ",xangle);
    printf("y-angle: %d ",yangle);
    printf("z-angle: %d ",zangle);
   glutPostRedisplay();
}
//---------------------------------------
// Mouse callback for OpenGL borrowed from Gauch's source code, modified the code. Leaving the comments so it makes it easier to show where I changed the code from what working code Dr. Gauch had to changing it to draw through the entire motion. This allowed for the shape to be drawn once the mouse click is over, the lineCount is reset to 0 so that upon clicking the mouse again it will erase the old data points and only show the new drawing.
//---------------------------------------
void mouse(int button, int state, int x, int y)
{
   // Calculate scale factors
//   if (mode != 2) return;
//   float x_scale = (MAX_X_VIEW - MIN_X_VIEW) /
//      (float)(MAX_X_SCREEN - MIN_X_SCREEN);
//   float y_scale = (MIN_Y_VIEW - MAX_Y_VIEW) /
//      (float)(MAX_Y_SCREEN - MIN_Y_SCREEN);

   // Handle mouse down
   if (state == GLUT_DOWN)
   {
//      point[count][0] = MIN_X_VIEW + (x - MIN_X_SCREEN) * x_scale;
//      point[count][1] = MAX_Y_VIEW + (y - MIN_Y_SCREEN) * y_scale;
       drawLine = true;
   }

   // Handle mouse up
   else if (state == GLUT_UP)
   {
//      point[count][2] = MIN_X_VIEW + (x - MIN_X_SCREEN) * x_scale;
//      point[count][3] = MAX_Y_VIEW + (y - MIN_Y_SCREEN) * y_scale;
//      count++;
      drawLine = false;
      gatherDataPoints();
      lineCount = 0;
      glutPostRedisplay();
   }
}

//---------------------------------------
// Motion callback for OpenGL. modified the motion method so that the drawing only occured once the mouse had been clicked and stopped following and tracking the points after the click was selected.
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
    if(drawLine == true){
        point[lineCount][0] = MIN_X_VIEW + (x - MIN_X_SCREEN) * x_scale;
        point[lineCount][1] = MAX_Y_VIEW + (y - MIN_Y_SCREEN) * y_scale;
        lineCount++;
        
    }
    glutPostRedisplay();
}


//---------------------------------------
// Display callback for OpenGL borrowed from Gauch's source code
//---------------------------------------
void display()
{
   // Incrementally rotate objects
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
    
   glRotatef(xangle, 1.0, 0.0, 0.0);
   glRotatef(yangle, 0.0, 1.0, 0.0);
   glRotatef(zangle, 0.0, 0.0, 1.0);
    
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

   // Draw all lines
   for (int i=1; i<lineCount; i++)
    
         createLine(point[i-1][0], point[i-1][1], point[i][0], point[i][1]);
    
   glFlush();
}

//---------------------------------------
// Main program borrowed from Gauch's source code
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

