#include<iostream>
#include<math.h>
#include<GL/glut.h>
#define w 640
#define h 480
#define ROUND(X)((int)X+0.5)
using namespace std;

void init(void);
void draw();
int dda_line(float,float,float,float);



void init(void)
{
	glClearColor(1.0,1.0,1.0,0);              //clear buffer
    glColor3f(0.0,0.0,0.0);                      //set background color
    glPointSize(4.0);                            
   gluOrtho2D(-w/2 , w/2 , -h/2 , h/2);             //dividing screen into four quadurants
	//gluOrtho2D(0,640,0,480);
}



int dda_line(float x1,float y1,float x2,float y2)
{
	float dx,dy,steps,X,Y,xinc,yinc;
	int i=0;
	
	dx=(x2-x1);   // x1=6 y1=9   x2=10 y2=12   dx=4  dy=3
	dy=(y2-y1);
	
	if(abs(dx)>=abs(dy))
	{
		steps=abs(dx);       //steps=4
	}
	
	else
	{
		steps=abs(dy);
	}

	

	xinc=dx/steps;  //xinc=4/4=1     xinc=1+old x value
	yinc=dy/steps;   //yinc=3/4=0.7   yinc=0.7+y old value
	
	//assign Intial values(starting coordinates)
	X=x1;
	Y=y1;

	i=1;
	

//1:  1 <=4
	
	
	while(i<=steps)
	{
		
		
		glBegin(GL_POINTS);
		glVertex2i(ROUND(X),ROUND(Y));
		glEnd();
		
		//changing value of xnew & ynew
		X=X+xinc;   //xnew=6+1=7
		Y=Y+yinc;   //ynew=9+0.7=9.7
		glFlush();
	
		i++;
		
	}
	return 0;

}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	 glVertex2d(-w/2,0);
	 glVertex2d(w/2,0);
	 glVertex2d(0,-h/2);
	 glVertex2d(0,h/2);

	glEnd();
	
	dda_line(10,50,100,150);
	
	//
	
	
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("MY SHAPE");
	glutDisplayFunc(draw);
	init();
	glutMainLoop();
	
	return(0);
}

