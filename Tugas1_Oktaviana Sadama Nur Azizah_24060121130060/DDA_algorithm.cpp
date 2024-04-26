/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: DDA_algorithm.cpp
Deskripsi 	: Membuat program DDA dengan cpp dan opengl
*/

#include <gl/glut.h> void
void Garis(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	
	// Garis Vertikal
	glColor3f(2.0f, 0.5f, 1.0f); //lilac
	glVertex3f(0.0, 0.5, 0.0); //titik 1
	glVertex3f(0.0, -0.5, 0.0); //titik 2
	
	// Garis Horizontal
	glColor3f(0.0f, 0.0f, 0.0f); //hitam
	glVertex3f(0.5, 0.0, 0.0); //titik 1
	glVertex3f(-0.5, 0.0, 0.0); //titik 2
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Garis");
	glutDisplayFunc(Garis);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutMainLoop();
	
	return 0;
}
