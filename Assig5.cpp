#include<iostream>
#include <GL/glut.h>
#include<string.h>
#include<math.h>
using namespace std;
double xmin, ymin, xmax, ymax, x1, yy1, x2, y2;
const int l = 8, r = 4, b = 2, t = 1;
int temp, x, y;
int cal_code(double x, double y) {
int code = 0;
if (x > xmax) {
code = r;
}
if (x < xmin) {
code = l;
}
if (y < ymin) {
code = b;
}
if (y > ymax) {
code = t;
}
return code;
}
void LineClip(double x1, double yy1, double x2, double y2) {
unsigned int outcode1, outcode2;
int accept = 0;
int done = 0;
float m = float(y2 - yy1) / (x2 - x1);
outcode1 = cal_code(x1, yy1);
outcode2 = cal_code(x2, y2);
do {
if (outcode1 == 0 && outcode2 == 0) {
accept = 1;
done = 1;
}
else if ((outcode1 & outcode2) != 0) {
done = 1;
}
else {
if (outcode1 == 0) {
temp = outcode2;
}
else {
temp = outcode1;
}
if (temp & l) {
x = xmin;
y = yy1 + m * (xmin - x1);
}
else if (temp & r) {
x = xmax;
y = yy1 + m * (xmax - x1);
}
else if (temp & t) {
y = ymax;
x = x1 + (ymax - yy1) / m;
}
else if (temp & b) {
y = ymin;
x = x1 + (ymin - yy1) / m;
}
if (temp == outcode1) {
x1 = x;
yy1 = y;
outcode1 = cal_code(x1, yy1);
}
if (temp == outcode2) {
x2 = x;
y2 = y;
outcode2 = cal_code(x2, y2);
}
}
} while (done == 0);
if (accept) {
cout << "\nAfter clipping";
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINES);
glVertex2d(x1, yy1);
glVertex2d(x2, y2);
glEnd();
}
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
glColor3f(1.0, 1.0, 1.0);
glVertex2d(xmin, ymin);
glVertex2d(xmax, ymin);
glVertex2d(xmax, ymax);
glVertex2d(xmin, ymax);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2d(x1, yy1);
glVertex2d(x2, y2);
glEnd();
LineClip(x1, yy1, x2, y2);
glFlush();
}
void myinit() {
glClearColor(0.0, 0.0, 0.0, 0.0);
glColor3f(0.0, 0.0, 0.0);
gluOrtho2D(0.0, 650.0, 0.0, 650.0);
}
int main(int argc, char** argv) {
cout << "Enter the cordinates of the window";
cout << "\nEnter point1: ";
cin >> xmin >> ymin;
cout << "\nEnter point2: ";
cin >> xmax >> ymax;
cout << "\nEnter the end points of the lines";
cout << "\nEnter point1: ";
cin >> x1 >> yy1;
cout << "\nEnter point2: ";
cin >> x2 >> y2;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(650, 650);
glutInitWindowPosition(0, 0);
glutCreateWindow("Line clipping");
myinit();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
