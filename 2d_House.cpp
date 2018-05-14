#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>

using namespace std;
#define pi (2*acos(0.0))
double cameraHeight=30;

double cameraAngle=0;
int drawgrid;
int drawaxes;
double angle;
double anglee=0;
double ang=45;
double fixed=0;
double a=80;
int y=-80;
double angleRotate=0.0;

//5 means axis rotate false

//10 means axis rotate true

double map_angle;double Block_size=40;double Block_distance=38,size_cube=38;int slices_spehere=30, stacks_spehere=30;
int segments_cylinder=24;double temp=0;double move_pos=2;double ar=0,ay=0;


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
			glVertex3f( 1000,0,0);
			glVertex3f(-1000,0,0);

			glVertex3f(0,-1000,0);
			glVertex3f(0, 1000,0);

			glVertex3f(0,0, 200);
			glVertex3f(0,0,-200);
		}glEnd();
	}
}
void drawSquare(double a)
{

	glBegin(GL_LINES);{
		glVertex3f( 0, 0,0);
		glVertex3f( -100,0,0);

		glVertex3f( 0, 0,0);
		glVertex3f( 0,-170,0);


        glVertex3f( -100, 0,0);
		glVertex3f( -100,-170,0);

		glVertex3f( 0, -170,0);
		glVertex3f( -100,-170,0);

		//glVertex3f( -250, 0,0);
		//glVertex3f( -50,-250,0);

		//glVertex3f( 0, -250,0);
		//glVertex3f( -50,-250,0);


	}glEnd();
}

void drawTriangle()
{
	glBegin( GL_TRIANGLES );
	{
        glVertex3f(a+20,0,0);
        glVertex3f(-a-20,0,0);
        glVertex3f(0,0,50);
	}
	glEnd();
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
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(0,0,200,	0,0,0,	0,1,0);
	//gluLookAt(pos.x, pos.y, pos.z,     pos.x + l.x,pos.y + l.y, pos.z + l.z,     u.x, u.y, u.z);
    gluLookAt(205*cos(1.5),205*sin(1.5),0,		0,0,0,		0,0,1);
    cout<<cameraHeight<<endl;

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects
	//drawAxes();
glPushMatrix();
  //glTranslatef(-120,0,0);
	glPushMatrix();
    glColor3f(1,.7,1);
    glTranslatef(-60,0,-50);
    glRotatef(90,0,1,0);

	glRotatef(90,1,0,0);
     glBegin(GL_LINES);{
		glVertex3f( 0, 0,0);
		glVertex3f( -30,0,0);

		glVertex3f( 0, 0,0);
		glVertex3f( 0,-30,0);   /** window left*/

		glVertex3f( -30, 0,0);
		glVertex3f( -30,-30,0);

		glVertex3f( 0, -30,0);
		glVertex3f( -30,-30,0);

	}glEnd();
 glPopMatrix();
	glPushMatrix();
    glColor3f(1,.7,1);
    glTranslatef(70,0,-50);
    glRotatef(90,0,1,0);

	glRotatef(90,1,0,0);
     glBegin(GL_LINES);{
		glVertex3f( 0, 0,0);
		glVertex3f( -30,0,0);

		glVertex3f( 0, 0,0);
		glVertex3f( 0,-30,0);   /** window right*/

		glVertex3f( -30, 0,0);
		glVertex3f( -30,-30,0);

		glVertex3f( 0, -30,0);
		glVertex3f( -30,-30,0);

	}glEnd();

    glPopMatrix();

    glPushMatrix();
    glColor3f(1,.7,1);
    glTranslatef(0,0,-80);
    glRotatef(90,0,1,0);

	glRotatef(90,1,0,0);
     glBegin(GL_LINES);{
		glVertex3f( 0, 0,0);
		glVertex3f( -60,0,0);

		glVertex3f( 0, 0,0);
		glVertex3f( 0,-30,0);   /** door*/

		glVertex3f( -60, 0,0);
		glVertex3f( -60,-30,0);

		glVertex3f( 0, -30,0);
		glVertex3f( -60,-30,0);

	}glEnd();
 glPopMatrix();

	glColor3f(.5,.5,.5);
	glPushMatrix();
	glTranslatef(0,0,20);
	drawTriangle();
	glPopMatrix();
	glColor3f(.2,.6,.4);
    glPushMatrix();
    glTranslatef(80,0,-80);
    glRotatef(90,0,1,0);

	glRotatef(90,1,0,0);       /**       main base*/

    drawSquare(a);
    glPopMatrix();

  glPopMatrix();



   glPushMatrix();
   glTranslatef(ar,0,0);

  glPopMatrix();

	glutSwapBuffers();
}


void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			//cameraHeight -= 3.0;
			cameraHeight-=50;
			break;
		case GLUT_KEY_UP:		// up arrow key
		    cameraHeight+=50;
			break;
        case GLUT_KEY_F1:
            ar-=10;
            break;

        case GLUT_KEY_F2:
            ar+=10;
            break;
        case GLUT_KEY_F3:
            ang+=10;
            break;
        case GLUT_KEY_F4:
            ang-=10;
        break;
		case GLUT_KEY_RIGHT:
			//cameraAngle += 0.03;
			cameraAngle+=.5;
			//if(cameraHeight==50)
                //cameraHeight=5;
			break;
		case GLUT_KEY_LEFT:
			cameraAngle-=.5;

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
		default:
			break;
	}
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
	gluPerspective(100,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
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
	glutIdleFunc(animate);
//	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);		//what you want to do in the idle time (when no drawing is occuring)

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
