//
//  Homework1.cpp
//
//
//  Created by Anthony Lopez-Guerra on 1/27/21.
//

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


//Borrowed Random code from Dr. Gauch source code.
//---------------------------------------
// Calculate random value between [min..max]
//---------------------------------------
float myrand(float min, float max)
{
   return rand() * (max - min) / RAND_MAX + min;
}

//---------------------------------------
// Generate I shape
//---------------------------------------
void generateIShape(float x, float y, float w){

	// The variable d is the offset distance from one vertex position to the next
	float d = 0.555;
	// the variable set of {x1,..., x4} can be utilized to represent each block relative to what I am calling the base design as the I shape.

	float x1 = x;
	float x2 = x1 + d;
	float x3 = x2 + d;
	float x4 = x3 + d;

	// the variable set of {y1,...,y4} can be utilized to represent each block relative to what I am calling the base design as the I shape.

	float y1 = y;

	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(50);
//	glBegin(GL_LINE_LOOP);
//		glColor3f(0.0,0.8,0.8);
//		glVertex2f(((x1-0.005)-(w/2)), ((y1-0.005)-(w/2)));
//		glVertex2f(((x1+0.005)+(w/2)), ((y1-0.005)-(w/2)));
//		glVertex2f(((x1+0.005)+(w/2)), ((y1+0.005)+(w/2)));
//		glVertex2f(((x1-0.005)-(w/2)), ((y1+0.005)+(w/2)));
//	glEnd();

	//This code is one way of creating the border by generating another square that is bigger.
	//block1 I played around with the offset value of 0.030 to give the shape some thickness but not so much that it overwhelemed the design.
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.8,0.8);
		glVertex2f(((x1-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x1+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x1+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x1-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(((x1)-(w/2)), (y1-(w/2)));
		glVertex2f(((x1)+(w/2)), (y1-(w/2)));
		glVertex2f(((x1)+(w/2)), (y1+(w/2)));
		glVertex2f(((x1)-(w/2)), (y1+(w/2)));
	glEnd();

	//block2
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.8,0.8);
		glVertex2f(((x2-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(((x2)-(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1+(w/2)));
		glVertex2f(((x2)-(w/2)), (y1+(w/2)));
	glEnd();
	//block3
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.8,0.8);
		glVertex2f(((x3-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(((x3)-(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1+(w/2)));
		glVertex2f(((x3)-(w/2)), (y1+(w/2)));
	glEnd();

	//block4
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.8,0.8);
		glVertex2f(((x4-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x4+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x4+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x4-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(((x4)-(w/2)), (y1-(w/2)));
		glVertex2f(((x4)+(w/2)), (y1-(w/2)));
		glVertex2f(((x4)+(w/2)), (y1+(w/2)));
		glVertex2f(((x4)-(w/2)), (y1+(w/2)));
	glEnd();

}

void getnerateLShape(float x, float y, float w){
	// The variable d is the offset distance from one vertex position to the next
	float d = 0.555;

	// the variable set of {x1,..., x4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float x1 = x;
	float x2 = x1 + d;
	float x3 = x2 + d;

	// the variable set of {y1,...,y4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float y1 = y;
	float y2 = y1+d;

	//This code is one way of creating the border by generating another square that is bigger.
	//block1 I played around with the offset value of 0.030 to give the shape some thickness but not so much that it overwhelemed the design.
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.5,0.0);
		glVertex2f(((x1-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x1+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x1+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x1-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,0.5,0.0);
		glVertex2f(((x1)-(w/2)), (y1-(w/2)));
		glVertex2f(((x1)+(w/2)), (y1-(w/2)));
		glVertex2f(((x1)+(w/2)), (y1+(w/2)));
		glVertex2f(((x1)-(w/2)), (y1+(w/2)));
	glEnd();

	//block2
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.5,0.0);
		glVertex2f(((x2-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,0.5,0.0);
		glVertex2f(((x2)-(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1+(w/2)));
		glVertex2f(((x2)-(w/2)), (y1+(w/2)));
	glEnd();
	//block3
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.5,0.0);
		glVertex2f(((x3-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,0.5,0.0);
		glVertex2f(((x3)-(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1+(w/2)));
		glVertex2f(((x3)-(w/2)), (y1+(w/2)));
	glEnd();

	//block4
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.5,0.0);
		glVertex2f(((x3-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2f(((x3)-(w/2)), (y2-(w/2)));
		glVertex2f(((x3)+(w/2)), (y2-(w/2)));
		glVertex2f(((x3)+(w/2)), (y2+(w/2)));
		glVertex2f(((x3)-(w/2)), (y2+(w/2)));
	glEnd();

}

void generateJShape(float x,float y, float w){
	// The variable d is the offset distance from one vertex position to the next
	float d = 0.555;

	// the variable set of {x1,..., x4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float x1 = x;
	float x2 = x1 + d;
	float x3 = x2 + d;
	float x4 = x3 + d;

	// the variable set of {y1,...,y4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float y1 = y;
	float y2 = y1+d;

	//This code is one way of creating the border by generating another square that is bigger.
	//block1 I played around with the offset value of 0.030 to give the shape some thickness but not so much that it overwhelemed the design.
	//block1
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,.8);
		glVertex2f(((x2-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(((x2)-(w/2)), (y2-(w/2)));
		glVertex2f(((x2)+(w/2)), (y2-(w/2)));
		glVertex2f(((x2)+(w/2)), (y2+(w/2)));
		glVertex2f(((x2)-(w/2)), (y2+(w/2)));
	glEnd();

	//block2
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.8);
		glVertex2f(((x2-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(((x2)-(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1+(w/2)));
		glVertex2f(((x2)-(w/2)), (y1+(w/2)));
	glEnd();
	//block3
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.8);
		glVertex2f(((x3-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(((x3)-(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1+(w/2)));
		glVertex2f(((x3)-(w/2)), (y1+(w/2)));
	glEnd();

	//block4
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.8);
		glVertex2f(((x4-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x4+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x4+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x4-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(((x4)-(w/2)), (y1-(w/2)));
		glVertex2f(((x4)+(w/2)), (y1-(w/2)));
		glVertex2f(((x4)+(w/2)), (y1+(w/2)));
		glVertex2f(((x4)-(w/2)), (y1+(w/2)));
	glEnd();
}

void generateOShape(float x,float y, float w){

	// The variable d is the offset distance from one vertex position to the next
	float d = 0.555;

	// the variable set of {x1,..., x4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float x1 = x;
	float x2 = x1 + d;
	float x3 = x2 + d;

	// the variable set of {y1,...,y4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float y1 = y;
	float y2 = y1+d;

	//This code is one way of creating the border by generating another square that is bigger.
	//block1 I played around with the offset value of 0.030 to give the shape some thickness but not so much that it overwhelemed the design.
	//block1
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.8,0.0);
		glVertex2f(((x2-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(((x2)-(w/2)), (y2-(w/2)));
		glVertex2f(((x2)+(w/2)), (y2-(w/2)));
		glVertex2f(((x2)+(w/2)), (y2+(w/2)));
		glVertex2f(((x2)-(w/2)), (y2+(w/2)));
	glEnd();

	//block2
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.8,0.0);
		glVertex2f(((x2-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(((x2)-(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1+(w/2)));
		glVertex2f(((x2)-(w/2)), (y1+(w/2)));
	glEnd();
	//block3
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.8,0.0);
		glVertex2f(((x3-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(((x3)-(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1+(w/2)));
		glVertex2f(((x3)-(w/2)), (y1+(w/2)));
	glEnd();

	//block4
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.8,0.0);
		glVertex2f(((x3-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(((x3)-(w/2)), (y2-(w/2)));
		glVertex2f(((x3)+(w/2)), (y2-(w/2)));
		glVertex2f(((x3)+(w/2)), (y2+(w/2)));
		glVertex2f(((x3)-(w/2)), (y2+(w/2)));
	glEnd();

}

void generateSShape(float x,float y, float w){

	// The variable d is the offset distance from one vertex position to the next
	float d = 0.555;

	// the variable set of {x1,..., x4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float x1 = x;
	float x2 = x1 + d;
	float x3 = x2 + d;
	float x4 = x3 + d;

	// the variable set of {y1,...,y4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float y1 = y;
	float y2 = y1+d;

	//This code is one way of creating the border by generating another square that is bigger.
	//block1 I played around with the offset value of 0.030 to give the shape some thickness but not so much that it overwhelemed the design.
	//block1
	glBegin(GL_POLYGON);
		glColor3f(0.196078, 0.5, 0.196078);
		glVertex2f(((x3-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f( 0,1,0);
		glVertex2f(((x3)-(w/2)), (y2-(w/2)));
		glVertex2f(((x3)+(w/2)), (y2-(w/2)));
		glVertex2f(((x3)+(w/2)), (y2+(w/2)));
		glVertex2f(((x3)-(w/2)), (y2+(w/2)));
	glEnd();

	//block2
	glBegin(GL_POLYGON);
		glColor3f(0.196078, 0.5, 0.196078);
		glVertex2f(((x2-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0,1,0);
		glVertex2f(((x2)-(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1+(w/2)));
		glVertex2f(((x2)-(w/2)), (y1+(w/2)));
	glEnd();
	//block3
	glBegin(GL_POLYGON);
		glColor3f(0.196078, 0.5, 0.196078);
		glVertex2f(((x3-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0,1,0);
		glVertex2f(((x3)-(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1+(w/2)));
		glVertex2f(((x3)-(w/2)), (y1+(w/2)));
	glEnd();

	//block4
	glBegin(GL_POLYGON);
		glColor3f(0.196078, 0.5, 0.196078);
		glVertex2f(((x4-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x4+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x4+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x4-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0,1,0);
		glVertex2f(((x4)-(w/2)), (y2-(w/2)));
		glVertex2f(((x4)+(w/2)), (y2-(w/2)));
		glVertex2f(((x4)+(w/2)), (y2+(w/2)));
		glVertex2f(((x4)-(w/2)), (y2+(w/2)));
	glEnd();


}

void generateTShape(float x,float y, float w){

	// The variable d is the offset distance from one vertex position to the next
	float d = 0.555;

	// the variable set of {x1,..., x4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float x1 = x;
	float x2 = x1 + d;
	float x3 = x2 + d;

	// the variable set of {y1,...,y4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float y1 = y;
	float y2 = y1+d;

	//This code is one way of creating the border by generating another square that is bigger.
	//block1 I played around with the offset value of 0.030 to give the shape some thickness but not so much that it overwhelemed the design.
	//block1
	glBegin(GL_POLYGON);
		glColor3f(0.8,0,0.8);
		glVertex2f(((x1-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x1+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x1+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x1-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,0,1);
		glVertex2f(((x1)-(w/2)), (y1-(w/2)));
		glVertex2f(((x1)+(w/2)), (y1-(w/2)));
		glVertex2f(((x1)+(w/2)), (y1+(w/2)));
		glVertex2f(((x1)-(w/2)), (y1+(w/2)));
	glEnd();

	//block2
	glBegin(GL_POLYGON);
		glColor3f(0.8,0,0.8);
		glVertex2f(((x2-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,0,1);
		glVertex2f(((x2)-(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1+(w/2)));
		glVertex2f(((x2)-(w/2)), (y1+(w/2)));
	glEnd();
	//block3
	glBegin(GL_POLYGON);
		glColor3f(0.8,0,0.8);
		glVertex2f(((x3-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,0,1);
		glVertex2f(((x3)-(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1+(w/2)));
		glVertex2f(((x3)-(w/2)), (y1+(w/2)));
	glEnd();

	//block4
	glBegin(GL_POLYGON);
		glColor3f(0.8,0,0.8);
		glVertex2f(((x2-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,0,1);
		glVertex2f(((x2)-(w/2)), (y2-(w/2)));
		glVertex2f(((x2)+(w/2)), (y2-(w/2)));
		glVertex2f(((x2)+(w/2)), (y2+(w/2)));
		glVertex2f(((x2)-(w/2)), (y2+(w/2)));
	glEnd();


}

void generateZShape(float x,float y, float w){

	// The variable d is the offset distance from one vertex position to the next
	float d = 0.555;

	// the variable set of {x1,..., x4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float x1 = x;
	float x2 = x1 + d;
	float x3 = x2 + d;

	// the variable set of {y1,...,y4} can be utilized to represent each block relative to what I am calling the base design as the I shape.
	float y1 = y;
	float y2 = y1+d;

	//This code is one way of creating the border by generating another square that is bigger.
	//block1 I played around with the offset value of 0.030 to give the shape some thickness but not so much that it overwhelemed the design.

	//block1
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.0,0.0);
		glVertex2f(((x1-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x1+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x1+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x1-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(((x1)-(w/2)), (y2-(w/2)));
		glVertex2f(((x1)+(w/2)), (y2-(w/2)));
		glVertex2f(((x1)+(w/2)), (y2+(w/2)));
		glVertex2f(((x1)-(w/2)), (y2+(w/2)));
	glEnd();

	//block2
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.0,0.0);
		glVertex2f(((x2-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(((x2)-(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1-(w/2)));
		glVertex2f(((x2)+(w/2)), (y1+(w/2)));
		glVertex2f(((x2)-(w/2)), (y1+(w/2)));
	glEnd();
	//block3
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.0,0.0);
		glVertex2f(((x3-0.030)-(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1-0.030)-(w/2)));
		glVertex2f(((x3+0.030)+(w/2)), ((y1+0.030)+(w/2)));
		glVertex2f(((x3-0.030)-(w/2)), ((y1+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(((x3)-(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1-(w/2)));
		glVertex2f(((x3)+(w/2)), (y1+(w/2)));
		glVertex2f(((x3)-(w/2)), (y1+(w/2)));
	glEnd();

	//block4
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.0,0.0);
		glVertex2f(((x2-0.030)-(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y2-0.030)-(w/2)));
		glVertex2f(((x2+0.030)+(w/2)), ((y2+0.030)+(w/2)));
		glVertex2f(((x2-0.030)-(w/2)), ((y2+0.030)+(w/2)));
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(((x2)-(w/2)), (y2-(w/2)));
		glVertex2f(((x2)+(w/2)), (y2-(w/2)));
		glVertex2f(((x2)+(w/2)), (y2+(w/2)));
		glVertex2f(((x2)-(w/2)), (y2+(w/2)));
	glEnd();

}



//---------------------------------------
// Init function for OpenGL Homework 1
//---------------------------------------
void init(){

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0,5.0,-5.0,5.0,-5.0,5.0);

}

//---------------------------------------
// Display callback for OpenGL Homework 1
//---------------------------------------
void display(){

	glClear(GL_COLOR_BUFFER_BIT);

	// the w is the wariable I will be using as a constant throughout the application. w is the width.
	float w = 0.5;

	// an x and y variable has to be instantiated for each different shape so that they each would get their own random values through the random funtion. this would allow the vertex positions to be random for each shape.
	float xI = myrand(0,3);
	float yI = myrand(0,3);
	float xJ = myrand(0,3);
	float yJ = myrand(0,3);
	float xL = myrand(0,3);
	float yL = myrand(0,3);
	float xO = myrand(0,3);
	float yO = myrand(0,3);
	float xS = myrand(0,3);
	float yS = myrand(0,3);
	float xT = myrand(0,3);
	float yT = myrand(0,3);
	float xZ = myrand(0,3);
	float yZ = myrand(0,3);

	//this is the method calls to generate each shape. the paramenters are the random variables for the x,y
	// generateIShape(xI,yI,w);
	// generateJShape(xJ,yJ,w);
	// getnerateLShape(xL,yL,w);
	// generateOShape(xO,yO,w);
	// generateSShape(xS,yS,w);
	generateTShape(xT,yT,w);
	// generateZShape(xZ,yZ,w);

	glFlush();
}



//---------------------------------------
// Main program for OpenGL Homework 1
//---------------------------------------
int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(250, 250);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutCreateWindow("Homework1");
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}
