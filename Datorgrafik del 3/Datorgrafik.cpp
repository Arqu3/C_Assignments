#include "Support.h"
#include "Camera.h"
#include <stdlib.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <ApplicationServices/ApplicationServices.h>
#else
#include <glut.h>
#endif



// Data som delas mellan programmets olika delar
struct Shared
{
	float time;
	bool pause;
	bool mouseWarped;
	GLuint floorTexture, pillarTexture, earthTexture;
	Camera camera;
	GLUquadric *quadric;
	bool isOrbit = true;
	bool isRoll = false;
	bool isMovement = false;
	bool is4View = false;
	int mode = 1;
};

struct Shared shared;

#pragma  region Vertices
GLfloat vertexArray[] =
{
	-7, -5, -7, //0

	7, -5, -7, //1

	7, -5, 7, //2

	-7, -5, 7, //3

	7, 0, 7, //4

	7, 0, -7, //5

	-7, 0, -7, //6

	-7, 0, 7, //7

	0, 10, 0 //8
};
#pragma endregion ..

#pragma  region VertexIndex
GLint indexArray[] =
{
	0, 1, 2,

	2, 3, 0,

	4, 2, 1,

	1, 5, 4,

	5, 1, 0,

	0, 6, 5,

	6, 0, 3,

	3, 7, 6,

	7, 3, 2,

	4, 7, 2,

	5, 6, 8,

	6, 7, 8,

	7, 4, 8,

	4, 5, 8
};

#pragma  region Colors
GLfloat colorArray[] =
{
	0.4, 0.4, 0.4,

	0.9, 0.7, 0.4,

	0.9, 0.4, 0,

	0, 0.9, 0.4,

	0, 0, 0.9,

	0.9, 0, 0,

	0, 0.9, 0,

	0.9, 0.9, 0.9,

	0.9, 0, 0.9,
};
#pragma  endregion ..

// Vår egen underfunktion som initierar det som behövs innan renderingen börjar
void initialize()
{
	shared.time = 0;
	shared.pause = false;
	shared.mouseWarped = false;

	shared.quadric = gluNewQuadric();
	gluQuadricTexture(shared.quadric, true);

	loadTexture("Floor.png", &shared.floorTexture);
	loadTexture("Pillar.png", &shared.pillarTexture);
	loadTexture("Earth.png", &shared.earthTexture);
}

void drawPolyObject()
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT, GL_FILL);

	glPushMatrix();
	//Förflytta X mha cos
	glTranslatef(0, 15, 0);
	glTranslatef(15 * cos(shared.time), 0, 0);

	//Rita ut objektet från deluppg 1 mha indexlista

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertexArray);
	glColorPointer(3, GL_FLOAT, 0, colorArray);

	glDrawElements(GL_TRIANGLES, 42, GL_UNSIGNED_INT, indexArray);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
}

void drawSphere()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();

	glTranslatef(-10 * cos(shared.time), 5 * sin(shared.time), 0);

	glBindTexture(GL_TEXTURE_2D, shared.earthTexture);
	gluSphere(shared.quadric, 5, 32, 32);

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
}

// Vår egen underfunktion som ritar ut scenen
void drawScene()
{
	// Initiala renderingstillstånd
	glEnable(GL_CULL_FACE);
	glDepthMask(GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPolygonMode(GL_FRONT, GL_FILL);

	// Rita golv och pelare
	drawFloor(shared.floorTexture);
	drawPillars(shared.pillarTexture);

	drawSphere();

	drawPolyObject();
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

	case 'e':
		shared.isOrbit = !shared.isOrbit;
		break;

	case 'r':
		shared.isRoll = !shared.isRoll;
		break;

	case 'w':
		shared.isMovement = !shared.isMovement;
		break;

	case 'q':
		shared.is4View = !shared.is4View;
		break;

	//Förflyttningslägen
	case '1':
		shared.mode = 1;
		break;
	case '2':
		shared.mode = 2;
		break;
	case '3':
		shared.mode = 3;
		break;
	case '4':
		shared.mode = 4;
		break;
	case '5':
		shared.mode = 5;
		break;
	case '6':
		shared.mode = 6;
		break;
	}
}



// GLUT-hanterad funktion som anropas varje gång en tangent släpps upp
void keyboardUp(unsigned char key, int x, int y)
{
	switch(key)
	{
	default:
		break;
	}
}



// GLUT-hanterad funktion som anropas efter att en angiven tid har löpt ut (ofta kallad timer)
void timer(int timeout)
{
	glutTimerFunc(timeout, timer, timeout);   // Vi måste starta om timern varje gång

	if(!shared.pause)
	{
		shared.time += 0.01f;
	}
}



// GLUT-hanterad funktion som anropas en gång för varje bildruta (frame)
void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);   // Vi vill rensa både skärmbuffert och z-buffert

	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	
	//W = 640, H = 480

	if (shared.is4View == true)
	{
		//Rörlig kamera
		glLoadIdentity();
		glViewport(0, 0, 325, 250);
		shared.camera.lookAt();   // Skapar vymatris via kameraklassen
		drawScene();

		//Från sidan
		glLoadIdentity();
		glViewport(325, 220, 325, 250);
		gluLookAt(-60, 0, 0, 0, 0, 0, 0, 1, 0);
		drawScene();

		//Framifrån
		glLoadIdentity();
		glViewport(0, 220, 325, 250);
		gluLookAt(0, 0, 60, 0, 0, 0, 0, 1, 0);
		drawScene();

		//Uppifrån
		glLoadIdentity();
		glViewport(325, 0, 325, 250);
		gluLookAt(0, 60, 0, 0, 0, 0, 1, 0, 0);
		drawScene();
	}
	else
	{
		//Rörlig kamera
		glLoadIdentity();
		glViewport(0, 0, 640, 480);
		shared.camera.lookAt();   // Skapar vymatris via kameraklassen
		drawScene();
	}

	glutSwapBuffers();
}



// GLUT-hanterad funktion som anropas en gång n‰r fönstret öppnas och sedan varje gång fönstret förstoras eller förminskas
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, float(width) / float(height), 0.1f, 100.0f);   // Skapar en projektionsmatris
}



// GLUT-hanterad funktion som anropas när ingen händelse (tangentbord, utritning etc) sker 
void idle()
{
	glutPostRedisplay();
}



// GLUT-hanterad funktion som anropas när muspekaren flyttas
void passiveMotion(int x, int y)
{
	if(shared.mouseWarped)
	{
		shared.mouseWarped = false;
	}
	else
	{
		int centerX = glutGet(GLUT_WINDOW_WIDTH) / 2;
		int centerY = glutGet(GLUT_WINDOW_HEIGHT) / 2;
		float scale = 0.3f;
		float deltaX = float(x - centerX) * scale;
		float deltaY = float(y - centerY) * scale;

		float multiplier = 0.4f;
		
		//Byt mellan rörelse och rotation med W
		if (shared.isMovement == false)
		{
			//Byt mellan roll och icke roll med R
			if (shared.isRoll != true)
			{
				//Byt mellan orbit och tumble med E
				if (shared.isOrbit == true)
				{
					shared.camera.orbitPitch(deltaY * multiplier);
					shared.camera.orbitYaw(deltaX * multiplier);
				}
				else
				{
					shared.camera.tumblePitch(-deltaY * multiplier);
					shared.camera.tumbleYaw(-deltaX * multiplier);
				}
			}
			//Kan inte använda roll rotation och pitch/yaw samtidigt (3 axlar att rotera efter, men endast 2 axlar att röra musen i)
			else
			{
				shared.camera.roll(deltaX * multiplier);
			}
		}
		else
		{
			//Moveposition
			if (shared.mode == 1)
			{
				shared.camera.movePosition(deltaX, deltaY, 0);
			}
			if (shared.mode == 2)
			{
				shared.camera.movePosition(0, 0, deltaY);
			}
			//Movetarget
			if (shared.mode == 3)
			{
				shared.camera.moveTarget(deltaX, -deltaY, 0);
			}
			if (shared.mode == 4)
			{
				//Förflytta kameran och vart kameran ska titta i Z-led för att visa vad som faktiskt händer
				shared.camera.moveTarget(0, 0, deltaY);
				shared.camera.movePosition(0, 0, deltaY);
			}
			//Strafe
			if (shared.mode == 5)
			{
				shared.camera.strafeRight(deltaX);
				shared.camera.strafeUp(-deltaY);
			}
			if (shared.mode == 6)
			{
				shared.camera.strafeForward(deltaY);
			}
		}

		glutWarpPointer(centerX, centerY);
		shared.mouseWarped = true;
	}
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
	
	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
	#ifdef __APPLE__
	CGSetLocalEventsSuppressionInterval(0);
	#endif
	glutPassiveMotionFunc(passiveMotion);

	glutMainLoop();

	return 0;
}
