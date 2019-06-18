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
int mouseX, mouseY;

GLuint skybox[6];
GLuint textures[5];

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
	drawEixos();
	
	desenhaEscadas(0);
	desenhaParedePrincipal(0);
	desenhaTelhado(1);
	desenhaChao();
	desenhaInterior();
	desenhaFocosExteriores();
	desenhaAltar();
	drawSkybox();

	glutSwapBuffers();
}

void updatePosition(){
	lookx = obsPx + sens[0] * cos(phi);
	lookz = obsPz - sens[0] * sin(phi);
	looky = obsPy;
	if(obsPx < 100 && obsPx > 25 && obsPz < 165 && obsPz > 125){
		lookz++;
	}
	else if(!(obsPx < 100 && obsPx > 25 && obsPz < 165 && obsPz > 125)){
		lookz--;
	}
}

void keyboardFunction(unsigned char key, int x, int y) {
	switch (key) {
		// MOVEMENT
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
		case 32:
			obsPy += 2;
			updatePosition();
			break;
		case 'r':
		case 'R':
			//usamos 4 estados para impedir que o utilizador feche a meio de abrir ou vice versa
			if(retract==0) // 0- pode fechar
				retract = 2; // 1- sinal para fechar
			else if(retract == 2) //2- pode abrir
				retract = 0; //3- sinal para abrir
			break;
		 // LIGHTS
		/*case '0':
			if(light[0]){
				glDisable(GL_LIGHT7);
				light[0] = 0;
			}
			else{
				glEnable(GL_LIGHT7);
				light[0] = 1;
			}
			break;

		case '1':
			if(light[1]){
				glDisable(GL_LIGHT0);
				light[1] = 0;
			}
			else{
				glEnable(GL_LIGHT0);
				light[1] = 1;
			}
			break;
		case '2':
			if(light[2]){
				glDisable(GL_LIGHT1);
				light[2] = 0;
			}
			else{
				glEnable(GL_LIGHT1);
				light[2] = 1;
			}
			break;
		case '3':
			if(light[3]){
				glDisable(GL_LIGHT2);
				light[3] = 0;
			}
			else{
				glEnable(GL_LIGHT2);
				light[3] = 1;
			}
			break;
		case '4':
			if(light[4]){
				glDisable(GL_LIGHT3);
				light[4] = 0;
			}
			else{
				glEnable(GL_LIGHT3);
				light[4] = 1;
			}
			break; */
		// EXITING
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
