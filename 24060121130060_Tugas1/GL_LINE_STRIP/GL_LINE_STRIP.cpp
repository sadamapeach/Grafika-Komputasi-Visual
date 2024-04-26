/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: GL_LINE_STRIP.cpp
Deskripsi 	: Membuat program dengan menggunakan fungsi GL_LINE_STRIP
*/

// Gl_LINE_STRIP digunakan untuk membuat garis dengan lebih dari 2 koordinat

#include <gl/glut.h> void
void strip(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(15.0f);
	glBegin(GL_LINE_STRIP);
	
	// Line strip dengan warna blue-green
	glColor3f(0.0f, 0.5f, 0.5f);
	// Garis horizontal atas
	glVertex3f(-0.1, 0.1, 0.0);
	glVertex3f(0.1, 0.1, 0.0);
	// Garis diagonal
	glVertex3f(-0.1,-0.1,0.0);
	//  Garis horizontal bawah
	glVertex3f(0.1,-0.1,0.0);
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Line Strip");
	glutDisplayFunc(strip);
	glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
	glutMainLoop();
	
	return 0;
}
