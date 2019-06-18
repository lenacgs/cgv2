#include "definitions.h"
#include "RgbImage.h"

RgbImage imag;

void initVariables(void) {
	wScreen = glutGet(GLUT_SCREEN_WIDTH);
	hScreen = glutGet(GLUT_SCREEN_HEIGHT);

	obsPx = 400;
	obsPy = 20;
	obsPz = 300;

	lookx = 300;
	looky = 0;
	lookz = 100;

	tetha = 3;
	phi = (GLfloat)PI/2;
	
	angZoom = 90;
	
	mouseX = wScreen/2;
	mouseY = hScreen/2;

	sens[0] = 2.5;
	sens[1] = (GLfloat) 0.025;
}

void initTextures() {
	//skybox bottom
	glGenTextures(1, &skybox[0]);
	glBindTexture(GL_TEXTURE_2D, skybox[0]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	imag.LoadBmpFile("Images/skybox/floor.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//skybox top
	glGenTextures(1, &skybox[1]);
	glBindTexture(GL_TEXTURE_2D, skybox[1]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	imag.LoadBmpFile("Images/skybox/sky.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//skybox right
	glGenTextures(1, &skybox[2]);
	glBindTexture(GL_TEXTURE_2D, skybox[2]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	imag.LoadBmpFile("Images/skybox/right.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//skybox left
	glGenTextures(1, &skybox[3]);
	glBindTexture(GL_TEXTURE_2D, skybox[3]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	imag.LoadBmpFile("Images/skybox/left.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//skybox front
	glGenTextures(1, &skybox[4]);
	glBindTexture(GL_TEXTURE_2D, skybox[4]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	imag.LoadBmpFile("Images/skybox/front.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//skybox back
	glGenTextures(1, &skybox[5]);
	glBindTexture(GL_TEXTURE_2D, skybox[5]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	imag.LoadBmpFile("Images/skybox/back.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	//pedra
	glGenTextures(1, &textures[0]);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Images/rock.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	//tijolo
	glGenTextures(1, &textures[1]);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Images/brick.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	//madeira chao
	glGenTextures(1, &textures[2]);
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Images/wood.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
	//altar
	glGenTextures(1, &textures[3]);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Images/altar.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
	//20 a CG
	glGenTextures(1, &textures[4]);
	glBindTexture(GL_TEXTURE_2D, textures[4]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Images/20.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
}

void initLights() {
	GLfloat sunPos[4] = {1000.0, 1000.0, 0.0, 1.0};
	GLfloat sunColor[4] = { 1.0, 1.0, 1.0, 1.0 };
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sunColor);

	// GL_LIGHT0 - SUN
	glLightfv(GL_LIGHT0, GL_POSITION, sunPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, sunColor);
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glShadeModel(GL_SMOOTH);
	//glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glFrontFace(GL_CCW);

	glEnable(GL_NORMALIZE);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//glEnable(GL_COLOR_MATERIAL);
/*
	if(light[1])
		glEnable(GL_LIGHT0);
	if(light[2])
		glEnable(GL_LIGHT1);
	if(light[3])
		glEnable(GL_LIGHT2);
	if(light[4])
		glEnable(GL_LIGHT3);
	if(fog)
		glEnable(GL_FOG);
 */

	glEnable(GL_DEPTH_TEST);

	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	initLights();
	initTextures();
}
