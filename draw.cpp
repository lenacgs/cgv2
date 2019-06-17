#include "definitions.h"
#include "materials.h"

GLfloat posEscada1, posEscada2, posEscada3;
GLfloat alturaTelhado = 10.0;
GLint nSteps=10;
GLint move = 0;
GLfloat altura=5.0, comprimento=200.0, profundidade=10.0;
GLfloat coordParede1[]={300.0,0,0.0}, coordParede2[]={0.0,0,300.0}, coordParede3[]={300.0,0,600.0}, coordParede4[]={510.0,0,300.0};
GLfloat coordTelhado1[]={300.0,100.0,100.0}, coordTelhado2[]={100.0,100,300.0}, coordTelhado3[]={300.0,100,500.0}, coordTelhado4[]={500.0,100,300.0};

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
	int i,j;
	GLfloat steps=nSteps;
	
	
	if(retract==0){ //aberto
		//parede 1
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede1[0],altura*i*2,coordParede1[2]+profundidade*i);
				glScalef(1+(((steps-i)*profundidade)/comprimento),1,(steps-i+1)/2);
				desenhaDegrau(altura, comprimento, profundidade);
			glPopMatrix();
		}
		posEscada1=coordParede1[2]+profundidade*(nSteps-1);
		//parede 2
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede2[0]+profundidade*i,altura*i*2,coordParede2[2]);
				glRotatef(90,0,1,0);
				glScalef(1+(((steps-i)*profundidade)/comprimento),1,(steps-i+1)/2);
				desenhaDegrau(altura, comprimento, profundidade);
			glPopMatrix();
		}
		posEscada2=coordParede2[0]+profundidade*(nSteps-1);
		//parede 3
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede3[0],altura*i*2,coordParede3[2]-profundidade*i);
				glRotatef(180,0,1,0);
				glScalef(1+(((steps-i)*profundidade)/comprimento),1,(steps-i+1)/2);
				desenhaDegrau(altura, comprimento, profundidade);
			glPopMatrix();
		}
		posEscada3=coordParede3[2]-profundidade*(nSteps-1);
	}
	else if (retract==1){ //fecha
		//parede 1
		if(move<1000){
			for (i=0; i<nSteps; i++) {
				glPushMatrix();
					glTranslatef(coordParede1[0],altura*i*2,coordParede1[2]+(move/1000)*(profundidade*(nSteps-1)));
					glScalef(1+((1000-move)/1000)*(((steps-i)*profundidade)/comprimento),1,(steps-i+1)/2);
					desenhaDegrau(altura, comprimento, profundidade);
				glPopMatrix();
				printf("move: %d\n",move);
			}
		}
		else
			retract = 2;
		move++;
	}
	else if (retract == 3){ //abre
		for (i=0; i<nSteps; i++) {
			if(move>=0){
				
			}
		}
		retract = 0;
	}
	else if (retract == 2){ //fechado
		//parede 1
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede1[0],altura*i*2,coordParede1[2]+profundidade*(nSteps-1));
				desenhaDegrau(altura, comprimento, profundidade);
			glPopMatrix();
		}
		//parede 2
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede2[0]+profundidade*(nSteps-1),altura*i*2,coordParede2[2]);
				glRotatef(90,0,1,0);
				desenhaDegrau(altura, comprimento, profundidade);
			glPopMatrix();
		}
		//parede 3
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede3[0],altura*i*2,coordParede3[2]-profundidade*(nSteps-1));
				glRotatef(180,0,1,0);
				desenhaDegrau(altura, comprimento, profundidade);
			glPopMatrix();
		}
	}
}

void desenhaParedePrincipal(){
	glPushMatrix();
		glTranslatef(coordParede4[0],coordParede4[1],coordParede4[2]);
		glRotatef(-90,0,1,0);
		desenhaDegrau((altura*nSteps*2)-altura,comprimento,profundidade);
	glPopMatrix();
}

void desenhaTelhado(){
	int i;
	
	for (i=0; i<alturaTelhado; i++) {
		glPushMatrix();
			glTranslatef(coordTelhado1[0],coordTelhado1[1]+altura*i*2,coordTelhado1[2]+profundidade*i);
			glScalef(1+(2*(alturaTelhado-i)*profundidade)/comprimento,1,1);
			desenhaDegrau(altura, 100, profundidade);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(coordTelhado2[0]+profundidade*i,coordTelhado2[1]+altura*i*2,coordTelhado2[2]);
			glRotatef(90,0,1,0);
			glScalef(1+(2*(alturaTelhado-i)*profundidade)/comprimento,1,1);
			desenhaDegrau(altura, 100, profundidade);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(coordTelhado3[0],coordTelhado3[1]+altura*i*2,coordTelhado3[2]-profundidade*i);
			glRotatef(180,0,1,0);
			glScalef(1+(2*(alturaTelhado-i)*profundidade)/comprimento,1,1);
			desenhaDegrau(altura, 100, profundidade);
		glPopMatrix();
		
			glPushMatrix();
			glTranslatef(coordTelhado4[0]-profundidade*i,coordTelhado4[1]+altura*i*2,coordTelhado4[2]);
			glRotatef(-90,0,1,0);
			glScalef(1+(2*(alturaTelhado-i)*profundidade)/comprimento,1,1);
			desenhaDegrau(altura, 100, profundidade);
		glPopMatrix();
	}
	
	glPushMatrix();
			glTranslatef(300,200,200);
			desenhaDegrau(altura, 100, 100);
		glPopMatrix();
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

