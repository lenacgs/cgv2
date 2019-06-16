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

extern GLuint skybox[6];

void initVariables();
void initTextures();
void initLights();
void init();

void drawSkybox();
void desenhaQuadrado(GLfloat tam, GLfloat r, GLfloat g, GLfloat b);
void desenhaDegrau(GLfloat altura, GLfloat comprimento, GLfloat profundidade);
void desenhaEscadas();
void drawEixos();
