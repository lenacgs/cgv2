#define DEBUG
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <windows.h>
#endif

#define PI	3.14159265359

extern GLint wScreen, hScreen;
extern GLfloat obsPx, obsPy, obsPz;
extern GLfloat lookx, looky, lookz;
extern GLfloat tetha, phi;
extern GLfloat angZoom;
extern int mouseX, mouseY;
extern GLfloat sens[2];
extern bool lights1;
extern bool lights2;
extern GLint retract;
extern GLfloat fogColor[];

extern GLuint skybox[6];
extern GLuint textures[7];

void initVariables();
void initTextures();
void initLights();
void init();

void drawSkybox();
void desenhaQuadrado(GLfloat tam, GLfloat r, GLfloat g, GLfloat b, GLint text, GLint lado, GLint tipo);
void desenhaDegrau(GLfloat altura, GLfloat comprimento, GLfloat profundidade, GLint text, GLint tipo);
void desenhaEscadas(GLint text);
void drawEixos();
void desenhaParedePrincipal();
void desenhaTelhado(GLint text);
void desenhaParede(GLfloat x, GLfloat y, GLfloat z, GLint tipo);
void desenhaInterior();
void desenhaPorta();
void desenhaJanela();
void desenhaLampada (bool flag, bool flag2);
void desenhaFocosExteriores();
void desenhaLuzesInterior();
void desenhaAltar();
void desenhaChao();
void desenhaTapete();
void drawFog();
void desenhaLareira();
