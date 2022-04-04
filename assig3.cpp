#include <GL/glut.h>
#include<math.h>
#include<iostream>
#define w 640
#define h 480
using namespace std;
int x, y, r;
void MyInit()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1.0);
glPointSize(4.0);
gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}
void Bresenham(int x0, int y0, int r)
{
int d, x, y;
x = 0;
y = r;
d = 3 - 2 * r;
do {
//use of symmetry property of circle
glBegin(GL_POINTS);
glVertex2i(x, y);
glVertex2i(y, x);
glVertex2i(y, -x);
glVertex2i(x, -y);
glVertex2i(-x, -y);
glVertex2i(-y, -x);
glVertex2i(-y, x);
glVertex2i(-x, y);
glEnd();
if (d < 0)
{
d += 4 * x + 6; //x++ y
}
else {
d += 4 * (x - y) + 10; //x++ y--
y--;
}
x++;
} while (x < y);
}
void display() {
glClearColor(1.0, 1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2i(-500, 0);
glVertex2i(500, 0);
glVertex2i(0, -500);
glVertex2i(0, 500);
glEnd();
Bresenham(x, y, r);
Bresenham(x + r * x, y, r);
glFlush();
}
int main(int argc, char** argv) {
cout << "Please enter the dot coordinates and radius:" <<endl;
cin>> x >> y >> r;
glutInit(&argc, argv); //Initialize glut
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//Set the mode of the window-depth buffer, single buffer, color model
glutInitWindowPosition(800, 600); //Set the position of the window
glutInitWindowSize(100, 100); //Set the size of the window
glutCreateWindow("Bresenham Circle"); //Create window and assign title
MyInit();
glutDisplayFunc(display);//Call display to transfer the drawing to the window. The prototype
//of this function is glutDisplayFunc(void)
glutMainLoop(); //Enter the loop and wait
return 0;
}
