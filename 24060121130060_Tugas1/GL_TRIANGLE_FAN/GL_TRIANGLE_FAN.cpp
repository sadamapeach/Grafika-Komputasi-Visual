/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: GL_TRIANGLE_FAN.cpp
Deskripsi 	: Membuat program dengan menggunakan fungsi GL_TRIANGLE_FAN
*/

/* Gl_TRIANGLE_FAN digunakan untuk membuat gambar dengan 1 vertex sebagai 
titik tumpuan yaitu titik awalnya. */

#include <gl/glut.h> void
void t_fan(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	
	// Garis vertical kiri
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.2, 0.2, 0.0);
	glVertex3f(-0.2, -0.3, 0.0);
	
	// Garis diagonal
	glVertex3f(0.2, 0.2, 0.0);
	
	// Garis vertical kanan
	glVertex3f(0.2, -0.3, 0.0);
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Triangle Fan");
	glutDisplayFunc(t_fan);
	glClearColor(1.0f, 0.5f, 0.0f, 0.0f);
	glutMainLoop();
	
	return 0;
}
