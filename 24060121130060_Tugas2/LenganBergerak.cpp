/*
Nama		: Oktaviana Sadama Nur Azizah
NIM			: 24060121130060
Nama File	: LenganBergerak.cpp
Deskripsi	: Modifikasi kode lengan bergerak dengan menambahkan
			  telapak tangan dan jari
*/

#include <GL/glut.h>

static int shoulder = 0, elbow = 120, palm = 0, thumb = 30,
index = 0, middle = 0, ring = 0, little = 0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
		// shoulder
		glTranslatef(-0.8, 0.0, 0.0);
		glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
		glTranslatef(0.8, 0.0, 0.0);
		
		glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(0.8);
		glPopMatrix();
		
		// elbow	
		glTranslatef(0.75, 0.0, 0.0);
		glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
		glTranslatef (0.75, 0.0, 0.0);
	
		glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(0.75);
		glPopMatrix();
				
		// palm
		glTranslatef(0.55, 0.0, 0.0);
		glRotatef((GLfloat) palm, 0.0, 0.0, 1.0);
		glTranslatef (0.55, 0.0, 0.0);
	
		glPushMatrix();
			glScalef(0.78, 0.95, 0.3);
			glutWireCube(0.55);
		glPopMatrix();
			
		// thumb
		glPushMatrix();
			glTranslatef(0.12, 0.16, 0.0);
			glRotatef((GLfloat) thumb, 0.0, 0.0, 1.0);
			glTranslatef (0.12, 0.16, 0.0);
	
			glPushMatrix();
				glScalef(0.4, 0.15, 0.1);
				glutWireCube(0.6);
			glPopMatrix();
		glPopMatrix();
			
		// index
		glPushMatrix();
			glTranslatef(0.21, 0.1, 0.0);
			glRotatef((GLfloat) index, 0.0, 0.0, 1.0);
			glTranslatef (0.21, 0.1, 0.0);

			glPushMatrix();
				glScalef(0.75, 0.15, 0.1);
				glutWireCube(0.6);
			glPopMatrix();
		glPopMatrix();
		
		// middle
		glPushMatrix();
			glTranslatef(0.23, 0.03, 0.0);
			glRotatef((GLfloat) middle, 0.0, 0.0, 1.0);
			glTranslatef (0.23, 0.03, 0.0);
		
			glPushMatrix();
				glScalef(0.9, 0.15, 0.1);
				glutWireCube(0.6);
			glPopMatrix();		
		glPopMatrix();
		
		// ring
		glPushMatrix();
			glTranslatef(0.2, -0.04, 0.0);
			glRotatef((GLfloat) ring, 0.0, 0.0, 1.0);
			glTranslatef (0.2, -0.04, 0.0);

			glPushMatrix();
				glScalef(0.7, 0.15, 0.1);
				glutWireCube(0.6);
			glPopMatrix();
		glPopMatrix();
		
		// little
		glPushMatrix();
			glTranslatef(0.16, -0.1, 0.0);
			glRotatef((GLfloat) little, 0.0, 0.0, 1.0);
			glTranslatef (0.16, -0.1, 0.0);
	
			glPushMatrix();
				glScalef(0.45, 0.15, 0.1);
				glutWireCube(0.6);
			glPopMatrix();
		glPopMatrix();
		
	glPopMatrix();
	glutSwapBuffers();
}

void reshape (int w, int h) 
{ 
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	glTranslatef (0.0, 0.0, -5.0); 
}

void keyboard(unsigned char key, int x, int y) 
{ 
	switch (key) 
	{
		case 'S': shoulder = (shoulder + 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
 		case 's': shoulder = (shoulder - 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
				  
  		case 'E': elbow = (elbow + 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
		case 'e': elbow = (elbow - 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
				  
		case 'P': palm = (palm + 5) % 30; 
				  glutPostRedisplay(); 
				  break; 
		case 'p': palm = (palm - 5) % 30; 
				  glutPostRedisplay(); 
				  break; 
				  
		case 'T': thumb = (thumb + 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
		case 't': thumb = (thumb - 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
				  
		case 'I': index = (index + 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
		case 'i': index = (index - 5) % 360; 
				  glutPostRedisplay(); 
				  break;
				  
		case 'M': middle = (middle + 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
		case 'm': middle = (middle - 5) % 360; 
				  glutPostRedisplay(); 
				  break;
				  
		case 'R': ring = (ring + 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
		case 'r': ring = (ring - 5) % 360; 
				  glutPostRedisplay(); 
				  break;
				  
		case 'L': little = (little + 5) % 360; 
				  glutPostRedisplay(); 
				  break; 
		case 'l': little = (little - 5) % 360; 
				  glutPostRedisplay(); 
				  break;
				  		  
		case 27: exit(0); 
				 break; 
		default: break; 
 	}	 
} 

int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); 
	glutInitWindowSize (1000, 500); 
	glutInitWindowPosition (100, 50); 
	glutCreateWindow (argv[0]);
	
	init(); 
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutKeyboardFunc(keyboard); 
	glutMainLoop(); 
	return 0; 
} 	
