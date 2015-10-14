#include "Support.h"
#include <stdlib.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif



// Data som delas mellan programmets olika delar
struct Shared
{
	float time;
	bool pause;
	float distance, distanceDelta;
	GLUquadric *quadric;
	GLuint sunTexture, planetTexture, planetTextureG, planetTextureG1, moonTexture, moonTexture1, earthTexture, cloudTexture, ringTexture;
};

struct Shared shared;



// Vår egen underfunktion som initierar det som behövs innan renderingen börjar
void initialize()
{
	shared.time = 0;
	shared.pause = false;
	shared.distance = 50;
	shared.distanceDelta = 0;

	shared.quadric = gluNewQuadric();
	gluQuadricTexture(shared.quadric, true);

	loadTexture("Sun.png", &shared.sunTexture);
	loadTexture("RockyPlanet2.png", &shared.planetTexture);
	loadTexture("GasPlanet2.png", &shared.planetTextureG);
	loadTexture("GasPlanet1.png", &shared.planetTextureG1);
	loadTexture("RockyPlanet1.png", &shared.moonTexture);
	loadTexture("RockyPlanet3.png", &shared.moonTexture1);
	loadTexture("Earth.png", &shared.earthTexture);
	loadTexture("EarthClouds.png", &shared.cloudTexture);
	loadTexture("Rings.png", &shared.ringTexture);
}

void drawRockyPlanet()
{
	// Rita planet
	glPushMatrix();

	//Specifierar runt vilken punkt objektet ska rotera
	glRotatef(50 * shared.time, 0, 1, 0);
	glTranslatef(0, 0, 13);

	//Specifierar individuell rotation
	glRotatef(240 * shared.time, 0, -1, 0);

	//Rotera planeten så att nordpolen är uppåt
	glRotatef(90, 1, 0, 0);

	GLfloat material_Diffuse[] = { 0.8, 0.8, 0.8, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_Diffuse);

	GLfloat material_Specular[] = { 0, 0, 0, 1 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_Specular);

	GLfloat material_Ambient[] = { 0.3, 0.3, 0.3, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_Ambient);

	GLfloat material_Shininess[] = { 100 };
	glMaterialfv(GL_FRONT, GL_SHININESS, material_Shininess);

	glBindTexture(GL_TEXTURE_2D, shared.planetTexture);
	gluSphere(shared.quadric, 2.5, 32, 32);

	glPopMatrix();
}

void drawGasPlanet()
{
	glPushMatrix();

	//Specifierar runt vilken punkt objektet ska rotera
	glRotatef(30 * shared.time, 0, 1, 0);
	glTranslatef(0, 6, 21);

	//Individuell rotation
	glRotatef(90 * shared.time, 0, 1, 0);

	glRotatef(90, 1, 0, 0);

	GLfloat material_Diffuse[] = { 0.8, 0.8, 0.8, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_Diffuse);

	GLfloat material_Specular[] = { 0, 0, 0, 1 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_Specular);

	GLfloat material_Ambient[] = { 0.3, 0.3, 0.3, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_Ambient);

	GLfloat material_Shininess[] = { 100 };
	glMaterialfv(GL_FRONT, GL_SHININESS, material_Shininess);

	glBindTexture(GL_TEXTURE_2D, shared.planetTextureG);
	gluSphere(shared.quadric, 4, 32, 32);

	//Måne 1
	glPushMatrix();
	glRotatef(90 * shared.time, 0, 1, 0);
	glTranslatef(1, 5, 2);

	glBindTexture(GL_TEXTURE_2D, shared.moonTexture);
	gluSphere(shared.quadric, 0.8, 32, 32);
	glPopMatrix();

	//Måne 2
	glPushMatrix();
	glRotatef(180 * shared.time, 10, 1, 3);
	glTranslatef(5, 1, 2);

	glBindTexture(GL_TEXTURE_2D, shared.moonTexture1);
	gluSphere(shared.quadric, 0.7, 32, 32);
	glPopMatrix();

	glPopMatrix();
}

void drawEarth()
{
	glPushMatrix();

	//Specifierar runt vilken punkt objektet ska rotera
	glRotatef(20 * shared.time, 0, 1, 0);
	glTranslatef(0, -2, 22);

	//Individuell rotation
	glRotatef(90 * shared.time, 0, 1, 0);

	//Flip
	glRotatef(90, 1, 0, 0);

	GLfloat material_Diffuse[] = { 0.8, 0.8, 0.8, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_Diffuse);

	GLfloat material_Specular[] = { 0, 0, 0, 1 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_Specular);

	GLfloat material_Ambient[] = { 0.3, 0.3, 0.3, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_Ambient);

	GLfloat material_Shininess[] = { 100 };
	glMaterialfv(GL_FRONT, GL_SHININESS, material_Shininess);

	glBindTexture(GL_TEXTURE_2D, shared.earthTexture);
	gluSphere(shared.quadric, 2.5, 32, 32);

	//Atmosfär
	glPushMatrix();

	glRotatef(180 * shared.time, 0, 0, 1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, shared.cloudTexture);
	gluSphere(shared.quadric, 2.8, 32, 32);

	glDisable(GL_BLEND);

	glPopMatrix();

	//Måne
	glPushMatrix();

	glRotatef(90 * shared.time, 0, 1, 0);
	glTranslatef(1, 4, 0);

	glBindTexture(GL_TEXTURE_2D, shared.moonTexture1);
	gluSphere(shared.quadric, 0.6, 32, 32);

	glPopMatrix();

	glPopMatrix();
}

void drawGasPlanet1()
{
	glPushMatrix();

	//Specifierar runt vilken punkt objektet ska rotera
	glRotatef(30 * shared.time, 0, 1, 0);
	glTranslatef(0, -8, 27.5);

	//Individuell rotation
	glRotatef(90 * shared.time, 0, 1, 0);

	//Flip
	glRotatef(90, 1, 0, 0);

	GLfloat material_Diffuse[] = { 0.8, 0.8, 0.8, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_Diffuse);

	GLfloat material_Specular[] = { 0, 0, 0, 1 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_Specular);

	GLfloat material_Ambient[] = { 0.3, 0.3, 0.3, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_Ambient);

	GLfloat material_Shininess[] = { 100 };
	glMaterialfv(GL_FRONT, GL_SHININESS, material_Shininess);

	//Skala
	glScalef(1, 1, 1.2);

	glBindTexture(GL_TEXTURE_2D, shared.planetTextureG1);
	gluSphere(shared.quadric, 4.5, 32, 32);

	//Måne
	glPushMatrix();

	//Rotation före translation bestämmer objektets origo
	//Rotation efter translation bestämmer individuell rotation
	glTranslatef(10, 0, 0);
	glRotatef(90 * shared.time, 0, 1, 0);

	glBindTexture(GL_TEXTURE_2D, shared.moonTexture1);
	gluSphere(shared.quadric, 1, 32, 32);

	glPopMatrix();

	//Ringsystem
	glPushMatrix();

	glDepthMask(false);

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glBindTexture(GL_TEXTURE_2D, shared.ringTexture);

	//Flip
	glRotatef(90, 1, 0, 0);

	glBegin(GL_QUADS);

	//En platt fyrhörning som ritar ut ringarna runt planeten
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(10, 0, 10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-10, 0, 10);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-10, 0, -10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(10, 0, -10);

	glEnd();
	glDisable(GL_BLEND);

	glPopMatrix();

	glPopMatrix();
}

// Vår egen underfunktion som ritar ut scenen
void drawScene()
{
	// Initiala renderingstillstånd
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glColor4f(1, 1, 1 ,1);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	//Ljus-specifikationer
	GLfloat lightAmbient[] = { 0.3, 0.3, 0.3, 1 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);

	GLfloat lightDiffuse[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);

	GLfloat lightSpecular[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular);

	GLfloat lightPos[] = {0, 0, 0, 1};
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos);

	//Ritar ut planeter och allt som tillhör dom
	drawRockyPlanet();

	drawGasPlanet();

	drawEarth();

	drawGasPlanet1();

	// Rita solen (sist)
	drawSun(shared.sunTexture);
}


// GLUT-hanterad funktion som anropas varje gång en tangent trycks ned
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:   // Esc-tangenten
		exit(0);   // Ett abrupt slut behövs eftersom vi använder GLUT
		break;
	case 'p':
		shared.pause = !shared.pause;
		break;
	case '1':
		shared.distanceDelta = 1;
		break;
	case '4':
		shared.distanceDelta = -1;
		break;
	}
}



// GLUT-hanterad funktion som anropas varje gång en tangent släpps upp
void keyboardUp(unsigned char key, int x, int y)
{
	switch(key)
	{
	case '1':
	case '4':
		shared.distanceDelta = 0;
		break;
	}
}



// GLUT-hanterad funktion som anropas efter att en angiven tid har löpt ut (ofta kallad timer)
void timer(int timeout)
{
	glutTimerFunc(timeout, timer, timeout);   // Vi måste starta om timern varje gång

	if(!shared.pause)
		shared.time += 0.01f;

	shared.distance += shared.distanceDelta;
}



// GLUT-hanterad funktion som anropas en gång för varje bildruta (frame)
void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);   // Vi vill rensa både skärmbuffert och z-buffert

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, shared.distance, 0, 0, 0, 0, 1, 0);   // Roterar kameran kring origo genom att skapa en ny vymatris varje bildruta

	drawScene();

	glutSwapBuffers();
}



// GLUT-hanterad funktion som anropas en gång när fönstret öppnas och sedan varje gång fönstret förstoras eller förminskas
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, float(width) / float(height), 0.1f, 500.0f);   // Skapar en projektionsmatris
}



// GLUT-hanterad funktion som anropas när ingen händelse (tangentbord, utritning etc) sker 
void idle()
{
	glutPostRedisplay();
}



// Startpunkt för programmet
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);   // Vi vill ha dubbelbuffring och z-buffert (depth buffer)
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Datorgrafik");

	initialize();

	glutTimerFunc(1000/60, timer, 1000/60);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMainLoop();

	return 0;
}
