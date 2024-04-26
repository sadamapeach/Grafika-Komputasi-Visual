/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: ice_cream.cpp
Deskripsi 	: Membuat gambar ice cream dari tumpukan segi empat
*/

#include <GL/glut.h>

#include <stdlib.h>

void ice_cream(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Baris 1	
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(-0.045, -0.185, 0.045, -0.215);
		
	// Baris 2
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f);
		glRectf(-0.1, -0.155, -0.045, -0.185); //kiri
		glRectf(0.045, -0.155, 0.1, -0.185); //kanan
		// Segi empat di tengah
		glColor3f(1.0f, 0.5f, 0.0f);
		glRectf(-0.045, -0.155, 0.045, -0.185);
		
	// Baris 3
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.155, -0.085, -0.1, -0.155); //kiri
		glRectf(0.1, -0.085, 0.155, -0.155); //kanan
		// Segi empat di tengah
		glColor3f(1.0f, 0.5f, 0.0f);
		glRectf(-0.1, -0.085, 0.1, -0.155);
		
	// Baris 4
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.21, -0.015, -0.155, -0.085); //kiri
		glRectf(0.155, -0.015, 0.21, -0.085); //kanan
		// Segi empat di tengah
		glColor3f(1.0f, 0.5f, 0.0f);
		glRectf(-0.155, -0.015, 0.155, -0.085);
		
	// Baris 5
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.265, 0.015, -0.21, -0.015); //kiri
		glRectf(0.21, 0.015, 0.265, -0.015); //kanan
		// Segi empat di tengah
		glColor3f(1.0f, 0.5f, 0.0f);
		glRectf(-0.21, 0.015, 0.21, -0.015);
		
	// Baris 6
	glColor3f(0.0f, 0.0f, 0.0f); 
	glRectf(-0.265, 0.045, 0.265, 0.015);
	
	// Baris 7
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.32, 0.1, -0.265, 0.045); //kiri
		glRectf(0.265, 0.1, 0.32, 0.045); //kanan
		// Segi empat di tengah
		glColor3f(1.0f, 0.5f, 0.0f);
		glRectf(-0.265, 0.1, 0.265, 0.045);
		
	// Baris 8 
		// Segi empat warna hitam
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.32, 0.15, -0.265, 0.1); //kiri
		glRectf(0.265, 0.15, 0.32, 0.1); //kanan
		glRectf(-0.215, 0.15, -0.1, 0.1); //tengah 1
		glRectf(0.1, 0.15, 0.215, 0.1); //tengah 2
		// Segi empat warna orange
		glColor3f(1.0f, 0.5f, 0.0f); 
		glRectf(-0.265, 0.15, -0.215, 0.1); //kiri
		glRectf(0.265, 0.15, 0.215, 0.1); //kanan
		glRectf(-0.1, 0.15, 0.1, 0.1); //tengah
		
	// Baris 9
		// Segi empat warna hitam
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.32, 0.2, -0.215, 0.15); //kiri
		glRectf(0.215, 0.2, 0.32, 0.15); //kanan
		glRectf(-0.1, 0.2, 0.1, 0.15); //tengah
		//Segi empat warna lilac
		glColor3f(2.0f, 0.5f, 1.0f); 
		glRectf(-0.215, 0.2, -0.1, 0.15); //kiri
		glRectf(0.1, 0.2, 0.215, 0.15); //kanan
		
	// Baris 10
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.32, 0.3, -0.375, 0.2); //kiri
		glRectf(0.375, 0.3, 0.32, 0.2); //kanan
		// Segi empat di tengah
		glColor3f(2.0f, 0.5f, 1.0f); 
		glRectf(-0.32, 0.3, 0.32, 0.2);
		
	// Baris 11
		// Segi empat warna hitam
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.32, 0.35, -0.375, 0.3); //kiri
		glRectf(0.375, 0.35, 0.32, 0.3); //kanan
		glRectf(-0.07, 0.35, 0.13, 0.3); //tengah
		// Segi empat warna lilac
		glColor3f(2.0f, 0.5f, 1.0f); 
		glRectf(-0.32, 0.35, -0.25, 0.3); //kiri
		glRectf(0.25, 0.35, 0.32, 0.3); //kanan
		glRectf(-0.14, 0.35, -0.07, 0.3); //tengah 1
		glRectf(0.07, 0.35, 0.14, 0.3); //tengah 2
		// Segi empat warna purple
		glColor3f(1.0f, 0.0f, 1.0f);
		glRectf(-0.25, 0.35, -0.14, 0.3); //kiri
		glRectf(0.14, 0.35, 0.25, 0.3); //kanan
		
	// Baris 12
		// Segi empat warna hitam
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.32, 0.4, -0.375, 0.35); //kiri
		glRectf(0.375, 0.4, 0.32, 0.35); //kanan
		glRectf(-0.195, 0.4, -0.1, 0.35); //tengah 1
		glRectf(0.1, 0.4, 0.195, 0.35); //tengah 2
		// Segi empat warna lilac
		glColor3f(2.0f, 0.5f, 1.0f); 
		glRectf(-0.32, 0.4, -0.25, 0.35); //kiri
		glRectf(0.25, 0.4, 0.32, 0.35); //kanan
		glRectf(-0.1, 0.4, 0.1, 0.35); //tengah
		// Segi empat warna purple
		glColor3f(1.0f, 0.0f, 1.0f);
		glRectf(-0.25, 0.4, -0.195, 0.35); //kiri
		glRectf(0.195, 0.4, 0.25, 0.35); //kanan
		
	// Baris 13
		// Segi empat warna hitam
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.32, 0.45, -0.25, 0.4); //kiri
		glRectf(0.25, 0.45, 0.32, 0.4); //kanan
		glRectf(-0.1475, 0.45, -0.1, 0.4); //tengah 1
		glRectf(0.1475, 0.45, 0.195, 0.4); //tengah 2
		// Segi empat warna lilac
		glColor3f(2.0f, 0.5f, 1.0f); 
		glRectf(-0.25, 0.45, -0.195, 0.4); //kiri
		glRectf(0.195, 0.45, 0.25, 0.4); //kanan
		glRectf(-0.1, 0.45, 0.1, 0.4); //tengah
		// Segi empat warna putih
		glColor3f(1.0f, 1.0f, 1.0f);
		glRectf(-0.195, 0.45, -0.1475, 0.4); //kiri
		glRectf(0.1, 0.45, 0.1475, 0.4); //kanan
		
	// Baris 14
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.32, 0.5, -0.25, 0.45); //kiri
		glRectf(0.25, 0.5, 0.32, 0.45); //kanan
		// Segi empat di tengah
		glColor3f(2.0f, 0.5f, 1.0f);
		glRectf(-0.25, 0.5, 0.25, 0.45);
		
	// Baris 15
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.25, 0.55, -0.195, 0.5); //kiri
		glRectf(0.195, 0.55, 0.25, 0.5); //kanan
		// Segi empat di tengah
		glColor3f(2.0f, 0.5f, 1.0f);
		glRectf(-0.195, 0.55, 0.195, 0.5);	
	
	// Baris 16
		// Segi empat di pinggir
		glColor3f(0.0f, 0.0f, 0.0f); 
		glRectf(-0.195, 0.6, -0.08, 0.55); //kiri
		glRectf(0.08, 0.6, 0.195, 0.55); //kanan
		// Segi empat di tengah
		glColor3f(2.0f, 0.5f, 1.0f);
		glRectf(-0.08, 0.6, 0.08, 0.55);
		
	// Baris 17
	glColor3f(0.0f, 0.0f, 0.0f); 
	glRectf(-0.08, 0.65, 0.08, 0.6);
	
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 850);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	
	glutCreateWindow("Ice Cream | Oktaviana Sadama");
	
	glutDisplayFunc(ice_cream);
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	glutMainLoop();
	
	return 0;
}
