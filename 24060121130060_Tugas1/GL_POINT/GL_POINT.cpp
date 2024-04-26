/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: GL_POINT.cpp
Deskripsi 	: Membuat titik menggunakana GL_POINT
*/

#include <gl/glut.h> void
void point(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(20.0f);
	glBegin(GL_POINTS);
	
	// Titik 1 (lilac)
	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(-0.5, 0.255, 0.0);
	
	// Titik 2 (baby blue)
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex3f(0.5, -0.255, 0.0);
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Titik");
	glutDisplayFunc(point);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutMainLoop();
	
	return 0;
}
