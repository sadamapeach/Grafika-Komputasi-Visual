/*
Nama		: Oktaviana Sadama Nur Azizah 
NIM			: 24060121130060
Nama File	: Truk_Gandeng.cpp
Deskripsi 	: Membuat truk gandeng statis 3D dengan menggunakan Depth dan Lighting
*/

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

float angle=0.0, deltaAngle=0.0, ratio;
float x=0.0f, y=1.75f, z=15.0f; // posisi awal kamera
float lx=0.0f, ly=0.0f, lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight = 12;

void Reshape(int w1, int h1)
{
	// Fungsi reshape
	if(h1 == 0) h1 = 1;
	w = w1;
	h = h1;
	ratio = 1.0f*w/h;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
	x, y, z,
	x+lx, y+ly, z+lz,
	0.0f, 1.0f, 0.0f);
}

void orientMe(float ang)
{
	// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan)
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(
	x, y, z,
	x+lx, y+ly, z+lz,
	0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i)
{
	// Fungsi ini untuk maju mundur kamera
	x = x + i*(lx)*0.1;
	z = z + i*(lz)*0.1;
	glLoadIdentity();
	gluLookAt(
	x, y, z,
	x+lx, y+ly, z+lz,
	0.0f, 1.0f, 0.0f);
}

void Grid()
{
	// Fungsi untuk membuat grid di "lantai"
	double i;
	const float Z_MIN = -50, Z_MAX = 50;
	const float X_MIN = -50, X_MAX = 50;
	const float gap = 1.5;
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		for(i=Z_MIN; i<Z_MAX; i+=gap)
		{
			glVertex3f(i, 0, Z_MIN);
			glVertex3f(i, 0, Z_MAX);
		}
		
		for(i=X_MIN; i<X_MAX; i+=gap)
		{
			glVertex3f(X_MIN, 0, i);
			glVertex3f(X_MAX, 0, i);
		}
	glEnd();
}

void TrukGandeng()
{
// BAGIAN KEPALA TRUK + ORNAMENNYA
	// depan buat kaca truk
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 3);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 1.0f, 0.0f); // bawah kiri
			glVertex3f(2.0f, 1.0f, 0.0f); // bawah kanan
			glVertex3f(2.0f, 3.5f, 0.0f); // atas kanan
			glVertex3f(-2.0f, 3.5f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// jendela
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 3.001);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.75f, 2.0f, 0.0f); // bawah kiri
			glVertex3f(1.75f, 2.0f, 0.0f); // bawah kanan
			glVertex3f(1.75f, 3.25f, 0.0f); // atas kanan
			glVertex3f(-1.75f, 3.25f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// ornamen bawah jendela
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-1.75f, 2.0f, 0.0f); // bawah kiri
			glVertex3f(1.75f, 2.0f, 0.0f); // bawah kanan
			glVertex3f(1.5f, 2.15f, 0.0f); // atas kanan
			glVertex3f(-1.5f, 2.15f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// ornanem atas jendela
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 1.1, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-1.5f, 2.0f, 0.0f); // bawah kiri
			glVertex3f(1.5f, 2.0f, 0.0f); // bawah kanan
			glVertex3f(1.75f, 2.15f, 0.0f); // atas kanan
			glVertex3f(-1.75f, 2.15f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// batas jendela (kiri)
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(-1.75, 0, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.01f, 2.0f, 0.0f); // bawah kiri
			glVertex3f(0.01f, 2.0f, 0.0f); // bawah kanan
			glVertex3f(0.01f, 3.25f, 0.0f); // atas kanan
			glVertex3f(-0.01f, 3.25f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// batas jendela (kanan)
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(1.75, 0, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.01f, 2.0f, 0.0f); // bawah kiri
			glVertex3f(0.01f, 2.0f, 0.0f); // bawah kanan
			glVertex3f(0.01f, 3.25f, 0.0f); // atas kanan
			glVertex3f(-0.01f, 3.25f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();	
	
	// ornamen
	// 1 (trapesium besar)
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0.0, -1.0, 3.001);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.65f, 2.55f, 0.0f); // bawah kiri
			glVertex3f(1.65f, 2.55f, 0.0f); // bawah kanan
			glVertex3f(1.75f, 2.85f, 0.0f); // atas kanan
			glVertex3f(-1.75f, 2.85f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// inside trapesium besar
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0.0, -0.9, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-1.4f, 2.55f, 0.0f); // bawah kiri
			glVertex3f(1.4f, 2.55f, 0.0f); // bawah kanan
			glVertex3f(1.5f, 2.75f, 0.0f); // atas kanan
			glVertex3f(-1.5f, 2.75f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// 2 (trapesium kecil)
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0.0, -1.0, 3.001);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.55f, 2.1f, 0.0f); // bawah kiri
			glVertex3f(1.55f, 2.1f, 0.0f); // bawah kanan
			glVertex3f(1.65f, 2.4f, 0.0f); // atas kanan
			glVertex3f(-1.65f, 2.4f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// inside trapesium kecil
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0.0, -0.9, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-1.3f, 2.1f, 0.0f); // bawah kiri
			glVertex3f(1.3f, 2.1f, 0.0f); // bawah kanan
			glVertex3f(1.4f, 2.3f, 0.0f); // atas kanan
			glVertex3f(-1.4f, 2.3f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// depan bawah  
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 3);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(2.0f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(2.0f, 1.0f, 0.0f); // atas kanan
			glVertex3f(-2.0f, 1.0f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// depan batasan 
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0.5, 3.001);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(2.0f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(2.0f, 0.525f, 0.0f); // atas kanan
			glVertex3f(-2.0f, 0.525f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// lampu kiri
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(-1.75, 0.1, 3.001);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(0.25f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(0.25f, 0.8f, 0.0f); // atas kanan
			glVertex3f(-0.25f, 0.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// lampu kanan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(1.75, 0.1, 3.001);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(0.25f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(0.25f, 0.8f, 0.0f); // atas kanan
			glVertex3f(-0.25f, 0.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// plat tanpa nomor truk 
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0.0, 0.1, 3.001);
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(0.5f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(0.5f, 0.8f, 0.0f); // atas kanan
			glVertex3f(-0.5f, 0.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------	
	
	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0); // kalo perseginya mau di miringin
		glTranslatef(0, -3, 3.5); // ubah letak perseginya, y = depan belakang, z = atas bawah, x = kanan kiri
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.0f, 0.0f); // depan kiri 
			glVertex3f(2.0f, 0.0f, 0.0f); // depan kanan
			glVertex3f(2.0f, 2.5f, 0.0f); // belakang kanan
			glVertex3f(-2.0f, 2.5f, 0.0f); // belakang kiri
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------		
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 0.5);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 3.5f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kiri bawah
			glVertex3f(-2.0f, 3.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang putih
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 0.5);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------		
	
	// bawah
	glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslatef(0, 0.5, -0.5);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 2.5f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 2.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------		
	
	// kiri
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(1.75, 0, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 1.0f, 0.0f);
			glVertex3f(1.25f, 1.0f, 0.0f);
			glVertex3f(1.25f, 3.5f, 0.0f);
			glVertex3f(-1.25f, 3.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri bawah merah
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(1.75, 0.5, 2.0);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 0.0f, 0.0f);
			glVertex3f(1.25f, 0.0f, 0.0f);
			glVertex3f(1.25f, 0.5f, 0.0f);
			glVertex3f(-1.25f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri batasan
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(1.75, 1.0, 2.005);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 0.0f, 0.0f);
			glVertex3f(1.25f, 0.0f, 0.0f);
			glVertex3f(1.25f, 0.025f, 0.0f);
			glVertex3f(-1.25f, 0.025f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri ornamen pintuu
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(2.15, 0, 2.001);
		glColor3f(1.0f, 0.0f, 0.0f); // merah
		glBegin(GL_QUADS);
			glVertex3f(-0.75f, 1.0f, 0.0f);
			glVertex3f(0.75f, 1.0f, 0.0f);
			glVertex3f(0.75f, 3.3f, 0.0f);
			glVertex3f(-0.75f, 3.3f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri jendela kecil ornamen pintu
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(2.15, 0, 2.002);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.65f, 2.3f, 0.0f);
			glVertex3f(0.65f, 2.0f, 0.0f);
			glVertex3f(0.65f, 3.2f, 0.0f);
			glVertex3f(-0.65f, 3.2f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri jendela bronze
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(1.0, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 2.35f, 0.0f);
			glVertex3f(0.25f, 2.25f, 0.0f);
			glVertex3f(0.25f, 3.2f, 0.0f);
			glVertex3f(-0.25f, 3.2f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri gagang pintu
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(1.7, 1.75, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-0.2f, 0.0f, 0.0f);
			glVertex3f(0.2f, 0.0f, 0.0f);
			glVertex3f(0.2f, 0.15f, 0.0f);
			glVertex3f(-0.2f, 0.15f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 1
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(0.9, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.015f, 2.35f, 0.0f);
			glVertex3f(0.015f, 2.35f, 0.0f);
			glVertex3f(0.015f, 0.9f, 0.0f);
			glVertex3f(-0.015f, 0.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 2
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(1.05, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.015f, 2.35f, 0.0f);
			glVertex3f(0.015f, 2.35f, 0.0f);
			glVertex3f(0.015f, 0.9f, 0.0f);
			glVertex3f(-0.015f, 0.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------			
	
	// kanan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-1.75, 0, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 1.0f, 0.0f);
			glVertex3f(1.25f, 1.0f, 0.0f);
			glVertex3f(1.25f, 3.5f, 0.0f);
			glVertex3f(-1.25f, 3.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan bawah merah
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-1.75, 0.5, 2.0);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 0.0f, 0.0f);
			glVertex3f(1.25f, 0.0f, 0.0f);
			glVertex3f(1.25f, 0.5f, 0.0f);
			glVertex3f(-1.25f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan batasan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-1.75, 1.0, 2.005);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 0.0f, 0.0f);
			glVertex3f(1.25f, 0.0f, 0.0f);
			glVertex3f(1.25f, 0.025f, 0.0f);
			glVertex3f(-1.25f, 0.025f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan ornamen pintuu
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2.15, 0, 2.001);
		glColor3f(1.0f, 0.0f, 0.0f); // merah
		glBegin(GL_QUADS);
			glVertex3f(-0.75f, 1.0f, 0.0f);
			glVertex3f(0.75f, 1.0f, 0.0f);
			glVertex3f(0.75f, 3.3f, 0.0f);
			glVertex3f(-0.75f, 3.3f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan jendela kecil ornamen pintu
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2.15, 0, 2.002);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.65f, 3.2f, 0.0f); 
			glVertex3f(0.65f, 3.2f, 0.0f); 
			glVertex3f(0.65f, 2.3f, 0.0f);
			glVertex3f(-0.65f, 2.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri jendela bronze
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-1.0, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 3.2f, 0.0f);
			glVertex3f(0.25f, 3.2f, 0.0f);
			glVertex3f(0.25f, 2.35f, 0.0f);
			glVertex3f(-0.25f, 2.25f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan gagang pintu
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-1.7, 1.75, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-0.2f, 0.0f, 0.0f);
			glVertex3f(0.2f, 0.0f, 0.0f);
			glVertex3f(0.2f, 0.15f, 0.0f);
			glVertex3f(-0.2f, 0.15f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 1
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-0.9, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.015f, 2.35f, 0.0f);
			glVertex3f(0.015f, 2.35f, 0.0f);
			glVertex3f(0.015f, 0.9f, 0.0f);
			glVertex3f(-0.015f, 0.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 2
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-1.05, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.015f, 2.35f, 0.0f);
			glVertex3f(0.015f, 2.35f, 0.0f);
			glVertex3f(0.015f, 0.9f, 0.0f);
			glVertex3f(-0.015f, 0.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------
	
// GANDENGAN TRUK 1
	// bawahan truk
	// kiri
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-3.0, 0.5, 2.0);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.5f, 0.0f);
			glVertex3f(-3.5f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(3.0, 0.5, 2.0);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.5f, 0.0f);
			glVertex3f(-3.5f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// bawah
	glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslatef(0, -3.0, -0.5);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, -3.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, -3.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 3.5f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 3.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0);
		glTranslatef(0, 3.0, 1.0);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, -3.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, -3.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 3.5f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 3.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, -6.5);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// lampu kiri
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(-1.65, 0.1, -6.525);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(0.25f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(0.25f, 0.8f, 0.0f); // atas kanan
			glVertex3f(-0.25f, 0.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// lampu kanan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(1.65, 0.1, -6.525);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(0.25f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(0.25f, 0.8f, 0.0f); // atas kanan
			glVertex3f(-0.25f, 0.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------	
	
	// main part
	// depan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 0.2);
		glColor3f(0.0f, 0.1f, 0.0f); // forest green
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 4.5f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kiri bawah
			glVertex3f(-2.0f, 4.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan depan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 3, 0.201);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-3.15, 0.5, 2.0);
		glColor3f(0.0f, 0.1f, 0.0f); // forest green
		glBegin(GL_QUADS);
			glVertex3f(-3.35f, 0.5f, 0.0f);
			glVertex3f(3.35f, 0.5f, 0.0f);
			glVertex3f(3.35f, 4.0f, 0.0f);
			glVertex3f(-3.85f, 4.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 1 (kiri)
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-0.5, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.015f, 4.4f, 0.0f);
			glVertex3f(0.015f, 4.4f, 0.0f);
			glVertex3f(0.015f, 0.9f, 0.0f);
			glVertex3f(-0.015f, 0.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 2 (kiri)
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-1.0, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.015f, 4.4f, 0.0f);
			glVertex3f(0.015f, 4.4f, 0.0f);
			glVertex3f(0.015f, 0.9f, 0.0f);
			glVertex3f(-0.015f, 0.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 3 (kiri)
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(3.3, 3.5, -2.001); // z= kanan kiri, y= atas bawah, x=depan belakang
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.5f, 0.0f, 0.0f);
			glVertex3f(3.55f, 0.0f, 0.0f);
			glVertex3f(3.6f, 0.5f, 0.0f);
			glVertex3f(-3.5f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(3.15, 0.5, 2.0);
		glColor3f(0.0f, 0.1f, 0.0f); // forest green
		glBegin(GL_QUADS);
			glVertex3f(-3.35f, 0.5f, 0.0f);
			glVertex3f(3.35f, 0.5f, 0.0f);
			glVertex3f(3.85f, 4.0f, 0.0f);
			glVertex3f(-3.35f, 4.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 1 (kiri)
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(0.5, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.015f, 4.4f, 0.0f);
			glVertex3f(0.015f, 4.4f, 0.0f);
			glVertex3f(0.015f, 0.9f, 0.0f);
			glVertex3f(-0.015f, 0.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 2 (kiri)
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(1.0, 0.1, 2.002);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.015f, 4.4f, 0.0f);
			glVertex3f(0.015f, 4.4f, 0.0f);
			glVertex3f(0.015f, 0.9f, 0.0f);
			glVertex3f(-0.015f, 0.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 3 (kiri)
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-3.3, 3.5, -2.001); // z= kanan kiri, y= atas bawah, x=depan belakang
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.55f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.5f, 0.0f);
			glVertex3f(-3.6f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, -6.5);
		glColor3f(0.1f, 0.1f, 0.1f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 4.5f, -0.5f);
			glTexCoord2f(0.0f, 1.0f); // kiri atas
			glVertex3f(-2.0f, 4.5f, -0.5f);
		glEnd();
	glPopMatrix();
	
	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0); // kalo perseginya mau di miringin
		glTranslatef(0, -0.2, 4.5); // ubah letak perseginya, y = depan belakang, z = atas bawah, x = kanan kiri
		glColor3f(0.0f, 0.1f, 0.0f); // forest green
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.0f, 0.0f); // depan kiri 
			glVertex3f(2.0f, 0.0f, 0.0f); // depan kanan
			glVertex3f(2.0f, 7.2f, 0.0f); // belakang kanan
			glVertex3f(-2.0f, 7.2f, 0.0f); // belakang kiri
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------		

// KONEKTOR TRUK
	//kanan bagian lampu kiri
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(7.25, 0.5, 0.75);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glVertex3f(-0.775f, 0.0f, 0.0f);
			glVertex3f(0.775f, 0.0f, 0.0f);
			glVertex3f(0.775f, 0.5f, 0.0f);
			glVertex3f(-0.775f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();

	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0);
		glTranslatef(0.75, 7.25, 1.0);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(0.0f, -0.775f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(0.0f, 0.775f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(0.5f, 0.775f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(0.5f, -0.775f, 0.0f);
		glEnd();
	glPopMatrix();

	// bawah
	glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslatef(0.75, -7.25, -0.5);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(0.0f, -0.775f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(0.0f, 0.775f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(0.5f, 0.775f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(0.5f, -0.775f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(-1, 0, -8.025);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-0.25f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(0.25f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(0.25f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kiri bawah
			glVertex3f(-0.25f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// depan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(-1, 0, -6.475);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-0.25f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(0.25f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(0.25f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kiri bawah
			glVertex3f(-0.25f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri bagian lampu kiri
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-7.25, 0.5, -1.25); // jarak gandengan 1.5
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glVertex3f(-0.775f, 0.0f, 0.0f);
			glVertex3f(0.775f, 0.0f, 0.0f);
			glVertex3f(0.775f, 0.5f, 0.0f);
			glVertex3f(-0.775f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan bagian lampu kanan
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-7.25, 0.5, 0.75); // jarak gandengan 1.5
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glVertex3f(-0.775f, 0.0f, 0.0f);
			glVertex3f(0.775f, 0.0f, 0.0f);
			glVertex3f(0.775f, 0.5f, 0.0f);
			glVertex3f(-0.775f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0);
		glTranslatef(-1.25, 7.25, 1.0);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(0.0f, -0.775f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(0.0f, 0.775f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(0.5f, 0.775f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(0.5f, -0.775f, 0.0f);
		glEnd();
	glPopMatrix();

	// bawah
	glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslatef(-1.25, -7.25, -0.5);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(0.0f, -0.775f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(0.0f, 0.775f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(0.5f, 0.775f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(0.5f, -0.775f, 0.0f);
		glEnd();
	glPopMatrix();	
	
	// depan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(1, 0, -6.475);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-0.25f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(0.25f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(0.25f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kiri bawah
			glVertex3f(-0.25f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(1, 0, -8.025);
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-0.25f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(0.25f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(0.25f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kiri bawah
			glVertex3f(-0.25f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri bagian lampu kanan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(7.25, 0.5, -1.25); // jarak gandengan 1.5
		glColor3f(0.1, 0.1, 0.1); // dark grey
		glBegin(GL_QUADS);
			glVertex3f(-0.775f, 0.0f, 0.0f);
			glVertex3f(0.775f, 0.0f, 0.0f);
			glVertex3f(0.775f, 0.5f, 0.0f);
			glVertex3f(-0.775f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------	

// GANDENGAN TRUK 2
	// bawahan truk
	// kiri
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-11.5, 0.5, 2.0); // jarak gandengan 1.5
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.5f, 0.0f);
			glVertex3f(-3.5f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(11.5, 0.5, 2.0);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.0f, 0.0f);
			glVertex3f(3.5f, 0.5f, 0.0f);
			glVertex3f(-3.5f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// bawah
	glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslatef(0, -11.5, -0.5);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, -3.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, -3.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 3.5f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 3.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0);
		glTranslatef(0, 11.5, 1.0);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, -3.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, -3.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 3.5f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 3.5f, 0.0f);
		glEnd();
	glPopMatrix();

	// depan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, -8.0);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, -15.0);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// lampu kiri
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(-1.6, 0.12, -15.01);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(0.25f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(0.25f, 0.8f, 0.0f); // atas kanan
			glVertex3f(-0.25f, 0.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// lampu kanan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(1.6, 0.12, -15.01);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(0.25f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(0.25f, 0.8f, 0.0f); // atas kanan
			glVertex3f(-0.25f, 0.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// plat tanpa nomor truk 
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0.0, 0.1, -15.001);
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f, 0.5f, 0.0f); // bawah kiri
			glVertex3f(0.5f, 0.5f, 0.0f); // bawah kanan
			glVertex3f(0.5f, 0.8f, 0.0f); // atas kanan
			glVertex3f(-0.5f, 0.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();	
	
//---------------------------------------------------------------------------------------------------------------------------------	
	
	// main part
	// depan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, -8.0);
		glColor3f(0.0f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 4.5f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kiri bawah
			glVertex3f(-2.0f, 4.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan depan
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 3, -7.999);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); // kanan bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	//kiri
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-11.5, 0.5, 2.0);
		glColor3f(0.0f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.5f, 0.5f, 0.0f);
			glVertex3f(3.5f, 0.5f, 0.0f);
			glVertex3f(3.5f, 4.0f, 0.0f);
			glVertex3f(-4.0f, 4.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(11.7, 3.5, -2.001); // z= kanan kiri, y= atas bawah, x=depan belakang
		glColor3f(0.1f, 0.1f, 0.0f); 
		glBegin(GL_QUADS);
			glVertex3f(-3.7f, 0.0f, 0.0f);
			glVertex3f(3.655f, 0.0f, 0.0f);
			glVertex3f(3.725f, 0.5f, 0.0f);
			glVertex3f(-3.7f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(11.5, 0.5, 2.0);
		glColor3f(0.0f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.5f, 0.5f, 0.0f);
			glVertex3f(3.5f, 0.5f, 0.0f);
			glVertex3f(4.0f, 4.0f, 0.0f);
			glVertex3f(-3.5f, 4.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-11.7, 3.5, -2.001); // z= kanan kiri, y= atas bawah, x=depan belakang
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.655f, 0.0f, 0.0f);
			glVertex3f(3.7f, 0.0f, 0.0f);
			glVertex3f(3.7f, 0.5f, 0.0f);
			glVertex3f(-3.725f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, -15.0);
		glColor3f(0.1f, 0.1f, 0.1f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); // kiri bawah
			glVertex3f(-2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); // kanan bawah
			glVertex3f(2.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); // kanan atas
			glVertex3f(2.0f, 4.5f, -0.5f);
			glTexCoord2f(0.0f, 1.0f); // kiri atas
			glVertex3f(-2.0f, 4.5f, -0.5f);
		glEnd();
	glPopMatrix();
	
	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0); // kalo perseginya di miringin
		glTranslatef(0, 8.0, 4.5); // ubah letak perseginya, y = depan belakang, z = atas bawah, x = kanan kiri
		glColor3f(0.0f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.0f, 0.0f); // depan kiri 
			glVertex3f(2.0f, 0.0f, 0.0f); // depan kanan
			glVertex3f(2.0f, 7.5f, 0.0f); // belakang kanan
			glVertex3f(-2.0f, 7.5f, 0.0f); // belakang kiri
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------	
	void cylinder(float alas, float atas, float tinggi); // meng-declared fungsi cylinder roda
	{
	glPushMatrix(); //roda kiri depan | dilihat dari depan --> kiri
		glRotated(90, 0, 10, 0);
		glTranslatef(-2.25, 0.55, -2.225); // x= depan belakang, y= atas bawah, z= kanan kiri
		glColor3f(0.1, 0.1, 0.1); // dark grey
     		cylinder(0.5, 0.5, 0.5);
     	glEnd();
	glPopMatrix();
	
	glPushMatrix(); //roda kiri tengah 
		glRotated(90, 0, 10, 0);
		glTranslatef(4.5, 0.55, -2.225); // x= depan belakang, y= atas bawah, z= kanan kiri
		glColor3f(0.1, 0.1, 0.1); // dark grey
     		cylinder(0.5, 0.5, 0.5);
     	glEnd();
	glPopMatrix();
	
	glPushMatrix(); //roda kiri depan gandengan 2
		glRotated(90, 0, 10, 0);
		glTranslatef(8.0, 0.55, -2.225); // x= depan belakang, y= atas bawah, z= kanan kiri
		glColor3f(0.1, 0.1, 0.1); // dark grey
     		cylinder(0.5, 0.5, 0.5);
     	glEnd();
	glPopMatrix();
	
	glPushMatrix(); //roda kiri belakang gandengan 2
		glRotated(90, 0, 10, 0);
		glTranslatef(13.0, 0.55, -2.225); // x= depan belakang, y= atas bawah, z= kanan kiri
		glColor3f(0.1, 0.1, 0.1); // dark grey
     		cylinder(0.5, 0.5, 0.5);
     	glEnd();
	glPopMatrix();
     	
    glPushMatrix(); //roda kanan depan
		glRotated(90, 0, -10, 0);
		glTranslatef(0.25, 0.55, -2.225); // x= depan belakang, y= atas bawah, z= kanan kiri
		glColor3f(0.1, 0.1, 0.1); // dark grey
     		cylinder(0.5, 0.5, 0.5);
     	glEnd();
	glPopMatrix();
	
	glPushMatrix(); //roda kanan tengah
		glRotated(90, 0, -10, 0);
		glTranslatef(-6.5, 0.55, -2.225); // x= depan belakang, y= atas bawah, z= kanan kiri
		glColor3f(0.1, 0.1, 0.1); // dark grey
     		cylinder(0.5, 0.5, 0.5);
     	glEnd();
	glPopMatrix();
	
	glPushMatrix(); //roda kanan tengah
		glRotated(90, 0, -10, 0);
		glTranslatef(-10.0, 0.55, -2.225); // x= depan belakang, y= atas bawah, z= kanan kiri
		glColor3f(0.1, 0.1, 0.1); // dark grey
     		cylinder(0.5, 0.5, 0.5);
     	glEnd();
	glPopMatrix();
	
		
	glPushMatrix(); //roda kanan belakang
		glRotated(90, 0, -10, 0);
		glTranslatef(-15.0, 0.55, -2.225); // x= depan belakang, y= atas bawah, z= kanan kiri
		glColor3f(0.1, 0.1, 0.1); // dark grey
     		cylinder(0.5, 0.5, 0.5);
     	glEnd();
	glPopMatrix();
	}
}

// Fungsi cylinder yang membentuk roda
void cylinder(float alas, float up, float height)
{	
    float i;
    glPushMatrix();
    glTranslatef(1.0,0.0,-alas/8); // perpindahan dari x, y, z
    glutSolidCone(alas,0,32,4);
    for(i=0;i<=height;i+=alas/24)
    {
    glTranslatef(0.0,0.0,alas/24);
    glutSolidTorus(alas/4,alas-((i*(alas-up))/height),16,16);
    }
    glTranslatef(0.0,0.0,alas/4);
    glutSolidCone(height,0,20,1);
    glColor3f(0.,0.,0.);
    glPopMatrix();
}

void display()
{
	// Jika move dan angle tidak nol, gerakkan kamera...
	usleep(1);
	if(deltaMove)
		moveMeFlat(deltaMove);
	if(deltaAngle)
	{
		angle += deltaAngle;
		orientMe(angle);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	// Gambar grid
	Grid();
	
	// Gambar objek di sini...
	TrukGandeng();
	glutSwapBuffers();
	glFlush();
}

void pressKey(int key, int x, int y)
{
	// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
	// Selama tombol ditekan, variabel angle dan move diubah --> kamera bergerak
	switch (key)
	{
		case GLUT_KEY_LEFT	: deltaAngle = -0.01f; break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.01f; break;
		case GLUT_KEY_UP	: deltaMove  = 1; break; 
		case GLUT_KEY_DOWN	: deltaMove  = -1; break; 
	}
}

void releaseKey(int key, int x, int y)
{
	// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
	// Saat tombol dilepas, variabel angle dan move diset nol --> kamera berhenti
	switch(key)
	{
		case GLUT_KEY_LEFT:
			if(deltaAngle < 0.0f)
				deltaAngle = 0.0f;
			break;
			
		case GLUT_KEY_RIGHT:
			if(deltaAngle > 0.0f)
				deltaAngle = 0.0f;
			break;
			
		case GLUT_KEY_UP:
			if(deltaMove > 0)
				deltaMove = 0;
			break;
			
		case GLUT_KEY_DOWN:
			if(deltaMove < 0)
				deltaMove = 0;
			break;
	}
}

// Variabel untuk pencahayaan
const GLfloat light_ambient[]  = {0.5f, 0.5f, 0.5f, 0.0f};
const GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {0.0f, 20.0f, 10.0f, 1.0f};

const GLfloat mat_ambient[]	 = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[]  = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

const GLfloat high_shininess[] ={100.0f}; // besar pantulan cahaya

void lighting()
{
	// Fungsi mengaktifkan pencahayaan
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 
 	glEnable(GL_LIGHT0); 
 	glEnable(GL_NORMALIZE); 
 	glEnable(GL_COLOR_MATERIAL); 
 	glEnable(GL_LIGHTING); 
 	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
 	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
 	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
 	glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
 	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
 	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
 	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
}

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
int main(int argc, char**argv) 
{ 
	glutInit(&argc, argv); 
 	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
 	glutInitWindowPosition(100,100); 
 	glutInitWindowSize(640,480); 
 	glutCreateWindow("3D Lighting | Truk Gandeng"); 
 	glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol keyboard dipencet terus) 
 	glutSpecialFunc(pressKey);
 	glutSpecialUpFunc(releaseKey); 
 	glutDisplayFunc(display); 
 	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
 	glutIdleFunc(display); // Fungsi displaynya dipanggil terusmenerus 
 	glutReshapeFunc(Reshape); 
 	lighting(); 
 	init(); 
 	glutMainLoop(); 
 
 	return(0);
}
