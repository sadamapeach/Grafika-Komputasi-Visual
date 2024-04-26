/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: GL_TRIANGLE_STRIP.cpp
Deskripsi 	: Membuat program dengan menggunakan fungsi GL_TRIANGLE_STRIP
*/

// Gl_TRIANGLE_STRIP digunakan untuk menggambar serangkaian segitiga terhubung. 

#include <gl/glut.h> void
void t_strip(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_STRIP);
	
	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(-0.2, 0.0, 0.0); 
	glVertex3f(-0.1, -0.2, 0.0);
	glVertex3f(0.0, 0.0, 0.0); 
	
	glVertex3f(0.1, -0.2, 0.0);
	glVertex3f(0.2, 0.0, 0.0); 
	glVertex3f(0.1, 0.2, 0.0); 
	
	glVertex3f(0.0, 0.0, 0.0); 
	glVertex3f(-0.1, 0.2, 0.0);
	glVertex3f(-0.2, 0.0, 0.0);
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Triangle Strip");
	glutDisplayFunc(t_strip);
	glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
	glutMainLoop();
	
	return 0;
}
