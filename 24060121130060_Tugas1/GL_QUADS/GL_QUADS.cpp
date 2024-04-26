/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: GL_QUADS.cpp
Deskripsi 	: Membuat program dengan menggunakan fungsi GL_QUADS
*/

/* Gl_QUADS menghasilkan output berupa segiempat yang tidak saling
berhubungan. */

#include <gl/glut.h> void
void Quads(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	
	glColor3f(0.0f, 0.0f, 0.0f);
	// Segiempat kiri
	glVertex3f(-0.07, 0.2, 0.0); 
	glVertex3f(-0.07, -0.2, 0.0);
	glVertex3f(-0.17, -0.3, 0.0);
	glVertex3f(-0.17, 0.3, 0.0);
	
	// Segiempat kanan
	glVertex3f(0.05, 0.3, 0.0); 
	glVertex3f(0.05, -0.3, 0.0);
	glVertex3f(-0.05, -0.2, 0.0);
	glVertex3f(-0.05, 0.2, 0.0);
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Segiempat (Quads)");
	glutDisplayFunc(Quads);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutMainLoop();
	
	return 0;
}
