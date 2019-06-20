#include "definitions.h"
#include "RgbImage.h"

RgbImage imag;
Particula particulas[MAX_PARTICULAS];

void initVariables(void) {
	wScreen = glutGet(GLUT_SCREEN_WIDTH);
	hScreen = glutGet(GLUT_SCREEN_HEIGHT);

	obsPx = 130;
	obsPy = 20;
	obsPz = 215;

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

	initParticulas(particulas);
	
}

void initTextures() {
	//skybox bottom
	glGenTextures(1, &skybox[0]);
	glBindTexture(GL_TEXTURE_2D, skybox[0]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
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
		
	//PORTA
	glGenTextures(1, &textures[5]);
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Images/door.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	//TAPETE
	glGenTextures(1, &textures[6]);
	glBindTexture(GL_TEXTURE_2D, textures[6]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Images/tapete.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//fogo
	glGenTextures(1, &textures[7]);
	glBindTexture(GL_TEXTURE_2D, textures[7]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Images/fire.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
}

void initLights() {
	//-------------------------------------------
	GLfloat sunPos[4] = {1000.0, 1000.0, 0.0, 1.0};
	GLfloat sunColor[4] = { 4.0, 4.0, 4.0, 1.0 };
	//-------------------------------------------
	GLfloat luzAltarPos[4] = {410.0, 80.0, 300.0, 1.0};
	//-------------------------------------------
	GLfloat luzDivisaoEsq1Pos[4] = {150.0, 80.0, 400.0, 1.0};
	//-------------------------------------------
	GLfloat luzDivisaoEsq2Pos[4] = {300.0, 80.0, 400.0, 1.0};
	//-------------------------------------------
	GLfloat luzDivisaoDir1Pos[4] = {150.0, 80.0, 200.0, 1.0};
	//-------------------------------------------
	GLfloat luzDivisaoDir2Pos[4] = {300.0, 80.0, 200.0, 1.0};
	//-------------------------------------------
	GLfloat luzExterior1Pos[4] = {610.0, 0.0, 0.0, 1.0};
	GLfloat luzExterior1Dir[3] = {-1.0, 1.0, 1.0};
	//-------------------------------------------
	GLfloat luzExterior2Pos[4] = {610.0, 0.0, 610.0, 1.0};
	GLfloat luzExterior2Dir[3] = {-1.0, 1.0, -1.0};
	//-------------------------------------------
	GLfloat luzCor[4] = {1.0, 1.0, 1.0, 1.0};
	GLfloat luzCorDif[4] = {1, 1, 1, 1.0}; 
	GLfloat luzCorSpec[4] = { 0, 0, 0, 0.0 };
	GLfloat luzInteriorAttCon =1.0;
	GLfloat luzInteriorAttLin =0.1;
	GLfloat luzExteriorAttCon =1.0;
	GLfloat luzExteriorAttLin =0.08;
	//-------------------------------------------
	
	// -------------- LUZ AMBIENTE --------------
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sunColor);
	//-------------------------------------------

	//------------- GL_LIGHT0 - SUN -------------
	glLightfv(GL_LIGHT0, GL_POSITION, sunPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, sunColor);
	//-------------------------------------------
	
	//------------ GL_LIGHT1 - ALTAR ------------
	glLightfv(GL_LIGHT1, GL_POSITION, luzAltarPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, luzCor);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luzCorDif);
	glLightfv(GL_LIGHT1, GL_SPECULAR, luzCorSpec);
	glLightf (GL_LIGHT1, GL_CONSTANT_ATTENUATION, luzInteriorAttCon);
	glLightf (GL_LIGHT1, GL_LINEAR_ATTENUATION, luzInteriorAttLin);
	//-------------------------------------------
	
	//-------- GL_LIGHT2 - DIVISAO ESQ 1 --------
	glLightfv(GL_LIGHT2, GL_POSITION, luzDivisaoEsq1Pos);
	glLightfv(GL_LIGHT2, GL_AMBIENT, luzCor);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, luzCorDif);
	glLightfv(GL_LIGHT2, GL_SPECULAR, luzCorSpec);
	glLightf (GL_LIGHT2, GL_CONSTANT_ATTENUATION, luzInteriorAttCon);
	glLightf (GL_LIGHT2, GL_LINEAR_ATTENUATION, luzInteriorAttLin);
	//-------------------------------------------
	
	//-------- GL_LIGHT3 - DIVISAO ESQ 2 --------
	glLightfv(GL_LIGHT3, GL_POSITION, luzDivisaoEsq2Pos);
	glLightfv(GL_LIGHT3, GL_AMBIENT, luzCor);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, luzCorDif);
	glLightfv(GL_LIGHT3, GL_SPECULAR, luzCorSpec);
	glLightf (GL_LIGHT3, GL_CONSTANT_ATTENUATION, luzInteriorAttCon);
	glLightf (GL_LIGHT3, GL_LINEAR_ATTENUATION, luzInteriorAttLin);
	//-------------------------------------------
	
	//-------- GL_LIGHT4 - DIVISAO DIR 1 --------
	glLightfv(GL_LIGHT4, GL_POSITION, luzDivisaoDir1Pos);
	glLightfv(GL_LIGHT4, GL_AMBIENT, luzCor);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, luzCorDif);
	glLightfv(GL_LIGHT4, GL_SPECULAR, luzCorSpec);
	glLightf (GL_LIGHT4, GL_CONSTANT_ATTENUATION, luzInteriorAttCon);
	glLightf (GL_LIGHT4, GL_LINEAR_ATTENUATION, luzInteriorAttLin);
	//-------------------------------------------
	
	//-------- GL_LIGHT5 - DIVISAO DIR 2 --------
	glLightfv(GL_LIGHT5, GL_POSITION, luzDivisaoDir2Pos);
	glLightfv(GL_LIGHT5, GL_AMBIENT, luzCor);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, luzCorDif);
	glLightfv(GL_LIGHT5, GL_SPECULAR, luzCorSpec);
	glLightf (GL_LIGHT5, GL_CONSTANT_ATTENUATION, luzInteriorAttCon);
	glLightf (GL_LIGHT5, GL_LINEAR_ATTENUATION, luzInteriorAttLin);
	//-------------------------------------------
	
	// --------- GL_LIGHT6 - EXTERIOR 1 ---------
	glLightfv(GL_LIGHT6, GL_POSITION, luzExterior1Pos);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, luzExterior1Dir);
	glLightfv(GL_LIGHT6, GL_AMBIENT, luzCor);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, luzCorDif);
	glLightfv(GL_LIGHT6, GL_SPECULAR, luzCorSpec);
	glLightf (GL_LIGHT6, GL_CONSTANT_ATTENUATION, luzExteriorAttCon);
	glLightf (GL_LIGHT6, GL_LINEAR_ATTENUATION, luzExteriorAttLin);
	//-------------------------------------------
	
	// --------- GL_LIGHT7 - EXTERIOR 2 ---------
	glLightfv(GL_LIGHT7, GL_POSITION, luzExterior2Pos);
	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, luzExterior2Dir);
	glLightfv(GL_LIGHT7, GL_AMBIENT, luzCor);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, luzCorDif);
	glLightfv(GL_LIGHT7, GL_SPECULAR, luzCorSpec);
	glLightf (GL_LIGHT7, GL_CONSTANT_ATTENUATION, luzExteriorAttCon);
	glLightf (GL_LIGHT7, GL_LINEAR_ATTENUATION, luzExteriorAttLin);
	//-------------------------------------------
	
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
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);


	glEnable(GL_DEPTH_TEST);

	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	initLights();
	initTextures();
}
