#include "definitions.h"

using namespace std;

//variable declaration
GLint wScreen, hScreen;
GLint retract=0;
GLfloat obsPx, obsPy, obsPz;
GLfloat lookx, looky, lookz;
GLfloat tetha, phi;
GLfloat angZoom;
GLfloat sens[2];
GLfloat Irotate;
bool fog;
GLfloat fogColor[] = { 0.3, 0.3, 0.3, 1 };
bool lights1, lights2;
int mouseX, mouseY;

GLuint skybox[6];
GLuint textures[9];

void drawFog() {
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.0005);
}

void drawScene() {
	// drawEixos();
	desenhaLareira();
	desenhaAltar(3,2,true);
	desenhaEscadas(0);
	desenhaTelhado(1);
	desenhaChao();
	desenhaInterior();
	desenhaFocosExteriores();
	desenhaLuzesInterior();
	drawSkybox();
	desenhaAltarAgua();
	drawFog();
	desenhaCama();
	
	desenhaParedePrincipal();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glViewport(0, 0, wScreen, hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angZoom, (float)wScreen / hScreen, 0.1, 5000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsPx, obsPy, obsPz, lookx, looky, lookz, 0, 1, 0);
	glClearStencil(0);

	initLights();

	drawMirror();
	
	drawScene();
	glutSwapBuffers();
}

void updatePosition(){
	lookx = obsPx + sens[0] * cos(phi);
	lookz = obsPz - sens[0] * sin(phi);

	printf("obsPx = %f\tobsPy = %f\tobsPz = %f\n", obsPx, obsPy, obsPz);
}

void keyboardFunction(unsigned char key, int x, int y) {
	switch (key) {
		// MOVIMENTO
		case 'w':
		case 'W':
			obsPx += sens[0] * cos(phi);
			obsPz -= sens[0] * sin(phi);
			updatePosition();
			break;
		case 's':
		case 'S':
			obsPx -= sens[0] * cos(phi);
			obsPz += sens[0] * sin(phi);
			updatePosition();
			break;
		case 'a':
		case 'A':
			obsPx += sens[0] * sin(-phi);
			obsPz -= sens[0] * cos(-phi);
			updatePosition();
			break;
		case 'd':
		case 'D':
			obsPx -= sens[0] * sin(-phi);
			obsPz += sens[0] * cos(-phi);
			updatePosition();
			break;
		
		// RETRAI / EXPANDE ESCADAS
		case 'r':
		case 'R':
			//usamos 4 estados para impedir que o utilizador feche a meio de abrir ou vice versa
			if(retract==0) // 0- pode fechar
				retract = 2; // 1- sinal para fechar
			else if(retract == 2) //2- pode abrir
				retract = 0; //3- sinal para abrir
			break;
			
		// LUZES
		
		case 'l':
		case 'L':
			lights1=!lights1;
			if(lights1){
				glEnable(GL_LIGHT1);
				glEnable(GL_LIGHT2);
				glEnable(GL_LIGHT3);
				glEnable(GL_LIGHT4);
				glEnable(GL_LIGHT5);
				
			}
			else{
				glDisable(GL_LIGHT1);
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT3);
				glDisable(GL_LIGHT4);
				glDisable(GL_LIGHT5);
				
			}
			break;
		case 'p':
		case 'P':
			lights2=!lights2;
			if(lights2){
				glEnable(GL_LIGHT6);
				glEnable(GL_LIGHT7);
			}
			else{
				glDisable(GL_LIGHT6);
				glDisable(GL_LIGHT7);
			}
			break;
			
		// NEVOEIRO
		case 'f':
		case 'F':
			fog=!fog;
			if(fog)
				glEnable(GL_FOG);
			else
				glDisable(GL_FOG);
			break;
			
		// EXIT
		case 27:
			exit(0);
			break;
	}
	glutPostRedisplay();
}

void mouseFunction(int x, int y) {
	
	if(x >= wScreen - 1 || x == 0 || y >= hScreen - 1 || y == 0) {
		mouseX = wScreen / 2;
		mouseY = hScreen / 2;
		glutWarpPointer(wScreen / 2, hScreen / 2);
	} else {
		phi -= sens[1] * (x - mouseX);
		looky -= sens[1] * (y - mouseY);
		mouseX = x;
		mouseY = y;
		updatePosition();
	}
}

void idle(void) {
	Irotate++;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	
	initVariables();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(wScreen, hScreen);

	glutCreateWindow("Movement: W A S D;  LookAt: Mouse Movement;  Lights: 1 - 3;");

	glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);

	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardFunction);
	glutPassiveMotionFunc(mouseFunction);
	glutIdleFunc(idle);
	
	glutMainLoop();
	return 0;
}
