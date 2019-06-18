#define DEBUG
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <GL/glut.h>


#define PI	3.14159265359

extern GLint wScreen, hScreen;
extern GLfloat obsPx, obsPy, obsPz;
extern GLfloat lookx, looky, lookz;
extern GLfloat tetha, phi;
extern GLfloat angZoom;
extern int mouseX, mouseY;
extern GLfloat sens[2];
extern GLint retract;

extern GLuint skybox[6];
extern GLuint textures[5];

void initVariables();
void initTextures();
void initLights();
void init();

void drawSkybox();
void desenhaQuadrado(GLfloat tam, GLfloat r, GLfloat g, GLfloat b, GLint text, GLint lado, GLint tipo);
void desenhaDegrau(GLfloat altura, GLfloat comprimento, GLfloat profundidade, GLint text, GLint tipo);
void desenhaEscadas(GLint text);
void drawEixos();
void desenhaParedePrincipal(GLint text);
void desenhaTelhado(GLint text);
void desenhaParede(GLfloat x, GLfloat y, GLfloat z);
void desenhaInterior();
void desenhaLampada (bool flag, bool flag2);
void desenhaFocosExteriores();
void desenhaAltar();
void desenhaChao();
