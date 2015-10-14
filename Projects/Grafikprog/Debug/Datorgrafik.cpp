#include <stdlib.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif

bool isFill = true;
bool rotateB4Translate = true;
bool rotateCamera = true;
bool drawVertex = true;

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

#pragma endregion ...

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

// Data som delas mellan programmets olika delar
struct Shared
{
	float time;
	bool pause;
};

struct Shared shared;

// Vår egen underfunktion som initierar det som behövs innan renderingen börjar
void initialize()
{
	shared.time = 0;
	shared.pause = false;
}

void drawFloor()
{
	//Bestämmer hur renderade objekt ska rasteriseras, första parametern bestämmer från vilken sida, andra bestämmer vilken sorts rasterisering
	//I detta fall ska alla polygoner rasteriseras med hela linjer både bak-och framifrån
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_LINE);

	//Sätter färgen på alla renderade objekt under denna rad till den specifierade färgen i RBG, om man sätter en ny färg efter denna byts alla efter den raden till den färgen
	//I detta fall sätter vi färgen på alla objekt under denna rad tills nästa färgbyte till 0% röd, 100% grön och 0% blå
	glColor3f(0, 1, 0);

	//Skapar en primitiv av givna vertexer mellan glBegin(Primitiv); och glEnd();
	//I detta fall skapas en "Quad" eller en kvadrat/rektangel mellan de fyra givna vertexpunkterna tills glEnd(); anges
	glBegin(GL_QUADS);
	//GRUND

	//Bestämmer vilken shader modellen ska använda
	glShadeModel(GL_SMOOTH);

	//Används mellan glBegin(Primitiv); och glEnd(); för att specifiera vart vertexpunkter finns i utrymmet som programmet skapar
	//glVertex3f tar 3 värden som alla är av typen float (x, y z)
	//glVertex2f tar också floatvärden men kan bara ha 2 istället för 3 (x, y). Det finns också vertex som tar interger värden istället (glVertex3i osv...)
	//I detta fall skapas 4 vertexpunkter av typen 3f som tillsammans skapar en kvadrat/rektangel mha glBegin();
	glVertex3f(10, -10, 10);
	glVertex3f(10, -10, -10);
	glVertex3f(-10, -10, -10);
	glVertex3f(-10, -10, 10);

	glEnd();
}

// Vår egen underfunktion som ritar ut ett golv
void drawObject()
{
	//Bestämmer vilket polygonmode som ska användas
	if (isFill)
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_FILL);
	}
	else
	{
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
	}
#pragma region ObjectInfo
	//Grund - 1
	glBegin(GL_TRIANGLES);

	glColor3f(0, 0, 0);
	glVertex3f(-7, -5, -7);

	glColor3f(0.1, 0.8, 0);
	glVertex3f(7, -5, -7);

	glColor3f(1, 0, 0);
	glVertex3f(7, -5, 7);

	//Grund - 2
	glColor3f(1, 0, 0);
	glVertex3f(7, -5, 7);

	glColor3f(0, 1, 0);
	glVertex3f(-7, -5, 7);

	glColor3f(0, 0, 0);
	glVertex3f(-7, -5, -7);

	glBegin(GL_TRIANGLES);
	//VÄGGAR

	//Vägg1 - 1
	glColor3f(0, 0, 1);
	glVertex3f(7, 0, 7);

	glColor3f(1, 0, 0);
	glVertex3f(7, -5, 7);

	glColor3f(0.1, 0.8, 0);
	glVertex3f(7, -5, -7);

	//Vägg1 - 2
	glColor3f(0.1, 0.8, 0);
	glVertex3f(7, -5, -7);

	glColor3f(1, 0, 0);
	glVertex3f(7, 0, -7);

	glColor3f(0, 0, 1);
	glVertex3f(7, 0, 7);

	//Vägg2 - 1
	glColor3f(1, 0, 0);
	glVertex3f(7, 0, -7);

	glColor3f(0.1, 0.8, 0);
	glVertex3f(7, -5, -7);

	glColor3f(0, 0, 0);
	glVertex3f(-7, -5, -7);

	//Vägg2 - 2
	glColor3f(0, 0, 0);
	glVertex3f(-7, -5, -7);

	glColor3f(0, 1, 0);
	glVertex3f(-7, 0, -7);

	glColor3f(1, 0, 0);
	glVertex3f(7, 0, -7);

	//Vägg3 - 1
	glColor3f(0, 1, 0);
	glVertex3f(-7, 0, -7);

	glColor3f(0, 0, 0);
	glVertex3f(-7, -5, -7);

	glColor3f(0, 1, 0);
	glVertex3f(-7, -5, 7);

	//Vägg3 - 2
	glColor3f(0, 1, 0);
	glVertex3f(-7, -5, 7);

	glColor3f(1, 1, 1);
	glVertex3f(-7, 0, 7);

	glColor3f(0, 1, 0);
	glVertex3f(-7, 0, -7);

	//Vägg4 - 1
	glColor3f(1, 1, 1);
	glVertex3f(-7, 0, 7);

	glColor3f(0, 1, 0);
	glVertex3f(-7, -5, 7);

	glColor3f(1, 0, 0);
	glVertex3f(7, -5, 7);

	//Vägg4 - 2
	glColor3f(0, 0, 1);
	glVertex3f(7, 0, 7);

	glColor3f(1, 1, 1);
	glVertex3f(-7, 0, 7);

	glColor3f(1, 0, 0);
	glVertex3f(7, -5, 7);

	glEnd();

	glBegin(GL_TRIANGLES);
	//TOPPTRIANGLAR

	//Triangel 1
	glColor3f(1, 0, 0);
	glVertex3f(7, 0, -7);

	glColor3f(0, 1, 0);
	glVertex3f(-7, 0, -7);

	glColor3f(1, 0, 1);
	glVertex3f(0, 10, 0);

	//Triangel 2
	glColor3f(0, 1, 0);
	glVertex3f(-7, 0, -7);

	glColor3f(1, 1, 1);
	glVertex3f(-7, 0, 7);

	glColor3f(1, 0, 1);
	glVertex3f(0, 10, 0);

	//Triangel 3
	glColor3f(1, 1, 1);
	glVertex3f(-7, 0, 7);

	glColor3f(0, 0, 1);
	glVertex3f(7, 0, 7);

	glColor3f(1, 0, 1);
	glVertex3f(0, 10, 0);

	//Triangel 4
	glColor3f(0, 0, 1);
	glVertex3f(7, 0, 7);

	glColor3f(1, 0, 0);
	glVertex3f(7, 0, -7);

	glColor3f(1, 0, 1);
	glVertex3f(0, 10, 0);

	glEnd();
#pragma endregion ..
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

	case 'a':
		//Kollar om det givna GL argumentet är aktiverat, ger tillbaka true om det stämmer, annars false
		//I detta fall kollar den om backface culling är igång och sedan ger tillbaka true/false
		if (glIsEnabled(GL_CULL_FACE))
		{
			//Avaktiverar det givna GL argumentet
			//I detta fall stänger det av backface culling om det redan är igång
			glDisable(GL_CULL_FACE);
		}
		else
		{
			//Aktiverar det givna GL argumenetet
			//I detta fall aktiverar den backface culling
			glEnable(GL_CULL_FACE);
		}
		break;

	case 's':
		//Toggla av/på fill rasterisering
		isFill = !isFill;

		break;

	case 'd':
		//Toggla av/på rotation före translation
		rotateB4Translate = !rotateB4Translate;

		break;

	case 'f':

		drawVertex = !drawVertex;

		break;

	case 'e':

		rotateCamera = !rotateCamera;

		break;
	}
}

void drawVList()
{
	if (isFill)
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_FILL);
	}
	else
	{
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
	}

	//Tillåter openGL att arbeta ifrån klient-sidan, dessa funktioner är vanligtvis inte tillgängliga och kan användas mellan glEnable tills glDisable
	//Dessa funktioner tar ett argument som beskriver vilka sorts funktioner som kommer kunna användas
	//I detta fall Tillåter vi GL_VERTEX samt GL_COLOR arrays att användas när programmet ska rita ut objekt
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//Tillåter programmet att läsa av en array av koordinater när man ska rita ut objekt
	//Första argumentet bestämmer hur många koordinater funktionen ska läsa av per index i arrayen - i detta fall 3 per index
	//Andra argumenetet bestämmer vilken datatyp som ska läsas av, i detta fall GL_FLOAT
	//Tredje argumentet bestämmer byte offset mellan koordinater, om detta värde är 0 läser funktionen koordinaterna som om dom är inpackade på varandra i arrayen
	//Fjärde argumentet behöver en pekare till första index värdet i arrayen som man vill rita ut
	glVertexPointer(3, GL_FLOAT, 0, vertexArray);

	//Liknar glVertexPointer fast läser av indexvärden till färger istället för koordinater
	//Alla argument till denna funktion är av samma typ som till glVertexPointer
	glColorPointer(3, GL_FLOAT, 0, colorArray);

	//Ritar primitiver baserat på tillgängliga arrays
	//Första argumentet bestämmer vilka sorts primitiver som funktionen ska rita ut
	//Andra argumentet bestämmer från vilket index i dessa arrays som funktionen ska börja
	//Tredje argumentet bestämmer hur många hörn som programmet ska rita ut
	glDrawElements(GL_TRIANGLES, 42, GL_UNSIGNED_INT, indexArray);

	//Stänger av klientbaserade funktioner
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

// GLUT-hanterad funktion som anropas efter att en angiven tid har löpt ut (ofta kallad timer)
void timer(int timeout)
{
	glutTimerFunc(timeout, timer, timeout);   // Vi måste starta om timern varje gång

	if(!shared.pause)
		shared.time += 0.01f;
}



// GLUT-hanterad funktion som anropas en gång för varje bildruta (frame)
void display()
{
	//Bestämmer vilken färg som skärmen ska sättas till när glCLear(); kallas
	//I detta fall sätts skärmens färg till svart med 100% alfavärde
	glClearColor(0, 0, 0, 1);

	//Rensar färgbufferten och djupledsbufferten så att färger och objekt skapade i utrymmet inte ska ritas över nästa frame
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);   // Vi vill rensa både skärmbufferten och z-bufferten

	//Utsätter alla objekt som har mindre än största djupet för "depth test"
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	//Bestämmer vilken sorts matris som ska användas för matrisoperationer
	//I detta fall vill vi att en modell ska visas
	glMatrixMode(GL_MODELVIEW);

	//Laddar identitetsmatrisen - en nollställare som man kan multiplicera in i sin nuvarande matris:
	//Den säger att x = x, y = y, och z = z som ger en resulterande matris
	glLoadIdentity();

	if (rotateCamera)
	{
		gluLookAt(cos(shared.time) * 40, 10, sin(shared.time) * 40, 0, 0, 0, 0, 1, 0);   // Roterar kameran kring origo genom att skapa en ny vymatris varje bildruta
	}
	else
	{
		gluLookAt(0, 10, 40, 0, 0, 0, 0, 1, 0); //Kameran kollar direkt mot objektet och rör sig inte
	}

	drawFloor();

	if (!rotateCamera)
	{
		//Bestämmer vilken sorts rörelse objektet ska ha
		if (rotateB4Translate)
		{
			//Sätter rotationen på en matris, första parametern bestämmer vinkel, andra bestämmer vilka axlar som ska rotera
			glRotatef(shared.time * 100, 1, 0, 0);
			glRotatef(shared.time * 50, 0, 0, 1);

			glTranslatef(0, 0, cos(shared.time) * 20);
		}
		else
		{
			glTranslatef(0, 0, cos(shared.time) * 20);

			glRotatef(shared.time * 100, 1, 0, 0);
			glRotatef(shared.time * 50, 0, 0, 1);
		}
	}

	if (drawVertex)
	{
		drawVList();
	}
	else
	{
		drawObject();
	}

	glutSwapBuffers();
}



// GLUT-hanterad funktion som anropas en gång när fönstret öppnas och sedan varje gång fönstret förstoras eller förminskas
void reshape(int width, int height)
{
	//Bestämmer hur mycket kameran kommer visa, de första två parametrarna ger storlek på rektangeln i visningen, höjd och bredd bestämmer hur mycket kameran kommer kunna visa
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
	glutMainLoop();

	return 0;
}
