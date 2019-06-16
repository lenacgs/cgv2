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

extern GLuint skybox[6];

void initVariables();
void initTextures();
void initLights();
void init();

void drawSkybox();