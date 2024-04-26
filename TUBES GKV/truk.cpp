#include "common.h"
#include "truk.h"

//redefinition variable collision point
float cpDepanX, cpDepanZ, cpBelakangX, cpBelakangZ;

void collisionBox(float putaran, float tx, float ty, float tz) 
{
    putaran = putaran - 90;
    cpDepanX = tx + -10.0*sin(putaran*M_PI/180);
    cpDepanZ = tz + -10.0*cos(putaran*M_PI/180);

    cpBelakangX = tx + 5.0*sin(putaran*M_PI/180);
    cpBelakangZ = tz + 5.0*cos(putaran*M_PI/180);
}

void TrukGandeng(float putaran, float x, float y, float z)
{
	//glLoadIdentity();
    collisionBox(putaran, x, y, z);
    glTranslatef(x, y, z);
    
// BAGIAN KEPALA TRUK + ORNAMENNYA
	// depan buat kaca truk
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 3);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 1.0f, 0.0f); // bawah kiri
			glVertex3f(2.0f, 1.0f, 0.0f); // bawah kanan
			glVertex3f(2.0f, 1.9f, 0.0f); // atas kanan
			glVertex3f(-2.0f, 1.9f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// depan trapesium
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 3);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 1.9f, 0.0f); // bawah kiri
			glVertex3f(2.0f, 1.9f, 0.0f); // bawah kanan
			glVertex3f(2.0f, 3.5f, -0.5f); // atas kanan
			glVertex3f(-2.0f, 3.5f, -0.5f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// jendela
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 3.001);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.75f, 2.0f, -0.021f); // bawah kiri
			glVertex3f(1.75f, 2.0f, -0.021f); // bawah kanan
			glVertex3f(1.75f, 3.25f, -0.411f); // atas kanan
			glVertex3f(-1.75f, 3.25f, -0.411f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// ornamen bawah jendela
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-1.75f, 1.99f, -0.0215f); // bawah kiri
			glVertex3f(1.75f, 1.99f, -0.0215f); // bawah kanan
			glVertex3f(1.5f, 2.15f, -0.075f); // atas kanan
			glVertex3f(-1.5f, 2.15f, -0.075f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// ornanem atas jendela
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 1.1, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-1.5f, 2.0f, -0.365f); // bawah kiri
			glVertex3f(1.5f, 2.0f, -0.365f); // bawah kanan
			glVertex3f(1.75f, 2.151f, -0.42f); // atas kanan
			glVertex3f(-1.75f, 2.151f, -0.42f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// batas jendela (kiri)
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(-1.75, 0, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.01f, 1.99f, -0.025f); // bawah kiri
			glVertex3f(0.01f, 1.99f, -0.025f); // bawah kanan
			glVertex3f(0.01f, 3.25f, -0.4175f); // atas kanan
			glVertex3f(-0.01f, 3.25f, -0.4175f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// batas jendela (kanan)
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(1.75, 0, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.01f, 1.99f, -0.025f); // bawah kiri
			glVertex3f(0.01f, 1.99f, -0.025f); // bawah kanan
			glVertex3f(0.01f, 3.25f, -0.4175f); // atas kanan
			glVertex3f(-0.01f, 3.25f, -0.4175f); // atas kiri
		glEnd();
	glPopMatrix();	
	
	// ornamen
	// 1 (trapesium besar) atas
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0.0, -1.0, 3.001);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-1.65f, 2.5f, 0.0f); // bawah kiri
			glVertex3f(1.65f, 2.5f, 0.0f); // bawah kanan
			glVertex3f(1.75f, 2.8f, 0.0f); // atas kanan
			glVertex3f(-1.75f, 2.8f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// inside trapesium besar
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0.0, -0.9, 3.01);
		glColor3f(0.1f, 0.1f, 0.0f); // bronze
		glBegin(GL_QUADS);
			glVertex3f(-1.4f, 2.5f, 0.0f); // bawah kiri
			glVertex3f(1.4f, 2.5f, 0.0f); // bawah kanan
			glVertex3f(1.5f, 2.7f, 0.0f); // atas kanan
			glVertex3f(-1.5f, 2.7f, 0.0f); // atas kiri
		glEnd();
	glPopMatrix();
	
	// 2 (trapesium kecil) bawah
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
			glVertex3f(-2.0f, 0.5f, 0.0f); // depan kiri 
			glVertex3f(2.0f, 0.5f, 0.0f); // depan kanan
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
			glTexCoord2f(0.0f, 1.0f); // kiri atas
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
			glTexCoord2f(0.0f, 1.0f); // kiri atas
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
			glTexCoord2f(0.0f, 1.0f); // kiri atas
			glVertex3f(-2.0f, 2.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
//---------------------------------------------------------------------------------------------------------------------------------		
	
	// kiri persegi
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(1.75, 0, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 1.0f, 0.0f);
			glVertex3f(1.25f, 1.0f, 0.0f);
			glVertex3f(1.25f, 1.9f, 0.0f);
			glVertex3f(-1.25f, 1.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri trapesium
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(1.75, 0, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 1.9f, 0.0f);
			glVertex3f(1.25f, 1.9f, 0.0f);
			glVertex3f(0.75f, 3.5f, 0.0f);
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
	
	// kiri ornamen pintuu persegii
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(2.15, 0, 2.001);
		glColor3f(1.0f, 0.0f, 0.0f); // merah
		glBegin(GL_QUADS);
			glVertex3f(-0.75f, 1.0f, 0.0f);
			glVertex3f(0.75f, 1.0f, 0.0f);
			glVertex3f(0.75f, 1.9f, 0.0f);
			glVertex3f(-0.75f, 1.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kiri ornamen pintuu trapesium
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(2.15, 0, 2.001);
		glColor3f(1.0f, 0.0f, 0.0f); // merah
		glBegin(GL_QUADS);
			glVertex3f(-0.75f, 1.9f, 0.0f);
			glVertex3f(0.75f, 1.9f, 0.0f);
			glVertex3f(0.32f, 3.3f, 0.0f);
			glVertex3f(-0.75f, 3.3f, 0.0f);
	
	// kiri jendela kecil ornamen pintu
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(2.15, 0, 0.0);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.65f, 3.2f, 0.001f);
			glVertex3f(0.25f, 3.2f, 0.001f);
			glVertex3f(0.6f, 2.0f, 0.001f);
			glVertex3f(-0.65f, 2.0f, 0.001f);
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
	
	// kanan persegii
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-1.75, 0, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 1.0f, 0.0f);
			glVertex3f(1.25f, 1.0f, 0.0f);
			glVertex3f(1.25f, 1.9f, 0.0f);
			glVertex3f(-1.25f, 1.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	
	// kanan trapesium
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-1.75, 0, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glBegin(GL_QUADS);
			glVertex3f(-1.25f, 1.9f, 0.0f);
			glVertex3f(1.25f, 1.9f, 0.0f);
			glVertex3f(1.25f, 3.5f, 0.0f);
			glVertex3f(-0.75f, 3.5f, 0.0f);
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
	
	// kanan ornamen pintuu persegi
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2.15, 0, 2.001);
		glColor3f(1.0f, 0.0f, 0.0f); // merah
		glBegin(GL_QUADS);
			glVertex3f(-0.75f, 1.0f, 0.0f);
			glVertex3f(0.75f, 1.0f, 0.0f);
			glVertex3f(0.75f, 1.9f, 0.0f);
			glVertex3f(-0.75f, 1.9f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan ornamen pintuu atas trapesium
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2.15, 0, 2.001);
		glColor3f(1.0f, 0.0f, 0.0f); // merah
		glBegin(GL_QUADS);
			glVertex3f(-0.75f, 1.9f, 0.0f);
			glVertex3f(0.75f, 1.9f, 0.0f);
			glVertex3f(0.75f, 3.3f, 0.0f);
			glVertex3f(-0.32f, 3.3f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan jendela kecil ornamen pintu
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2.15, 0, 2.002);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.25f, 3.2f, 0.0f); 
			glVertex3f(0.65f, 3.2f, 0.0f); 
			glVertex3f(0.65f, 2.0f, 0.0f);
			glVertex3f(-0.6f, 2.0f, 0.0f);
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
		glColor3f(1.0f, 0.0f, 0.0f); // red
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
		glTranslatef(-3.05, 0.5, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f); // dark orange
		glBegin(GL_QUADS);
			glVertex3f(-3.25f, 0.5f, 0.0f);
			glVertex3f(3.25f, 0.5f, 0.0f);
			glVertex3f(3.25f, 4.0f, 0.0f);
			glVertex3f(-3.25f, 4.0f, 0.0f);
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
		glTranslatef(3.05, 3.5, -2.001); // z= kanan kiri, y= atas bawah, x=depan belakang
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.25f, 0.0f, 0.0f);
			glVertex3f(3.25f, 0.0f, 0.0f);
			glVertex3f(3.25f, 0.5f, 0.0f);
			glVertex3f(-3.25f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(3.05, 0.5, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f); // dark orange
		glBegin(GL_QUADS);
			glVertex3f(-3.25f, 0.5f, 0.0f);
			glVertex3f(3.25f, 0.5f, 0.0f);
			glVertex3f(3.25f, 4.0f, 0.0f);
			glVertex3f(-3.25f, 4.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 1 (kanan)
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
	
	// garis hiasan 2 (kanan)
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
	
	// garis hiasan 3 (kanan)
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-3.05, 3.5, -2.001); // z= kanan kiri, y= atas bawah, x=depan belakang
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.25f, 0.0f, 0.0f);
			glVertex3f(3.25f, 0.0f, 0.0f);
			glVertex3f(3.25f, 0.5f, 0.0f);
			glVertex3f(-3.25f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, -6.3);
		glColor3f(1.0f, 0.0f, 0.0f); // red
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 1.0f, 0.0f);
			glVertex3f(2.0f, 1.0f, 0.0f);
			glVertex3f(2.0f, 4.5f, 0.0f);
			glVertex3f(-2.0f, 4.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0); // kalo perseginya mau di miringin
		glTranslatef(0, -0.2, 4.5); // ubah letak perseginya, y = depan belakang, z = atas bawah, x = kanan kiri
		glColor3f(1.0f, 0.5f, 0.0f); // dark orange
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.0f, 0.0f); // depan kiri 
			glVertex3f(2.0f, 0.0f, 0.0f); // depan kanan
			glVertex3f(2.0f, 6.5f, 0.0f); // belakang kanan
			glVertex3f(-2.0f, 6.5f, 0.0f); // belakang kiri
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
		glColor3f(1.0f, 0.0f, 0.0f);
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
			glVertex3f(-2.0f, 0.5f, 0.0f);
			glVertex3f(2.0f, 0.5f, 0.0f);
			glVertex3f(2.0f, 1.0f, 0.0f);
			glVertex3f(-2.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	//kiri
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-11.4, 0.5, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.4f, 0.5f, 0.0f);
			glVertex3f(3.4f, 0.5f, 0.0f);
			glVertex3f(3.4f, 4.0f, 0.0f);
			glVertex3f(-3.4f, 4.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(11.395, 3.5, -2.001); // z= kanan kiri, y= atas bawah, x=depan belakang
		glColor3f(0.1f, 0.1f, 0.0f); 
		glBegin(GL_QUADS);
			glVertex3f(-3.395f, 0.0f, 0.0f);
			glVertex3f(3.395f, 0.0f, 0.0f);
			glVertex3f(3.395f, 0.5f, 0.0f);
			glVertex3f(-3.395f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// kanan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(11.4, 0.5, 2.0);
		glColor3f(1.0f, 0.5f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.4f, 0.5f, 0.0f);
			glVertex3f(3.4f, 0.5f, 0.0f);
			glVertex3f(3.4f, 4.0f, 0.0f);
			glVertex3f(-3.4f, 4.0f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// garis hiasan 
	glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glTranslatef(-11.395, 3.5, -2.001); // z= kanan kiri, y= atas bawah, x=depan belakang
		glColor3f(0.1f, 0.1f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-3.395f, 0.0f, 0.0f);
			glVertex3f(3.395f, 0.0f, 0.0f);
			glVertex3f(3.395f, 0.5f, 0.0f);
			glVertex3f(-3.395f, 0.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// belakang
	glPushMatrix();
		glRotated(0, 1, 0, 0);
		glTranslatef(0, 0, -14.795);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 1.0f, 0.0f);
			glVertex3f(2.0f, 1.0f, 0.0f);
			glVertex3f(2.0f, 4.5f, 0.0f);
			glVertex3f(-2.0f, 4.5f, 0.0f);
		glEnd();
	glPopMatrix();
	
	// atas
	glPushMatrix();
		glRotated(-90, 1, 0, 0); // kalo perseginya di miringin
		glTranslatef(0, 8.0, 4.5); // ubah letak perseginya, y = depan belakang, z = atas bawah, x = kanan kiri
		glColor3f(1.0f, 0.5f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.0f, 0.0f); // depan kiri 
			glVertex3f(2.0f, 0.0f, 0.0f); // depan kanan
			glVertex3f(2.0f, 6.8f, 0.0f); // belakang kanan
			glVertex3f(-2.0f, 6.8f, 0.0f); // belakang kiri
		glEnd();
	glPopMatrix();
	
	// RODA TRUK
	// RODA CONTAINER DEPAN
	//roda kanan depan
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
		glRotated(90, 0, 1, 0);
    	glTranslatef(-1.5, 0.75, 2.0); // z kanan kiri; y atas bawah; x depan belakang
    	glutSolidTorus(0.35,0.35,90,90);
	glPopMatrix();  
	
	//roda kanan belakang
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
		glRotated(90, 0, 1, 0);
    	glTranslatef(5.0, 0.75, 2.0); // z kanan kiri; y atas bawah; x depan belakang
    	glutSolidTorus(0.35,0.35,90,90);
    glPopMatrix();
    
	//roda kiri depan
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
		glRotated(90, 0, 1, 0);
    	glTranslatef(-1.5, 0.75, -2.0); // z kanan kiri; y atas bawah; x depan belakang
    	glutSolidTorus(0.35,0.35,90,90);
	glPopMatrix(); 
    
    //roda kiri belakang
	glPushMatrix();
	glColor3f(0.1,0.1,0.1);
		glRotated(90, 0, 1, 0);
    	glTranslatef(5.0, 0.75, -2.0); // z kanan kiri; y atas bawah; x depan belakang
    	glutSolidTorus(0.35,0.35,90,90);
    glPopMatrix();
    
    // RODA CONTAINER BELAKANG
	//roda kanan depan
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
		glRotated(90, 0, 1, 0);
    	glTranslatef(9.5, 0.75, 2.0); // z kanan kiri; y atas bawah; x depan belakang
    	glutSolidTorus(0.35,0.35,90,90);
	glPopMatrix();  
    
    //roda kanan belakang
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
		glRotated(90, 0, 1, 0);
    	glTranslatef(13.5, 0.75, 2.0); // z kanan kiri; y atas bawah; x depan belakang
    	glutSolidTorus(0.35,0.35,90,90);
    glPopMatrix();
	
	//roda kiri depan
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
		glRotated(90, 0, 1, 0);
    	glTranslatef(9.5, 0.75, -2.0); // z kanan kiri; y atas bawah; x depan belakang
    	glutSolidTorus(0.35,0.35,90,90);
	glPopMatrix();
    
    //roda kiri belakang
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
		glRotated(90, 0, 1, 0);
    	glTranslatef(13.5, 0.75, -2.0); // z kanan kiri; y atas bawah; x depan belakang
    	glutSolidTorus(0.35,0.35,90,90);
    glPopMatrix();
}
