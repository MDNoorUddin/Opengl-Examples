#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <GL/glut.h>

#define pi (2*acos(0.0))

double cameraHeight=10;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;

double map_angle;
double Block_size=40;
double Block_distance=38,size_cube=38;
int slices_spehere=30, stacks_spehere=30;
int segments_cylinder=24;
double temp=0;
double move_pos=2;
double ar=0;
int left=1,fast=0;


struct point
{
	double x,y,z;
};

point l,u,r,pos;







void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}


void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	gluLookAt(60*cos(cameraAngle), 60*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(0,0,200,	0,0,0,	0,1,0);
	//gluLookAt(pos.x, pos.y, pos.z,     pos.x + l.x,pos.y + l.y, pos.z + l.z,     u.x, u.y, u.z);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add object
    //drawAxes();
    glPushMatrix();

    glRotatef(ar,0,0,1);
	glPushMatrix();
	glColor3f(1,0,.6);
	glRotatef(90,0,0,1);
	glScalef(2,2,.8);
   glutSolidSphere(10,20,30);             /** body*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,30);
	glColor3f(1,0,.6);
	glRotatef(90,0,0,1);
	glScalef(.2,.2,3);
    glutSolidSphere(10,20,30);             /** body*/
	glPopMatrix();

	glPushMatrix();{
    glTranslatef(17,17,0);
    glRotatef(45,0,0,1);
    glColor3f(.7,.5,0);
    glBegin(GL_POLYGON);
    {
        glVertex3f(5,0,0);
        glVertex3f(-5,0,0);
        glVertex3f(-5,5,0);
        glVertex3f(5,5,0);
    }glEnd();


    glBegin(GL_POLYGON);
    {
        glVertex3f(5,0,0);
        glVertex3f(-5,0,0);
        glVertex3f(-5,5,0);
        glVertex3f(5,5,0);
    }glEnd();

	}glPopMatrix();


	glPushMatrix();{
    glTranslatef(-24,0,0);
    //glRotatef(135,0,0,1);
    glColor3f(.7,.5,0);
    glBegin(GL_POLYGON);
    {
        glVertex3f(5,0,0);
        glVertex3f(-5,0,0);
        glVertex3f(-5,5,0);
        glVertex3f(5,5,0);
    }glEnd();

	}glPopMatrix();

	glPushMatrix();{
    glTranslatef(-77,0,0);
    //glRotatef(45,0,0,1);
    glColor3f(.7,.5,0);
    glBegin(GL_POLYGON);
    {
        glVertex3f(50,8,0);
        glVertex3f(0,8,0);
        glVertex3f(0,-10,0);
        glVertex3f(55,-10,0);
    }glEnd();

	}glPopMatrix();

	glPushMatrix();{
    glTranslatef(17,17,0);
    glRotatef(45,0,0,1);
    glColor3f(.7,.5,0);
    glBegin(GL_POLYGON);
    {
        glVertex3f(50,8,0);
        glVertex3f(0,8,0);
        glVertex3f(0,-10,0);
        glVertex3f(55,-10,0);
    }glEnd();

	}glPopMatrix();

	glPushMatrix();{
    glTranslatef(17,-17,0);
    glRotatef(315,0,0,1);
    glColor3f(.7,.5,0);
    glBegin(GL_POLYGON);
    {
        glVertex3f(50,8,0);
        glVertex3f(0,8,0);
        glVertex3f(0,-10,0);
        glVertex3f(55,-10,0);
    }glEnd();

	}glPopMatrix();

	glPushMatrix();{
    glTranslatef(17,-17,0);
    glRotatef(315,0,0,1);
    glColor3f(.7,.5,0);
    glBegin(GL_POLYGON);
    {
        glVertex3f(5,0,0);
        glVertex3f(-5,0,0);
        glVertex3f(-5,5,0);
        glVertex3f(5,5,0);
    }glEnd();

	}glPopMatrix();
    if(left==1)
	{
       if(fast==1)ar+=2;
	    else ar+=.5;
	}
	else
    {
        if(fast==1)ar-=2;
	    else ar-=.5;
    }
	glPopMatrix();

	glutSwapBuffers();
}


void animate(){
	angle+=0.05;
	//codes for any changes in Models, Camera
	glutPostRedisplay();
}
void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;

	u.x=0;
    u.y=0;
    u.z=1;


    r.x=-1/sqrt(2);
    r.y=1/sqrt(2);
    r.z=0;

    l.x=-1/sqrt(2) ;
    l.y=-1/sqrt(2) ;
    l.z=0;

    pos.x=100;
    pos.y=100;
    pos.z=0;


	map_angle=90;

	//clear the screen
	glClearColor(0,0,0,0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}
void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			//cameraHeight -= 3.0;
			cameraHeight-=10;

			break;
		case GLUT_KEY_UP:		// up arrow key
			//cameraHeight += 3.0;
			cameraHeight+=10;
			break;

		case GLUT_KEY_RIGHT:
			//cameraAngle += 0.03;
			cameraAngle+=.5;
			break;
		case GLUT_KEY_LEFT:
			//cameraAngle -= 0.03;
			cameraAngle-=.05;

			break;

		case GLUT_KEY_PAGE_UP:
		    pos.x+=u.x*move_pos;
			pos.y+=u.y*move_pos;
			pos.z+=u.z*move_pos;
			break;
		case GLUT_KEY_PAGE_DOWN:
            pos.x-=u.x*move_pos;
			pos.y-=u.y*move_pos;
			pos.z-=u.z*move_pos;
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
		    if(Block_size>0)
            {
                Block_size-=5;
                temp+=5;
            }
			break;
		case GLUT_KEY_END:
            if(Block_size<size_cube)
            {
                Block_size+=5;
                temp-=5;
            }
			break;
        case GLUT_KEY_F1:
            left=1;
            break;
        case GLUT_KEY_F2:
            left=0;
            break;
        case GLUT_KEY_F3:
            fast=1;
            break;
        case GLUT_KEY_F4:
            fast=0;
            break;
		default:
			break;
	}
}


int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

//	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	//glutMouseFunc(mouseListener);


	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
