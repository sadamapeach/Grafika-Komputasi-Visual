/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: GL_LINE_LOOP.cpp
Deskripsi 	: Membuat program dengan menggunakan GL_LINE_LOOP
*/

// GL_LINE_LOOP secara otomatis mengubungkan koordinat akhir dengan koordinat awal.

#include <gl/glut.h> void
void loop(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(18.0f);
	glBegin(GL_LINE_LOOP);
	
	// Garis horizontal atas
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-0.15, 0.15, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.15, 0.15, 0.0);
	
	// Garis diagonal
	glColor3f(0.0f, 0.5f, 0.5f);
	glVertex3f(-0.15, -0.2, 0.0);
	
	//  Garis horizontal bawah
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.15, -0.2, 0.0);
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Line Loop");
	glutDisplayFunc(loop);
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	glutMainLoop();
	
	return 0;
}
