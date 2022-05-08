#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<cmath>
static int menu_id;
static int submenu_id;
using namespace std;
#define w 640
#define h 480
float B[6];
float A[3][2];
float x1, yy1, x2, y2, x3, y3;
void translation();
void scaling();
void shearing();
void reflection();
void rotation();
void init(void) {
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,0.0,1.0);
glColor3f(1.0, 1.0, 1.0);
glPointSize(4.0);
gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
}
void swap(float *a, float *b) {
float temp;
temp = *a;
*a = *b;
*b = temp;
}
void rotation() {
int k = 0;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 2; j++) {
A[i][j] = B[k];
k++;
}
}
double a;
int i = 0;
cout << "Enter angle of rotation: ";
cin >> a;
a = (a * 3.14) / 180;
cout << "\n1.Clockwise\n2.Anti-clockwise"<<endl;
cout << "Enter: ";
cin >> i;
if (i == 1) {
A[0][0] = B[0] * cos(a) +B[1] * sin(a);
A[0][1] = -B[0] * sin(a) + B[1] * cos(a);
A[1][0] = B[2] * cos(a) + B[3] * sin(a);
A[1][1] = -B[2] * sin(a) + B[3] * cos(a);
A[2][0] = B[4] * cos(a) + B[5] * sin(a);
A[2][1] = -B[4] * sin(a) + B[5] * cos(a);
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
else if (i == 2) {
A[0][0] = B[0] * cos(a) - B[1] * sin(a);
A[0][1] = B[0] * sin(a) + B[1] * cos(a);
A[1][0] = B[2] * cos(a) - B[3] * sin(a);
A[1][1] = B[2]* sin(a) + B[3] * cos(a);
A[2][0] = B[4] * cos(a) - B[5] * sin(a);
A[2][1] = B[4] * sin(a) + B[5] * cos(a);
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
else {
cout << "Enter valid choice";
}
}
void reflection() {
int k = 0;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 2; j++) {
A[i][j] = B[k];
k++;
}
}
int i = 0;
cout << "Reflection along: \n1.X axis\n2.Yaxis\n3.Origin\n4.x=y"<<endl;
cout << "Enter: ";
cin >> i;
if (i == 1) {
A[0][1] = -A[0][1];
A[1][1] = -A[1][1];
A[2][1] = -A[2][1];
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
else if (i == 2) {
A[0][0] = -A[0][0];
A[1][0] = -A[1][0];
A[2][0] = -A[2][0];
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
else if (i == 3) {
A[0][1] = -A[0][1];
A[1][1] = -A[1][1];
A[2][1] = -A[2][1];
A[0][0] = -A[0][0];
A[1][0] = -A[1][0];
A[2][0] = -A[2][0];
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
else if (i == 4) {
swap(&A[0][0], &A[0][1]);
swap(&A[1][0], &A[1][1]);
swap(&A[2][0], &A[2][1]);
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
else{
cout << "Enter appropriate value";
}
}
void shearing() {
float sx, sy;
int k = 0;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 2; j++) {
A[i][j] = B[k];
k++;
}
}
int i = 0;
cout << "Shearing along \n1.X axis \n2.Yaxis\n";
cout << "Enter: ";
cin >> i;
if (i == 1) {
cout << "Enter shearing factor sx: ";
cin >> sx;
A[0][0] += sx * A[0][1];
A[1][0] += sx * A[1][1];
A[2][0] += sx * A[2][1];
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
else if (i == 2) {
cout << "Enter shearing factor sy: ";
cin >> sy;
A[0][1] += sy * A[0][0];
A[1][1] += sy * A[1][0];
A[2][1] += sy * A[2][0];
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
else {
cout << "Enter valid choice";
}
}
void scaling() {
float sx, sy;
cout << "Enter scaling factor sx: ";
cin >> sx;
cout << "Enter scaling factor sy: ";
cin >> sy;
int k = 0;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 2; j++) {
A[i][j] = B[k];
k++;
}
}
A[0][0] *= sx;
A[0][1] *= sy;
A[1][0] *= sx;
A[1][1] *= sy;
A[2][0] *= sx;
A[2][1] *= sy;
glLineWidth(4.0);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0], A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
void translation(){
float tx, ty;
cout << "Enter tx: ";
cin >> tx;
cout << "Enter ty: ";
cin >> ty;
int k = 0;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 2; j++) {
A[i][j] = B[k];
k++;
}
}
A[0][0]+=tx;
A[0][1]+=ty;
A[1][0]+=tx;
A[1][1]+=ty;
A[2][0]+=tx;
A[2][1]+=ty;
glColor3f(1,0,0);
glLineWidth(4.0);
glBegin(GL_LINE_LOOP);
glVertex2f(A[0][0],A[0][1]);
glVertex2f(A[1][0], A[1][1]);
glVertex2f(A[2][0], A[2][1]);
glEnd();
glFlush();
}
void draw() {
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
glVertex2d(-w / 2, 0);
glVertex2d(w / 2, 0);
glVertex2d(0, -h / 2);
glVertex2d(0, h / 2);
glEnd();
glLineWidth(4.0);
glColor3f(1,1,1);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 6; i+=2) {
glVertex2f(B[i], B[i + 1]);
}
glEnd();
glFlush();
}
void menu(int a) {
switch (a) {
case 1: translation();
break;
case 2: scaling();
break;
case 3: shearing();
break;
case 4: reflection();
break;
case 5: rotation();
break;
}
}
int main(int argc, char* argv[]) {
for (int i = 0; i < 6; i+=2) {
cout << "Enter first vertex: ";
cin >> B[i] >> B[i + 1];
}
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(800, 600);
glutInitWindowPosition(100, 100);
glutCreateWindow("bbh");
glutDisplayFunc(draw);
submenu_id=glutCreateMenu(menu);
glutAddMenuEntry("1. Translation", 1);
glutAddMenuEntry("2. Scaling", 2);
glutAddMenuEntry("3. Shearing", 3);
glutAddMenuEntry("4. Reflection", 4);
glutAddMenuEntry("4. Rotation", 5);
menu_id = glutCreateMenu(menu);
glutAddSubMenu("DRAW", submenu_id);
glutAddMenuEntry("Exit", 6);
glutAttachMenu(GLUT_RIGHT_BUTTON);
init();
glutMainLoop();
return(0);
}
