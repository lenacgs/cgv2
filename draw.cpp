#include "definitions.h"
#include "materials.h"

GLint nSteps=10;
GLfloat altura=5.0, comprimento=200.0, profundidade=10.0;
GLfloat coordParede1[]={300.0,0,0.0}, coordParede2[]={0.0,0,300.0}, coordParede3[]={300.0,0,600.0}, coordParede4[]={-300.0,0,0.0};

void drawEixos()
{	
	//Eixo X
	glColor4f(255,0,0,1);
	glBegin(GL_LINES);
		glVertex3i( 0, 0, 0);
		glVertex3i(80, 0, 0);
	glEnd();
	//Eixo Y
	glColor4f(0,255,0,1);
	glBegin(GL_LINES);
		glVertex3i(0,  0, 0);
		glVertex3i(0, 80, 0);
	glEnd();
	//Eixo Z
	glColor4f(0,0,255,1);
	glBegin(GL_LINES);
		glVertex3i( 0, 0, 0);
		glVertex3i( 0, 0,80);
	glEnd();

}

void desenhaQuadrado(GLfloat tam, GLfloat r, GLfloat g, GLfloat b){
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
		glVertex2f(0-tam , 0-tam );
		glVertex2f(0-tam , 0+tam );
		glVertex2f(0+tam , 0+tam );
		glVertex2f(0+tam , 0-tam );
	glEnd();
}

void desenhaDegrau(GLfloat altura, GLfloat comprimento, GLfloat profundidade) {

	glPushMatrix(); //face inferior
		glTranslatef(0.0, -altura, profundidade);
		glRotatef(90, 1.0, 0.0, 0.0); //rotacao de 90 graus sobre o eixo xx
		glScalef(comprimento, profundidade, profundidade);
		desenhaQuadrado(1.0, 255, 255, 0);
	glPopMatrix();
	glPushMatrix(); //face superior
		glTranslatef(0.0, altura, profundidade);
		glRotatef(90, 1.0, 0.0, 0.0); //rotacao de 90 graus sobre o eixo xx
		glScalef(comprimento, profundidade, profundidade);
		desenhaQuadrado(1.0, 255, 165, 0); //quadrado amarelo
	glPopMatrix();
	glPushMatrix(); //face traseira
		glTranslatef(0.0, 0.0, profundidade*2);
		glScalef(comprimento, altura, 1);
		desenhaQuadrado(1.0, 0.0, 0.0, 1.0); //quadrado azul
	glPopMatrix(); 
	glPushMatrix(); //faces laterais
		glTranslatef(-comprimento, 0.0, profundidade), //esquerda
		glRotatef(90.0, 0.0, 1.0, 0.0); //rotacao de 90 graus sobre o eixo yy
		glScalef(profundidade, altura, 1);
		desenhaQuadrado(1.0, 0.0, 255, 0.0); //quadrado verde
	glPopMatrix();
	glPushMatrix(); 
		glTranslatef(comprimento, 0.0, profundidade), //direita
		glRotatef(90.0, 0.0, 1.0, 0.0); //rotacao de 90 graus sobre o eixo yy
		glScalef(profundidade, altura, 1);
		desenhaQuadrado(1.0, 0.0, 1.0, 0.0); //quadrado verde
	glPopMatrix();
	glPushMatrix(); //face frontal
		glScalef(comprimento, altura, profundidade);
		desenhaQuadrado(1.0, 1.0, 0.0, 0.0); //quadrado vermelho
	glPopMatrix();
}

void desenhaEscadas(){
	int i;
	GLfloat altura1, altura2, altura3, altura4;
	GLfloat comprimento1, comprimento2, comprimento3, comprimento4;
	GLfloat profundidade1, profundidade2, profundidade3, profundidade4;
	GLfloat posX1, posX2, posX3, posX4;
	GLfloat posY1, posY2, posY3, posY4;
	GLfloat tempScale;
	GLfloat steps=nSteps;
	
	//parede 1
	for (i=0; i<nSteps; i++) {
		glPushMatrix();
			glTranslatef(coordParede1[0],altura*i*2,coordParede1[2]+profundidade*i);
			glScalef((comprimento+(steps-i)*profundidade)/comprimento,1,(steps-i+1)/2);
			desenhaDegrau(altura, comprimento, profundidade);
		glPopMatrix();
	}
	//parede 2
	tempScale=nSteps/2;
	for (i=0; i<nSteps; i++) {
		glPushMatrix();
			glTranslatef(coordParede2[0]+profundidade*i,altura*i*2,coordParede2[2]);
			glRotatef(90,0,1,0);
			glScalef((comprimento+(steps-i)*profundidade)/comprimento,1,(steps-i+1)/2);
			desenhaDegrau(altura, comprimento, profundidade);
		glPopMatrix();
		tempScale=tempScale-1;
	}
	//parede 3
	for (i=0; i<nSteps; i++) {
		glPushMatrix();
			glTranslatef(coordParede3[0],altura*i*2,coordParede3[2]-profundidade*i);
			glRotatef(180,0,1,0);
			glScalef((comprimento+(steps-i)*profundidade)/comprimento,1,(steps-i+1)/2);
			desenhaDegrau(altura, comprimento, profundidade);
		glPopMatrix();
	}
	/*for (i=0; i<nSteps; i++) {
		glPushMatrix();
			glTranslatef(coordParede4[0],coordParede4[1]*(i+1)*2,coordParede4[2]+profundidade*i);
			desenhaDegrau(altura, comprimento, profundidade);
		glPopMatrix();
	}*/
}


void drawSkybox() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, whiteDif);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, nullColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, nullColor);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, skybox[0]);
	glPushMatrix();
		glBegin(GL_QUADS);
			//World Floor
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.055f, 0.055f); glVertex3f(-2000, -1, -2000);
			glTexCoord2f(0.055f, 1.0f); glVertex3f(-2000, -1, 2000);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(2000, -1, 2000);
			glTexCoord2f(1.0f, 0.055f); glVertex3f(2000, -1, -2000);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);


	//World Top
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, skybox[1]);
	glPushMatrix();
	glBegin(GL_QUADS);
		glNormal3i(0, -1, 0);
		glTexCoord2f(0.055f, 1.0f); glVertex3f(-2000, 2000, -2000);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(2000, 2000, -2000);
		glTexCoord2f(1.0f, 0.055f); glVertex3f(2000, 2000, 2000);
		glTexCoord2f(0.055f, 0.055f); glVertex3f(-2000, 2000, 2000);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//World Right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, skybox[2]);
	glPushMatrix();
		glBegin(GL_QUADS);

		glNormal3i(0, 0, -1);
		glTexCoord2f(1.0f, 0.055f); glVertex3f(2000, -1, 2000);
		glTexCoord2f(0.055f, 0.055f); glVertex3f(-2000, -1, 2000);
		glTexCoord2f(0.055f, 1.0f); glVertex3f(-2000, 2000, 2000);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(2000, 2000, 2000);

		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//World Left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, skybox[3]);
	glPushMatrix();
		glBegin(GL_QUADS);

		glNormal3i(0, 0, 1);
		glTexCoord2f(1.0f, 0.055f); glVertex3f(-2000, -1, -2000);
		glTexCoord2f(0.055f, 0.055f); glVertex3f(2000, -1, -2000);
		glTexCoord2f(0.055f, 1.0f); glVertex3f(2000, 2000, -2000);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2000, 2000, -2000);

		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	//World Front
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, skybox[4]);
	glPushMatrix();
		glBegin(GL_QUADS);

		glNormal3i(-1, 0, 0);
		glTexCoord2f(1.0f, 0.055f); glVertex3f(2000, -1, -2000);
		glTexCoord2f(0.055f, 0.055f); glVertex3f(2000, -1, 2000);
		glTexCoord2f(0.055f, 1.0f); glVertex3f(2000, 2000, 2000);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(2000, 2000, -2000);

		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	//World Back
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, skybox[5]);
	glPushMatrix();
		glBegin(GL_QUADS);

		glNormal3i(1, 0, 0);
		glTexCoord2f(0.055f, 0.055f); glVertex3f(-2000, -1, -2000);
		glTexCoord2f(0.055f, 1.0f); glVertex3f(-2000, 2000, -2000);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2000, 2000, 2000);
		glTexCoord2f(1.0f, 0.055f); glVertex3f(-2000, -1, 2000);

		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

