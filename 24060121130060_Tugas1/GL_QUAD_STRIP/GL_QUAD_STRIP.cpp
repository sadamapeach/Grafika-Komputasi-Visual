/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: GL_QUAD_STRIP.cpp
Deskripsi 	: Membuat program dengan menggunakan fungsi GL_QUAD_STRIP
*/

/* Gl_QUAD_STRIP menghasilkan output berupa segiempat yang semuanya saling
berhubungan. */

#include <gl/glut.h> void
void q_strip(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUAD_STRIP);
	
	// Segiempat warna biru
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.05, -0.2, 0.0); 
	glVertex3f(-0.05, 0.2, 0.0); 
	glVertex3f(0.05, -0.2, 0.0); 
	glVertex3f(0.05, 0.2, 0.0); 
	
	// 2 vertex 
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5, -0.6, 0.0); //bawah
	glVertex3f(0.5, 0.6, 0.0); //atas
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Segiempat (Quad Strip)");
	glutDisplayFunc(q_strip);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutMainLoop();
	
	return 0;
}
