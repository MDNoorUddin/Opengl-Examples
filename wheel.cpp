#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <GL/glut.h>

#define pi (2*acos(0.0))
double cameraHeight=0;

double cameraAngle;
int drawgrid;
int drawaxes;
double angle;
double ang=0;

double map_angle;double Block_size=40;double Block_distance=38,size_cube=38;int slices_spehere=30, stacks_spehere=30;
int segments_cylinder=24;double temp=0;double move_pos=2;double ar=0;


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
			glVertex3f( 200,0,0);
			glVertex3f(-200,0,0);

			glVertex3f(0,-200,0);
			glVertex3f(0, 200,0);

			//glVertex3f(0,0, 200);
			//glVertex3f(0,0,-200);
		}glEnd();
	}
}
void drawSquare(double a)
{

	glBegin(GL_QUADS);{
		glVertex3f( a, a,0);
		glVertex3f( a,-a,0);
		glVertex3f(-a,-a,0);
		glVertex3f(-a, a,0);
	}glEnd();
}

void drawCircle(double radius,int segments)
{
    int i;
    struct point points[100];
    //glColor3f(1.0,0.0,1.0);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points
    for(i=0;i<segments;i++)
    {
        glBegin(GL_LINES);
        {
			glVertex3f(points[i].y/2,points[i].x/2,0);
			glVertex3f(points[i+1].y/2,points[i+1].x/2,0);
        }
        glEnd();
    }
    glColor3f(0,1,0);
    glBegin(GL_LINES);
        {
			glVertex3f(points[0].y/2,points[0].x/2,0);
			glVertex3f(points[19].y/2,points[19].x/2,0);
        }
        glEnd();
        glBegin(GL_LINES);
        {
			glVertex3f(points[13].y/2,points[13].x/2,0);
			glVertex3f(points[34].y/2,points[34].x/2,0);
        }
        glEnd();
}

void drawSphere( int radius ){

	glScalef(0.5f, 0.4f, 2.0f);
    glutWireSphere(radius,10,10);

}

void drawTriangle()
{
	glBegin( GL_TRIANGLES );
	{
        glVertex3f(10,0,0);
        glVertex3f(-10,0,0);
        glVertex3f(0,0,13);
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
      gluLookAt(160*cos(cameraAngle), 160*sin(cameraAngle),160*sin(cameraHeight),		0,0,0,		0,0,1);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects
	drawAxes();
	double tr=-10;
	glRotatef(ang,0,0,1);
    glTranslatef(ar,0,0);
    for(int i = 1; i <= 2000; i++,tr+=.010){
    //if((i/40)%2==0)glColor3f(0,1,0);
    //else glColor3f(1,1,0);
    //if(i%3==2)glColor3f(0,0,1);
    glColor3f(.7,0,0);
    glPushMatrix();
     glRotatef(90,1,0,0);
     glTranslatef(0,0,tr);
     glTranslatef(0,50,0);
     drawCircle(100,40);
    glPopMatrix();
    }
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

		case GLUT_KEY_RIGHT:
			//cameraAngle += 0.03;
			cameraAngle+=.01;
			//if(cameraHeight==50)
                //cameraHeight=5;
			break;
		case GLUT_KEY_LEFT:
			cameraAngle-=.01;

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

void keyboardListener(unsigned char key, int x,int y){
	switch(key){
        case 'w':
            ar-=10;
            break;

        case 's':
            ar+=10;
            break;
        case 'd':
            ang+=10;
            break;
        case 'a':
            ang-=10;
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
	gluPerspective(80,	1,	1,	1000.0);
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
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	//glutMouseFunc(mouseListener);


	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
