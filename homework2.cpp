//---------------------------------------
// Program: tetris.cpp
// Purpose: Draw seven tetris shapes.
// Author:  John Gauch
// Date:    Spring 2021
// Anthony Lopez-Guerra
// 010561185
//---------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <vector>
using namespace std;

vector<float> xpos;
vector<float> ypos;
float w = 1;
vector<float> RedColor;
vector<float> GreenColor;
vector<float> BlueColor;
vector<float> currentRotation;
vector<int> squarePosition;
vector<char> shape;
bool pieceCreated = false;
bool lockedIn = false;
int screenWidth = 10;
int screenHeight = 20;


/*
 Used Dr. Gauch's homework 1 source code as starting template for homework 2 just in case if there were any errors in my implementation of homework 1, I could eliminate them by using a correct version.
*/

void drawGrid(){
	for(int i = 0; i < 10;i++){
		glBegin(GL_LINES);
		glColor3f(0.9,0.9,0.9);
		glVertex2f((i*w),0);
		glVertex2f((i*w), 20);
		glEnd();
	}
	for(int i = 0; i < 20; i++){
		glBegin(GL_LINES);
		glColor3f(0.9,0.9,0.9);
		glVertex2f(0,(i*w));
		glVertex2f(10, (i*w));
		glEnd();
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
   glOrtho(0.0, 10.0, 0.0, 20.0, -1.0, 1.0);
	
}



//---------------------------------------
// Draw one square
//---------------------------------------
void draw_square(float x, float y, float w, float R, float G, float B, float rotation, int squareBlock)
{
   glBegin(GL_POLYGON);
   glColor3f(R, G, B);
   glVertex2f(x-w/2, y-w/2);
   glVertex2f(x-w/2, y+w/2);
   glVertex2f(x+w/2, y+w/2);
   glVertex2f(x+w/2, y-w/2);
   glEnd();
//	printf("I am calling the draw square method\n");
   glLineWidth(3);
   glBegin(GL_LINE_LOOP);
   glColor3f(R/2, G/2, B/2);
   glVertex2f(x-w/2, y-w/2);
   glVertex2f(x-w/2, y+w/2);
   glVertex2f(x+w/2, y+w/2);
   glVertex2f(x+w/2, y-w/2);
   glEnd();
}


//---------------------------------------
// Rotate functin for the I shape for OpenGL

void RotateI(int position, int squareBlock, float &xpos, float &ypos){
	
	switch(position){
		case 0:
			switch (squareBlock) {
				case 1:
//					printf("case 0\n");
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 2:
					break;
				case 3:
					xpos = xpos + w;
					ypos = ypos - w;
					break;
				case 4:
					xpos = xpos + 2*w;
					ypos = ypos - 2*w;
					break;
					
				default:
					break;
			}
			break;
		case 1:
			switch (squareBlock) {
				case 1:
//					printf("case 1 square 1\n");
					xpos = xpos +w;
					ypos = ypos + w;
					break;
				case 2:
//					printf("case 1 square2\n");
					break;
				case 3:
//					printf("case 1 square3\n");
					xpos = xpos - w;
					ypos = ypos - w;
					break;
				case 4:
//					printf("case 1 square4\n");
					xpos = xpos-2*w;
					ypos = ypos-2*w;
					break;
					
				default:
					break;
			}
			break;
		case 2:
			switch (squareBlock) {
				case 1:
//					printf("case 2\n");
					xpos = xpos + w;
					ypos = ypos - w;
					
					break;
				case 2:
					
					break;
				case 3:
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 4:
					xpos = xpos - 2*w;
					ypos = ypos + 2*w;
					
					break;
					
				default:
					break;
			}
			break;
		case 3:
			switch (squareBlock) {
				case 1:
//					printf("case 3\n");
					xpos = xpos - w;
					ypos = ypos - w;
					break;
				case 2:
					
					break;
				case 3:
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 4:
					xpos = xpos +2*w;
					ypos = ypos +2*w;
					break;
					
				default:
					break;
			}
			break;
			
	}
}

//---------------------------------------
// Rotate functin for the J shape for OpenGL

void RotateJ(int position, int squareBlock, float &xpos, float &ypos){
	
	switch(position){
		case 0:
			switch (squareBlock) {
				case 1:
//					printf("case 0\n");
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 2:
					break;
				case 3:
					xpos = xpos + w;
					ypos = ypos - w;
					break;
				case 4:
					xpos = xpos + 2*w;
					ypos = ypos - 2*w;
					break;
					
				default:
					break;
			}
			break;
		case 1:
			switch (squareBlock) {
				case 1:
//					printf("case 1 square 1\n");
					xpos = xpos +w;
					ypos = ypos - w;
					break;
				case 2:
//					printf("case 1 square2\n");
					break;
				case 3:
//					printf("case 1 square3\n");
					xpos = xpos - w;
					ypos = ypos - w;
					break;
				case 4:
//					printf("case 1 square4\n");
					xpos = xpos-2*w;
					ypos = ypos-2*w;
					break;
					
				default:
					break;
			}
			break;
		case 2:
			switch (squareBlock) {
				case 1:
//					printf("case 2\n");
					xpos = xpos - w;
					ypos = ypos - w;
					
					break;
				case 2:
					
					break;
				case 3:
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 4:
					xpos = xpos - 2*w;
					ypos = ypos + 2*w;
					
					break;
					
				default:
					break;
			}
			break;
		case 3:
			switch (squareBlock) {
				case 1:
//					printf("case 3\n");
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 2:
					
					break;
				case 3:
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 4:
					xpos = xpos +2*w;
					ypos = ypos +2*w;
					break;
					
				default:
					break;
			}
			break;
			
	}
}

//---------------------------------------
// Rotate functin for the L shape for OpenGL

void RotateL(int position, int squareBlock, float &xpos, float &ypos){
	
	switch(position){
		case 0:
			switch (squareBlock) {
				case 1:
//					printf("case 0\n");
					xpos = xpos - 2*w;
					ypos = ypos + 2*w;
					break;
				case 2:
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 3:
					break;
				case 4:
					xpos = xpos + w;
					ypos = ypos + w;
					break;
					
				default:
					break;
			}
			break;
		case 1:
			switch (squareBlock) {
				case 1:
//					printf("case 1 square 1\n");
					xpos = xpos +2*w;
					ypos = ypos +2*w;
					break;
				case 2:
//					printf("case 1 square2\n");
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 3:
//					printf("case 1 square3\n");
					break;
				case 4:
//					printf("case 1 square4\n");
					xpos = xpos + w;
					ypos = ypos - w;
					break;
					
				default:
					break;
			}
			break;
		case 2:
			switch (squareBlock) {
				case 1:
//					printf("case 2\n");
					xpos = xpos + 2*w;
					ypos = ypos - 2*w;
					
					break;
				case 2:
					xpos = xpos + w;
					ypos = ypos - w;
					break;
				case 3:
					break;
				case 4:
					xpos = xpos - w;
					ypos = ypos - w;
					
					break;
					
				default:
					break;
			}
			break;
		case 3:
			switch (squareBlock) {
				case 1:
//					printf("case 3\n");
					xpos = xpos - 2*w;
					ypos = ypos - 2*w;
					break;
				case 2:
					xpos = xpos - w;
					ypos = ypos - w;
					break;
				case 3:
					break;
				case 4:
					xpos = xpos -w;
					ypos = ypos +w;
					break;
					
				default:
					break;
			}
			break;
			
	}
}

//---------------------------------------
// Rotate functin for the T shape for OpenGL

void RotateT(int position, int squareBlock, float &xpos, float &ypos){
	
	switch(position){
		case 0:
			switch (squareBlock) {
				case 1:
//					printf("case 0\n");
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 2:
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 3:
					break;
				case 4:
					xpos = xpos + w;
					ypos = ypos - w;
					break;
					
				default:
					break;
			}
			break;
		case 1:
			switch (squareBlock) {
				case 1:
//					printf("case 1 square 1\n");
					xpos = xpos +w;
					ypos = ypos -w;
					break;
				case 2:
//					printf("case 1 square2\n");
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 3:
//					printf("case 1 square3\n");
					break;
				case 4:
//					printf("case 1 square4\n");
					xpos = xpos - w;
					ypos = ypos - w;
					break;
					
				default:
					break;
			}
			break;
		case 2:
			switch (squareBlock) {
				case 1:
//					printf("case 2\n");
					xpos = xpos - w;
					ypos = ypos - w;
					
					break;
				case 2:
					xpos = xpos + w;
					ypos = ypos - w;
					break;
				case 3:
					break;
				case 4:
					xpos = xpos - w;
					ypos = ypos + w;
					
					break;
					
				default:
					break;
			}
			break;
		case 3:
			switch (squareBlock) {
				case 1:
//					printf("case 3\n");
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 2:
					xpos = xpos - w;
					ypos = ypos - w;
					break;
				case 3:
					break;
				case 4:
					xpos = xpos +w;
					ypos = ypos +w;
					break;
					
				default:
					break;
			}
			break;
			
	}
}

//---------------------------------------
// Rotate functin for the S shape for OpenGL

void RotateS(int position, int squareBlock, float &xpos, float &ypos){
	
	switch(position){
		case 0:
			switch (squareBlock) {
				case 1:
//					printf("case 0\n");
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 2:
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 3:
					break;
				case 4:
					xpos = xpos + 2*w;
					
					break;
					
				default:
					break;
			}
			break;
		case 1:
			switch (squareBlock) {
				case 1:
//					printf("case 1 square 1\n");
					xpos = xpos +w;
					ypos = ypos -w;
					break;
				case 2:
//					printf("case 1 square2\n");
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 3:
//					printf("case 1 square3\n");
					break;
				case 4:
//					printf("case 1 square4\n");
					ypos = ypos -2*w;
					break;
					
				default:
					break;
			}
			break;
		case 2:
			switch (squareBlock) {
				case 1:
//					printf("case 2\n");
					xpos = xpos - w;
					ypos = ypos - w;
					
					break;
				case 2:
					xpos = xpos + w;
					ypos = ypos - w;
					break;
				case 3:
					break;
				case 4:
					xpos = xpos -2*w;
					
					
					break;
					
				default:
					break;
			}
			break;
		case 3:
			switch (squareBlock) {
				case 1:
//					printf("case 3\n");
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 2:
					xpos = xpos - w;
					ypos = ypos - w;
					break;
				case 3:
					break;
				case 4:
					ypos = ypos + 2*w;
					break;
					
				default:
					break;
			}
			break;
			
	}
}

//---------------------------------------
// Rotate functin for the O shape for OpenGL

void RotateO(int position, int squareBlock, float &xpos, float &ypos){
	
	switch(position){
		case 0:
			switch (squareBlock) {
				case 1:
//					printf("case 0\n");
					xpos = xpos + w;
					ypos = ypos + w;
					break;
				case 2:
					break;
				case 3:
					xpos = xpos + w;
					ypos = ypos - w;
					break;
				case 4:
					xpos = xpos + 2*w;
					
					break;
					
				default:
					break;
			}
			break;
		case 1:
			switch (squareBlock) {
				case 1:
//					printf("case 1 square 1\n");
					xpos = xpos +w;
					ypos = ypos -w;
					break;
				case 2:
//					printf("case 1 square2\n");
					break;
				case 3:
//					printf("case 1 square3\n");
					xpos = xpos - w;
					ypos = ypos - w;
					break;
				case 4:
//					printf("case 1 square4\n");
					ypos = ypos -2*w;
					break;
					
				default:
					break;
			}
			break;
		case 2:
			switch (squareBlock) {
				case 1:
//					printf("case 2\n");
					xpos = xpos - w;
					ypos = ypos - w;
					
					break;
				case 2:
					break;
				case 3:
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 4:
					xpos = xpos -2*w;
					
					
					break;
					
				default:
					break;
			}
			break;
		case 3:
			switch (squareBlock) {
				case 1:
//					printf("case 3\n");
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 2:
					break;
				case 3:
					xpos = xpos + w;
					ypos = ypos + w;
					
					break;
				case 4:
					ypos = ypos + 2*w;
					break;
					
				default:
					break;
			}
			break;
			
	}
}

//---------------------------------------
// Rotate functin for the Z shape for OpenGL

void RotateZ(int position, int squareBlock, float &xpos, float &ypos){
	
	switch(position){
		case 0:
			switch (squareBlock) {
				case 1:
//					printf("case 0\n");
					ypos = ypos +2*w;
					break;
				case 2:
					break;
				case 3:
					xpos = xpos + w;
					ypos = ypos - w;
					break;
				case 4:
					xpos = xpos + w;
					ypos = ypos + w;
					
					break;
					
				default:
					break;
			}
			break;
		case 1:
			switch (squareBlock) {
				case 1:
//					printf("case 1 square 1\n");
					xpos = xpos +2*w;
					
					break;
				case 2:
//					printf("case 1 square2\n");
					break;
				case 3:
//					printf("case 1 square3\n");
					xpos = xpos - w;
					ypos = ypos - w;
					break;
				case 4:
//					printf("case 1 square4\n");
					xpos = xpos + w;
					ypos = ypos -w;
					break;
					
				default:
					break;
			}
			break;
		case 2:
			switch (squareBlock) {
				case 1:
//					printf("case 2\n");
					
					ypos = ypos - 2*w;
					
					break;
				case 2:
					break;
				case 3:
					xpos = xpos - w;
					ypos = ypos + w;
					break;
				case 4:
					xpos = xpos -w;
					ypos = ypos -w;
					
					
					break;
					
				default:
					break;
			}
			break;
		case 3:
			switch (squareBlock) {
				case 1:
//					printf("case 3\n");
					xpos = xpos - 2*w;
					
					break;
				case 2:
					break;
				case 3:
					xpos = xpos + w;
					ypos = ypos + w;
					
					break;
				case 4:
					xpos = xpos - w;
					ypos = ypos + w;
					break;
					
				default:
					break;
			}
			break;
			
	}
}



void Rotate(char s, int position, int squareBlock, float &xpos, float &ypos){
	switch(s){
		case 'i':
//			printf("This will need to rotate for an i shape %d %d \n",squareBlock, position );
			RotateI(position,squareBlock,xpos,ypos);
			break;
		case 'j':
//			printf("This will need to rotate for an j shape %d %d \n",squareBlock, position );
			RotateJ(position,squareBlock,xpos,ypos);
			break;
		case 'l':
//			printf("This will need to rotate for an l shape %d %d \n",squareBlock, position );
			RotateL(position,squareBlock,xpos,ypos);
			break;
		case 't':
//			printf("This will need to rotate for an t shape %d %d \n",squareBlock, position );
			RotateT(position,squareBlock,xpos,ypos);
			break;
		case 's':
//			printf("This will need to rotate for an s shape %d %d \n",squareBlock, position );
			RotateS(position,squareBlock,xpos,ypos);
			break;
		case 'o':
//			printf("This will need to rotate for an o shape %d %d \n",squareBlock, position );
			RotateO(position,squareBlock,xpos,ypos);
			break;
		case 'z':
//			printf("This will need to rotate for an z shape %d %d \n",squareBlock, position );
			RotateZ(position,squareBlock,xpos,ypos);
			break;
		default:
			break;
	}
}



//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

//	printf("I am calling the display method\n");
	for(int i = 0; i < xpos.size(); i++){
		draw_square(xpos[i], ypos[i], w, RedColor[i], GreenColor[i], BlueColor[i], currentRotation[i], squarePosition[i]);
	}
    
	drawGrid();
   glFlush();
}
void keyboard(unsigned char key, int x, int y){
	key = tolower(key);
	srand(time(NULL));
	float xvar = (w/2) + rand()%10;
	
	//int yvar = w/2 + rand()%23;
	float yvar = 17 + (w/2);
		//Initialize shape pieces
	// lowercase any uppercase
	if(key == 'i' || key == 'I'){
//		printf("I am drawing I\n");
		float Ri = 0.65;
		float Gi = 0.85;
		float Bi = 1;
		pieceCreated = true;
		lockedIn = false;
		
		// Shape I configuration
		/*
		 
		  ---- ---- ---- ----
	     |  1 |  x  |  3 |  4 |
		  ---- ---- ---- ----
		 
		 */

		//square #1
		shape.push_back('i');
		// randomize x position
		
		if(xvar+2*w > screenWidth - w){
			xvar = screenWidth - w*4.5;
		}
		
		xpos.push_back(xvar);
		ypos.push_back(yvar);
		RedColor.push_back(Ri);
		GreenColor.push_back(Gi);
		BlueColor.push_back(Bi);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(1);
		
		
		//square #2
		shape.push_back('i');
		xpos.push_back(xvar+w);
		ypos.push_back(yvar);
		RedColor.push_back(Ri);
		GreenColor.push_back(Gi);
		BlueColor.push_back(Bi);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(2);
		//square 3
		shape.push_back('i');
		xpos.push_back(xvar + 2*w);
		ypos.push_back(yvar);
		RedColor.push_back(Ri);
		GreenColor.push_back(Gi);
		BlueColor.push_back(Bi);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(3);
		//sqaure 4
		shape.push_back('i');
		xpos.push_back(xvar+3*w);
		ypos.push_back(yvar);
		RedColor.push_back(Ri);
		GreenColor.push_back(Gi);
		BlueColor.push_back(Bi);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(4);
		
		for(int i = 0; i < xpos.size(); i++){
			draw_square(xpos[i], ypos[i], w, RedColor[i], GreenColor[i], BlueColor[i], currentRotation[i], squarePosition[i]);
		}
		
		
		
	}
	else if(key == 'j' || key == 'J'){
//		printf("I am drawing J\n");
		float Rj=0, Gj=0, Bj=1;
		pieceCreated = true;
		lockedIn = false;
		
		// Shape J configuration
		/*
		 
		  ----
		 |  1 |
		  ---- ---- ----
		 |  x |  3 |  4 |
		  ---- ---- ----
		 
		 */

		//square #1
		shape.push_back('j');
		// randomize x position
		if(xvar+2*w > screenWidth - w){
			xvar = screenWidth - w*4.5;
		}
		
		xpos.push_back(xvar);
		ypos.push_back(yvar+w);
		RedColor.push_back(Rj);
		GreenColor.push_back(Gj);
		BlueColor.push_back(Bj);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(1);
		
		//square #2
		shape.push_back('j');
		xpos.push_back(xvar);
		ypos.push_back(yvar);
		RedColor.push_back(Rj);
		GreenColor.push_back(Gj);
		BlueColor.push_back(Bj);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(2);
		//square 3
		shape.push_back('j');
		xpos.push_back(xvar + w);
		ypos.push_back(yvar);
		RedColor.push_back(Rj);
		GreenColor.push_back(Gj);
		BlueColor.push_back(Bj);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(3);
		//sqaure 4
		shape.push_back('j');
		xpos.push_back(xvar+2*w);
		ypos.push_back(yvar);
		RedColor.push_back(Rj);
		GreenColor.push_back(Gj);
		BlueColor.push_back(Bj);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(4);
		
		for(int i = 0; i < xpos.size(); i++){
			draw_square(xpos[i], ypos[i], w, RedColor[i], GreenColor[i], BlueColor[i], currentRotation[i], squarePosition[i]);
		}
		

	}
	else if(key == 'l' || key == 'L'){
//		printf("I am drawing L\n");
		float Rl=1, Gl=0.65, Bl=0;
		pieceCreated = true;
		lockedIn = false;
		
		// Shape L configuration
		/*
					----
		           |  4 |
		  ---- ---- ----
		 |  1 |  2 |  x |
		  ---- ---- ----
		 
		 */

		//square #1
		shape.push_back('l');
		// randomize x position
		
		if(xvar+2*w > screenWidth - w){
			xvar = screenWidth - w*4.5;
		}
		
		xpos.push_back(xvar);
		ypos.push_back(yvar);
		RedColor.push_back(Rl);
		GreenColor.push_back(Gl);
		BlueColor.push_back(Bl);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(1);
		
		//square #2
		shape.push_back('l');
		xpos.push_back(xvar+w);
		ypos.push_back(yvar);
		RedColor.push_back(Rl);
		GreenColor.push_back(Gl);
		BlueColor.push_back(Bl);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(2);
		//square 3
		shape.push_back('l');
		xpos.push_back(xvar + 2*w);
		ypos.push_back(yvar);
		RedColor.push_back(Rl);
		GreenColor.push_back(Gl);
		BlueColor.push_back(Bl);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(3);
		//sqaure 4
		shape.push_back('l');
		xpos.push_back(xvar+2*w);
		ypos.push_back(yvar + w);
		RedColor.push_back(Rl);
		GreenColor.push_back(Gl);
		BlueColor.push_back(Bl);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(4);
		
		for(int i = 0; i < xpos.size(); i++){
			draw_square(xpos[i], ypos[i], w, RedColor[i], GreenColor[i], BlueColor[i], currentRotation[i], squarePosition[i]);
		}

	}
	else if(key == 'o' || key == 'O'){
//		printf("I am drawing O\n");
		float Ro=1, Go=1, Bo=0;
		pieceCreated = true;
		lockedIn = false;
		
		// Shape O configuration
		/*
		       ----	----
			  |	 1 |  4 |
			   ---- ----
		      |  x |  3 |
		       ---- ----
		 
		 */

		//square #1
		shape.push_back('o');
		// randomize x position
		
		if(xvar+2*w > screenWidth - w){
			xvar = screenWidth - w*4.5;
		}
		
		xpos.push_back(xvar+w);
		ypos.push_back(yvar+w);
		RedColor.push_back(Ro);
		GreenColor.push_back(Go);
		BlueColor.push_back(Bo);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(1);
		
		//square #2
		shape.push_back('o');
		xpos.push_back(xvar+w);
		ypos.push_back(yvar);
		RedColor.push_back(Ro);
		GreenColor.push_back(Go);
		BlueColor.push_back(Bo);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(2);
		//square 3
		shape.push_back('o');
		xpos.push_back(xvar + 2*w);
		ypos.push_back(yvar);
		RedColor.push_back(Ro);
		GreenColor.push_back(Go);
		BlueColor.push_back(Bo);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(3);
		//sqaure 4
		shape.push_back('o');
		xpos.push_back(xvar+2*w);
		ypos.push_back(yvar + w);
		RedColor.push_back(Ro);
		GreenColor.push_back(Go);
		BlueColor.push_back(Bo);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(4);
		
		for(int i = 0; i < xpos.size(); i++){
			draw_square(xpos[i], ypos[i], w, RedColor[i], GreenColor[i], BlueColor[i], currentRotation[i], squarePosition[i]);
		}

		

	}
	else if(key == 's' || key == 'S'){
//		printf("I am drawing S\n");
		float Rs=0, Gs=1, Bs=0;
		pieceCreated = true;
		lockedIn = false;
		
		// Shape S configuration
		/*
			        ---- ----
			       |  1 |  4 |
			   ---- ---- ----
			  |  2 |  x |
			   ---- ----
		 
		 */

		//square #1
		shape.push_back('s');
		// randomize x position
		
		if(xvar+2*w > screenWidth - w){
			xvar = screenWidth - w*4.5;
		}
		
		xpos.push_back(xvar+2*w);
		ypos.push_back(yvar+w);
		RedColor.push_back(Rs);
		GreenColor.push_back(Gs);
		BlueColor.push_back(Bs);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(1);
		
		//square #2
		shape.push_back('s');
		xpos.push_back(xvar+w);
		ypos.push_back(yvar);
		RedColor.push_back(Rs);
		GreenColor.push_back(Gs);
		BlueColor.push_back(Bs);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(2);
		//square 3
		shape.push_back('s');
		xpos.push_back(xvar + 2*w);
		ypos.push_back(yvar);
		RedColor.push_back(Rs);
		GreenColor.push_back(Gs);
		BlueColor.push_back(Bs);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(3);
		//sqaure 4
		shape.push_back('s');
		xpos.push_back(xvar+3*w);
		ypos.push_back(yvar + w);
		RedColor.push_back(Rs);
		GreenColor.push_back(Gs);
		BlueColor.push_back(Bs);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(4);
		
		for(int i = 0; i < xpos.size(); i++){
			draw_square(xpos[i], ypos[i], w, RedColor[i], GreenColor[i], BlueColor[i], currentRotation[i], squarePosition[i]);
		}

	}
	else if(key == 't' || key == 'T'){
//		printf("I am drawing T\n");
		float Rt=1, Gt=0, Bt=1;
		pieceCreated = true;
		lockedIn = false;
		
		// Shape T configuration
		/*
					----
				   |  1 |
			   ---- ---- ----
			  |  2 |  x |  4 |
			   ---- ---- ----
		 
		 */

		//square #1
		shape.push_back('t');
		// randomize x position
		
		if(xvar+2*w > screenWidth - w){
			xvar = screenWidth - w*4.5;
		}
		
		xpos.push_back(xvar+2*w);
		ypos.push_back(yvar+w);
		RedColor.push_back(Rt);
		GreenColor.push_back(Gt);
		BlueColor.push_back(Bt);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(1);
		
		//square #2
		shape.push_back('t');
		xpos.push_back(xvar+w);
		ypos.push_back(yvar);
		RedColor.push_back(Rt);
		GreenColor.push_back(Gt);
		BlueColor.push_back(Bt);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(2);
		//square 3
		shape.push_back('t');
		xpos.push_back(xvar + 2*w);
		ypos.push_back(yvar);
		RedColor.push_back(Rt);
		GreenColor.push_back(Gt);
		BlueColor.push_back(Bt);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(3);
		//sqaure 4
		shape.push_back('t');
		xpos.push_back(xvar+3*w);
		ypos.push_back(yvar);
		RedColor.push_back(Rt);
		GreenColor.push_back(Gt);
		BlueColor.push_back(Bt);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(4);
		
		for(int i = 0; i < xpos.size(); i++){
			draw_square(xpos[i], ypos[i], w, RedColor[i], GreenColor[i], BlueColor[i], currentRotation[i], squarePosition[i]);
		}


	}
	else if(key == 'z' || key == 'Z'){
//		printf("I am drawing Z\n");
		float Rz=1, Gz=0, Bz=0;
		pieceCreated = true;
		lockedIn = false;
		
		// Shape Z configuration
		/*
	      ---- ----
	     |  1 |  4 |
		  ---- ---- ----
			  |  x |  3 |
			   ---- ----
		 
		 */

		//square #1
		shape.push_back('z');
		// randomize x position
		
		if(xvar+w > screenWidth - w){
			xvar = screenWidth - w*3.5;
		}
		
		xpos.push_back(xvar);
		ypos.push_back(yvar+w);
		RedColor.push_back(Rz);
		GreenColor.push_back(Gz);
		BlueColor.push_back(Bz);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(1);
		
		//square #2
		shape.push_back('z');
		xpos.push_back(xvar+w);
		ypos.push_back(yvar);
		RedColor.push_back(Rz);
		GreenColor.push_back(Gz);
		BlueColor.push_back(Bz);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(2);
		//square 3
		shape.push_back('z');
		xpos.push_back(xvar + 2*w);
		ypos.push_back(yvar);
		RedColor.push_back(Rz);
		GreenColor.push_back(Gz);
		BlueColor.push_back(Bz);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(3);
		//sqaure 4
		shape.push_back('z');
		xpos.push_back(xvar+w);
		ypos.push_back(yvar + w);
		RedColor.push_back(Rz);
		GreenColor.push_back(Gz);
		BlueColor.push_back(Bz);
		//currentRotation the current rotated position this will increase to determine how the configuration of each square will be positioned at
		currentRotation.push_back(0);
		squarePosition.push_back(4);
		
		for(int i = 0; i < xpos.size(); i++){
			draw_square(xpos[i], ypos[i], w, RedColor[i], GreenColor[i], BlueColor[i], currentRotation[i], squarePosition[i]);
		}


	}
	else if( key == 32){
		lockedIn = true;
	}
	else {
		printf("Please select an appropriate command.\n");
	}
	
	glutPostRedisplay();
}

void special(int key, int x, int y){
	bool dontMoveLeft = false;
	bool dontMoveRight = false;
	bool dontMoveDown = false;
	bool dontRotate = false;
	for(int i = 1; i < 5; i++){
		if(xpos[xpos.size()-i ] == screenWidth-(w/2)){
			dontMoveRight = true;
			dontRotate = true;
		}
		if(xpos[xpos.size()-i] == w/2){
			dontMoveLeft = true;
			dontRotate = true;
		}
		if(ypos[ypos.size()-i] == w/2){
			dontMoveDown = true;
			dontRotate = true;
		}
		
	}
	
	if(pieceCreated){
		if(!lockedIn){
			switch(key){
				case GLUT_KEY_UP:
//					printf("Up arrow key pressed\n");
					
					
					if(!dontRotate){
						for(int i = 1; i < 5; i++){
							if(xpos[xpos.size()-i ] == screenWidth-(w/2)){
								dontMoveRight = true;
								dontRotate = true;
							}
							if(xpos[xpos.size()-i] == w/2){
								dontMoveLeft = true;
								dontRotate = true;
							}
							if(ypos[ypos.size()-i] == w/2){
								dontMoveDown = true;
								dontRotate = true;
							}
							currentRotation[currentRotation.size()-i] += 1;
//							printf("square block %d\n", squarePosition[squarePosition.size()-i]);
							if(currentRotation[currentRotation.size()-i] == 4){
								currentRotation[currentRotation.size()-i] = 0;
							}
							Rotate(shape[shape.size()-i],currentRotation[currentRotation.size()-i],squarePosition[squarePosition.size()-i],xpos[xpos.size()-i],ypos[ypos.size()-i]);
						}
					}
					break;
				case GLUT_KEY_DOWN:
//					printf("Down arrow key pressed\n");
					if(!dontMoveDown){
						for(int i = 1; i < 5 ; i++){
							
							ypos[ypos.size()-i] = ypos[ypos.size()-i] - w;
						}
					}
					break;
				case GLUT_KEY_LEFT:
//					printf("Left arrow key pressed\n");
					if(!dontMoveLeft){
						for(int i = 1; i < 5 ; i++){
							
							xpos[xpos.size()-i] = xpos[xpos.size()-i] - w;
						}
					}
					
					break;
				case GLUT_KEY_RIGHT:
//					printf("Right arrow key pressed\n");
					if(!dontMoveRight){
						for(int i = 1; i < 5 ; i++){
							
							xpos[xpos.size()-i] = xpos[xpos.size()-i] + w;
						}
					}
					break;
				default:
					break;
			}
		}
	}
	glutPostRedisplay();
}



//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitWindowSize(500, 1000);
   glutInitWindowPosition(250, 250);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutCreateWindow("homework2");
   init();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   
   
   
   glutMainLoop();
   return 0;
}
