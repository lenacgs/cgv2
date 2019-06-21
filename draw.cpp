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

void desenhaQuadrado(GLfloat tam, GLfloat r, GLfloat g, GLfloat b, GLint text, GLint lado, GLint tipo){ 
//lado = face: 1- frente, 2- tras, 3- equerda, 4- direita, 5- cima, 6- baixo
	//glColor3f(255,255,255);
	if(text!=-1){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[text]);
	}
	glBegin(GL_QUADS);
		glNormal3i(0, 0, -1);
		if(tipo!=8){
			glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpec);
		}
		if(tipo==1){//escada
			if(lado==5 || lado == 6){
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
				glTexCoord2f(0.0f, 5.0f); glVertex2f(0-tam , 0+tam );
				glTexCoord2f(20.0f, 5.0f); glVertex2f(0+tam , 0+tam );
				glTexCoord2f(20.0f, 0.0f); glVertex2f(0+tam , 0-tam );
			}
			else{
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0-tam , 0+tam );
				glTexCoord2f(80.0f, 1.0f); glVertex2f(0+tam , 0+tam );
				glTexCoord2f(80.0f, 0.0f); glVertex2f(0+tam , 0-tam );
			}
		}
		else if (tipo == 0){
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
			glTexCoord2f(0.0f, 15.0f); glVertex2f(0-tam , 0+tam );
			glTexCoord2f(15.0f, 15.0f); glVertex2f(0+tam , 0+tam );
			glTexCoord2f(15.0f, 0.0f); glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == 2){
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
			glTexCoord2f(0.0f, 2.0f); glVertex2f(0-tam , 0+tam );
			glTexCoord2f(2.0f, 2.0f); glVertex2f(0+tam , 0+tam );
			glTexCoord2f(2.0f, 0.0f); glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == 3){
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
			glTexCoord2f(0.0f, 1.0f); glVertex2f(0-tam , 0+tam );
			glTexCoord2f(1.0f, 1.0f); glVertex2f(0+tam , 0+tam );
			glTexCoord2f(1.0f, 0.0f); glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == 4){
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
			glTexCoord2f(0.0f, 4.0f); glVertex2f(0-tam , 0+tam );
			glTexCoord2f(18.0f, 4.0f); glVertex2f(0+tam , 0+tam );
			glTexCoord2f(18.0f, 0.0f); glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == 5){
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
			glTexCoord2f(0.0f, 5.0f); glVertex2f(0-tam , 0+tam );
			glTexCoord2f(5.0f, 5.0f); glVertex2f(0+tam , 0+tam );
			glTexCoord2f(5.0f, 0.0f); glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == 6){
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
			glTexCoord2f(0.0f, 6.0f); glVertex2f(0-tam , 0+tam );
			glTexCoord2f(3.0f, 6.0f); glVertex2f(0+tam , 0+tam );
			glTexCoord2f(3.0f, 0.0f); glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == 7){
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
			glTexCoord2f(0.0f, 1.0f); glVertex2f(0-tam , 0+tam );
			glTexCoord2f(1.5f, 1.0f); glVertex2f(0+tam , 0+tam );
			glTexCoord2f(1.5f, 0.0f); glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == 9){
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0-tam , 0-tam );
			glTexCoord2f(0.0f, 7.0f); glVertex2f(0-tam , 0+tam );
			glTexCoord2f(6.0f, 7.0f); glVertex2f(0+tam , 0+tam );
			glTexCoord2f(6.0f, 0.0f); glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == 8){
			glMaterialfv(GL_FRONT, GL_AMBIENT, brownAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, brownDif);
			glVertex2f(0-tam , 0-tam );
			glVertex2f(0-tam , 0+tam );
			glVertex2f(0+tam , 0+tam );
			glVertex2f(0+tam , 0-tam );
		}
		else if (tipo == -1) {
			glVertex2f(0-tam , 0-tam );
			glVertex2f(0-tam , 0+tam );
			glVertex2f(0+tam , 0+tam );
			glVertex2f(0+tam , 0-tam );
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void desenhaDegrau(GLfloat altura, GLfloat comprimento, GLfloat profundidade, GLint text, GLint tipo) {

	glPushMatrix(); //face inferior
		glTranslatef(0.0, -altura, profundidade);
		glRotatef(90, 1.0, 0.0, 0.0); //rotacao de 90 graus sobre o eixo xx
		glScalef(comprimento, profundidade, profundidade);
		desenhaQuadrado(1.0, 255, 255, 0, text, 6, tipo);
	glPopMatrix();
	glPushMatrix(); //face superior
		glTranslatef(0.0, altura, profundidade);
		glRotatef(90, 1.0, 0.0, 0.0); //rotacao de 90 graus sobre o eixo xx
		glScalef(comprimento, profundidade, profundidade);
		desenhaQuadrado(1.0, 255, 165, 0, text, 5, tipo); //quadrado amarelo
	glPopMatrix();
	glPushMatrix(); //face traseira
		glTranslatef(0.0, 0.0, profundidade*2);
		glScalef(comprimento, altura, 1);
		desenhaQuadrado(1.0, 0.0, 0.0, 1.0, text, 2, tipo); //quadrado azul
	glPopMatrix(); 
	glPushMatrix(); //faces laterais
		glTranslatef(-comprimento, 0.0, profundidade), //esquerda
		glRotatef(90.0, 0.0, 1.0, 0.0); //rotacao de 90 graus sobre o eixo yy
		glScalef(profundidade, altura, 1);
		desenhaQuadrado(1.0, 0.0, 255, 0.0, text, 3, tipo); //quadrado verde
	glPopMatrix();
	glPushMatrix(); 
		glTranslatef(comprimento, 0.0, profundidade), //direita
		glRotatef(90.0, 0.0, 1.0, 0.0); //rotacao de 90 graus sobre o eixo yy
		glScalef(profundidade, altura, 1);
		desenhaQuadrado(1.0, 0.0, 1.0, 0.0, text, 4, tipo); //quadrado verde
	glPopMatrix();
	glPushMatrix(); //face frontal
		glScalef(comprimento, altura, profundidade);
		desenhaQuadrado(1.0, 1.0, 0.0, 0.0, text, 1, tipo); //quadrado vermelho
	glPopMatrix();
}

void desenhaEscadas(GLint text){
	int i,j;
	GLfloat steps=nSteps;
	
	if(retract==0){ //aberto
		//parede 1
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede1[0],altura*i*2,coordParede1[2]+profundidade*i);
				glScalef(1+(((steps-i)*profundidade)/comprimento),1,(steps-i+1)/2);
				desenhaDegrau(altura, comprimento, profundidade, text, 1);
			glPopMatrix();
		}
		//parede 2
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede2[0]+profundidade*i,altura*i*2,coordParede2[2]);
				glRotatef(90,0,1,0);
				glScalef(1+(((steps-i)*profundidade)/comprimento),1,(steps-i+1)/2);
				desenhaDegrau(altura, comprimento, profundidade, text, 1);
			glPopMatrix();
		}
		posEscada2=coordParede2[0]+profundidade*(nSteps-1);
		//parede 3
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede3[0],altura*i*2,coordParede3[2]-profundidade*i);
				glRotatef(180,0,1,0);
				glScalef(1+(((steps-i)*profundidade)/comprimento),1,(steps-i+1)/2);
				desenhaDegrau(altura, comprimento, profundidade, text, 1);
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
					desenhaDegrau(altura, comprimento, profundidade, text, 1);
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
				desenhaDegrau(altura, comprimento, profundidade, text, 1);
			glPopMatrix();
		}
		//parede 2
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede2[0]+profundidade*(nSteps-1),altura*i*2,coordParede2[2]);
				glRotatef(90,0,1,0);
				desenhaDegrau(altura, comprimento, profundidade, text, 1);
			glPopMatrix();
		}
		//parede 3
		for (i=0; i<nSteps; i++) {
			glPushMatrix();
				glTranslatef(coordParede3[0],altura*i*2,coordParede3[2]-profundidade*(nSteps-1));
				glRotatef(180,0,1,0);
				desenhaDegrau(altura, comprimento, profundidade, text, 1);
			glPopMatrix();
		}
	}
}

void desenhaParedePrincipal(){ //lado da casa que nao tem escada

	//PAREDES
	
	glPushMatrix();
		glTranslatef(coordParede4[0],coordParede4[1]+75,coordParede4[2]);
		glRotatef(-90,0,1,0);
		desenhaParede((altura*nSteps)/2-altura,comprimento,profundidade/2,4);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(coordParede4[0],coordParede4[1]+7,coordParede4[2]+167);
		glRotatef(-90,0,1,0);
		desenhaParede((altura*nSteps)-altura/3,comprimento/6,profundidade/2,5);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(coordParede4[0],coordParede4[1]+7,coordParede4[2]-167);
		glRotatef(-90,0,1,0);
		desenhaParede((altura*nSteps)-altura/3,comprimento/6,profundidade/2,5);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(coordParede4[0],coordParede4[1]+7,coordParede4[2]+50);
		glRotatef(-90,0,1,0);
		desenhaParede((altura*nSteps)-altura/3,20,profundidade/2,6);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(coordParede4[0],coordParede4[1]+7,coordParede4[2]-50);
		glRotatef(-90,0,1,0);
		desenhaParede((altura*nSteps)-altura/3,20,profundidade/2,6);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(coordParede4[0],coordParede4[1]+7,coordParede4[2]+102);
		glRotatef(-90,0,1,0);
		desenhaParede(10,32,profundidade/2,7);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(coordParede4[0],coordParede4[1]+7,coordParede4[2]-102);
		glRotatef(-90,0,1,0);
		desenhaParede(10,32,profundidade/2,7);
	glPopMatrix();
	
	//PORTAS
	
	glPushMatrix();
		glTranslatef(510,27,315);
		desenhaPorta();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(510,27,285);
		desenhaPorta();
	glPopMatrix();
	
	//JANELAS
	
	glPushMatrix();
		glTranslatef(505,15,201);
		desenhaJanela();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(505,15,404);
		desenhaJanela();
	glPopMatrix();
}

void desenhaPorta(){
	glPushMatrix();
		glRotatef(-90,0,1,0);
		desenhaDegrau(28,15,profundidade/2,-1,8);
	glPopMatrix();
	
	//textura
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	
	glPushMatrix();
		glTranslatef(0.05,-28,15);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 56, 0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(30, 56, 0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(30, 0, 0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glPushMatrix();
		glTranslatef(-10.1,-28,-15);
		glRotatef(-90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 56, 0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(30, 56, 0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(30, 0, 0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void drawCube(GLfloat width, GLfloat height, GLfloat depth) { //draws a cube

	glBegin(GL_QUADS);

		//back face
		glNormal3i(0, 0, -1);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0, 0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0, height, 0);

		//left face
		glNormal3i(-1, 0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0, height, 0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0, height, depth);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, depth);

		//front face
		glNormal3i(0, 0, 1);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, depth);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0, height, depth);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, depth);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0, depth);

		//right face
		glNormal3i(1, 0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(width, 0, depth);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(width, height, depth);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, 0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0, 0);

		//up face
		glNormal3i(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, height, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(width, height, 0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, depth);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, height, depth);

		//down face
		glNormal3i(0, -1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(width, 0, 0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(width, 0, depth);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, depth);		
	glEnd();
}

void desenhaLareira() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	
	glPushMatrix();
		glTranslatef(111, -1, 250);
		glRotatef(90, 0, 1, 0);
		
		glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
		
		glPushMatrix();
		glTranslatef(15, 0, 0);
			drawCube(40, 25, 3);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(15, 0, 0);
			drawCube(10, 25, 15);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(45, 0, 0);
			drawCube(10, 25, 15);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(25, 0, 0);
			drawCube(20, 7, 15);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(25, 18, 0);
			drawCube(20, 7, 15);
		glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	showParticulas(particulas, -213, 7, 120);
}

void desenhaCama() {

	glPushMatrix();
		glTranslatef(111, -1, 423);
		glRotatef(90, 0, 1, 0);
		drawCube(50, 30, 5);
		glMaterialfv(GL_FRONT, GL_AMBIENT, chromeAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, chromeDif);

		glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[8]);
		glTranslatef(0, 0, 5);
		drawCube(50, 10, 40);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void drawMirror() {

	glEnable(GL_STENCIL_TEST);
	glColorMask(0, 0, 0, 0);
	glDisable(GL_DEPTH_TEST);
	glStencilFunc(GL_ALWAYS, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 50);
			glVertex3f(0, 70, 50);
			glVertex3f(0, 70, 0);
		glEnd();
	glPopMatrix();

	glColorMask(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	glPushMatrix();
		//desenho da cena invertida
		glScalef(-1, 1, 1);
		drawScene();
	glPopMatrix();

	glDisable(GL_STENCIL_TEST);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, glassAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, glassDif);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 50);
			glVertex3f(0, 70, 50);
			glVertex3f(0, 70, 0);
		glEnd();
	glPopMatrix();

	glDisable(GL_BLEND);
}

void desenhaJanela(){

	glPushMatrix();
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, lightBrownAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, lightBrownDif);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 38, 0);
			glVertex3f(5, 38, 0);
			glVertex3f(5, 0, 0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0,-31);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, lightBrownAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, lightBrownDif);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 41.5, 0);
			glVertex3f(5, 41.5, 0);
			glVertex3f(5, 0, 0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0,31);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, lightBrownAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, lightBrownDif);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 41.5, 0);
			glVertex3f(5, 41.5, 0);
			glVertex3f(5, 0, 0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0,-34);
		glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, lightBrownAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, lightBrownDif);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 64, 0);
			glVertex3f(5, 64, 0);
			glVertex3f(5, 0, 0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,36.5,-34);
		glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, lightBrownAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, lightBrownDif);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 64, 0);
			glVertex3f(5, 64, 0);
			glVertex3f(5, 0, 0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,18.25,-34);
		glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, lightBrownAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, lightBrownDif);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 64, 0);
			glVertex3f(5, 64, 0);
			glVertex3f(5, 0, 0);
		glEnd();
	glPopMatrix();
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glPushMatrix();
		glTranslatef(0,5,-5);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 13.25, 0);
			glVertex3f(26, 13.25, 0);
			glVertex3f(26, 0, 0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,5,26);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 13.25, 0);
			glVertex3f(26, 13.25, 0);
			glVertex3f(26, 0, 0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,23.25,26);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 13.25, 0);
			glVertex3f(26, 13.25, 0);
			glVertex3f(26, 0, 0);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,23.25,-5);
		glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 13.25, 0);
			glVertex3f(26, 13.25, 0);
			glVertex3f(26, 0, 0);
		glEnd();
	glPopMatrix();
	
	glDisable(GL_BLEND);
}

void desenhaTelhado(GLint text){
	int i;
	
	for (i=0; i<alturaTelhado; i++) {
		glPushMatrix();
			glTranslatef(coordTelhado1[0],coordTelhado1[1]+altura*i*2,coordTelhado1[2]+profundidade*i);
			glScalef(1+(2*(alturaTelhado-i)*profundidade)/comprimento,1,1);
			desenhaDegrau(altura, 100, profundidade, text, 1);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(coordTelhado2[0]+profundidade*i,coordTelhado2[1]+altura*i*2,coordTelhado2[2]);
			glRotatef(90,0,1,0);
			glScalef(1+(2*(alturaTelhado-i)*profundidade)/comprimento,1,1);
			desenhaDegrau(altura, 100, profundidade, text, 1);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(coordTelhado3[0],coordTelhado3[1]+altura*i*2,coordTelhado3[2]-profundidade*i);
			glRotatef(180,0,1,0);
			glScalef(1+(2*(alturaTelhado-i)*profundidade)/comprimento,1,1);
			desenhaDegrau(altura, 100, profundidade, text, 1);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(coordTelhado4[0]-profundidade*i,coordTelhado4[1]+altura*i*2,coordTelhado4[2]);
			glRotatef(-90,0,1,0);
			glScalef(1+(2*(alturaTelhado-i)*profundidade)/comprimento,1,1);
			desenhaDegrau(altura, 100, profundidade, text, 1);
		glPopMatrix();
	}
	//tampinha do telhado
	glPushMatrix();
		glTranslatef(300,200,400);
		glRotatef(180,0,1,0);
		desenhaDegrau(altura, 100, 100, text, 0);
	glPopMatrix();
}

void desenhaParede(GLfloat x, GLfloat y, GLfloat z, GLint tipo){
	glPushMatrix();
		desenhaDegrau(x, y, z, 0, tipo);
	glPopMatrix();
}

void desenhaInterior(){
	
	//parede da primeira sala
	glPushMatrix();
		glTranslatef(350,0,300);
		glRotatef(90,0,1,0);
		desenhaParede(altura*nSteps*2,55,profundidade/2,9);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(350,0,440);
		glRotatef(90,0,1,0);
		desenhaParede(altura*nSteps*2,55,profundidade/2,9);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(350,0,160);
		glRotatef(90,0,1,0);
		desenhaParede(altura*nSteps*2,55,profundidade/2,9);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(350,70,230);
		glRotatef(90,0,1,0);
		desenhaParede(15,15,profundidade/2,7);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(350,70,370);
		glRotatef(90,0,1,0);
		desenhaParede(15,15,profundidade/2,7);
	glPopMatrix();
	
	//parede das duas divisoes
	glPushMatrix();
		glTranslatef(230,0,300);
		desenhaParede(altura*nSteps*2,125,profundidade/2,0);
	glPopMatrix();
	
	//teto
	glPushMatrix();
		glTranslatef(300,altura*nSteps*2,300);
		glRotatef(90,1,0,0);
		desenhaParede(200,200,profundidade/2,0);
	glPopMatrix();
	
	//tapete sala
	
	glPushMatrix();
		glTranslatef(190,0.001,150);
		desenhaTapete();
	glPopMatrix();
	
	//portas interiores
	//sala
	
	glPushMatrix();
		glTranslatef(360,27,230);
		desenhaPorta();
	glPopMatrix();
	
	//quarto
	glPushMatrix();
		glTranslatef(360,27,370);
		desenhaPorta();
	glPopMatrix();
}

void desenhaChao(){
	
	int x, z;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glPushMatrix();
		glBegin(GL_QUADS);
		glNormal3i(0, -1, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpec);
		for (x = 100; x < 510; x += 10) {
			for (z = 100; z < 500; z += 10) {
				glTexCoord2f(0.0f, 0.0f); glVertex3f(x, -0.94, z);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(x, -0.94, z + 10);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(x + 10, -0.94, z + 10);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(x + 10, -0.94, z);
			}
		}
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}



void desenhaLampada (bool flag, bool flag2){
	GLUquadricObj* quadric = gluNewQuadric();  
		gluQuadricDrawStyle(quadric, GLU_FILL);
		gluQuadricNormals(quadric, GLU_SMOOTH);
	if(flag2){
		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
			
			glRotatef(-90,1,0,0);
			gluCylinder(quadric, .25, .25, 8, 20, 20);  
		glPopMatrix();
	}

	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
		
		glRotatef(270,1,0,0);
		gluCylinder(quadric, 1.75, .25, 3, 20, 20);  
	glPopMatrix();

	glPushMatrix();
		if(flag){
			glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpec);
		}
		else{
			glMaterialfv(GL_FRONT, GL_AMBIENT, blackPlasticAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, blackPlasticDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, blackPlasticSpec);
		}
		glutSolidSphere(1.5, 50, 50);
	glPopMatrix();
}

void desenhaFocosExteriores(){
	glPushMatrix();
		glTranslatef(605,0,-5);
		glRotatef(180,0,1,0);
		glRotatef(-230,1,0,1);
		if(lights2)
			desenhaLampada(true, false);
		else
			desenhaLampada(false, false);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(605,0,605);
		glRotatef(90,0,1,0);
		glRotatef(-230,1,0,1);
		if(lights2)
			desenhaLampada(true, false);
		else
			desenhaLampada(false, false);
	glPopMatrix();
}

void desenhaLuzesInterior(){
	glPushMatrix();
		glTranslatef(410,82,300);
		if(lights1)
			desenhaLampada(true, true);
		else
			desenhaLampada(false, true);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(300,82,200);
		if(lights1)
			desenhaLampada(true, true);
		else
			desenhaLampada(false, true);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(150,82,200);
		if(lights1)
			desenhaLampada(true, true);
		else
			desenhaLampada(false, true);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(300,82,400);
		if(lights1)
			desenhaLampada(true, true);
		else
			desenhaLampada(false, true);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(150,82,400);
		if(lights1)
			desenhaLampada(true, true);
		else
			desenhaLampada(false, true);
	glPopMatrix();
}

void desenhaTapete(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[6]);
	glPushMatrix();
		glRotatef(90,1,0,0);
		glBegin(GL_QUADS);
			glNormal3i(0,1,0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpec);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
			glTexCoord2f(2.3f, 0.0f); glVertex3f(0, 80, 0);
			glTexCoord2f(2.3f, 2.5f); glVertex3f(80, 80, 0);
			glTexCoord2f(0.0f, 2.5f); glVertex3f(80, 0, 0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void desenhaAltarAgua(){
	glPushMatrix();
		glScalef(2,2,2);
		desenhaAltar(3,2,false);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0,-600);
		glScalef(2,2,2);
		desenhaAltar(3,2,false);
	glPopMatrix();
}

void desenhaAltar(GLint text, GLint tipo, bool flag){
	//degraus laterais
	//------------------------------------------------------

		
	glPushMatrix();
		glTranslatef(440,4,300);
		glRotatef(90,0,1,0);
		desenhaDegrau(4,15,3,text,2);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(373.9,4,300);
		glRotatef(90,0,1,0);
		desenhaDegrau(4,15,3,text,2);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(431.2,4,321.1);
		glRotatef(45,0,1,0);
		desenhaDegrau(4,15,3,text,2);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(435.3,4,274.3);
		glRotatef(-45,0,1,0);
		desenhaDegrau(4,15,3,text,2);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(410,4,263.8);
		desenhaDegrau(4,15,3,text,2);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(410,4,330);
		desenhaDegrau(4,15,3,text,2);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(388.55,4,321);
		glRotatef(-45,0,1,0);
		desenhaDegrau(4,15,3,text,2);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(384.5,4,274.4);
		glRotatef(45,0,1,0);
		desenhaDegrau(4,15,3,text,2);
	glPopMatrix();
	
	//--------------------------------------------------
	//tampa de cima do altar
	if(flag) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[text]);
	}
	glPushMatrix();
		if(flag)
			glTranslatef(410,8.5,300);
		else
			glTranslatef(410,6.5,300);
		glRotatef(22.5,0,1,0);
		glRotatef(-90,1,0,0);
		glBegin(GL_POLYGON);
			glNormal3i(0,1,0);
			if(flag){
				glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
				glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpec);
			}
			else{
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glMaterialfv(GL_FRONT, GL_AMBIENT, cyanRubberAmb);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, cyanRubberDif);
				glMaterialfv(GL_FRONT, GL_SPECULAR, cyanRubberSpec);
			}	
			for(int i=0;i<=8;i++){
				double anglo=i*2*PI/8;
				if(flag){
					if(i==0)
						glTexCoord2f(0.25f, 0.0f);
					if(i==1)
						glTexCoord2f(0.75f, 0.0f);
					if(i==2)
						glTexCoord2f(1.0f, 0.25f);
					if(i==3)
						glTexCoord2f(1.0f, 0.75f);
					if(i==4)
						glTexCoord2f(0.75f, 1.0f);
					if(i==5)
						glTexCoord2f(0.25f, 1.0f);
					if(i==6)
						glTexCoord2f(0.0f, 0.75f);
					if(i==7)
						glTexCoord2f(0.0f, 0.25f);
				}
				glVertex2d(35*cos(anglo),35*sin(anglo));
			}
		glEnd();
		glDisable(GL_BLEND);
	glPopMatrix();
	if(flag)
		glDisable(GL_TEXTURE_2D);
	
	if(flag){
	//quadro 20 a CG
	//frame
	glPushMatrix();
		glTranslatef(407,38,300);
		glRotatef(Irotate,0,1,0);
		glTranslatef(-407,-38,-300);
		glPushMatrix();
			glTranslatef(407,38,300);
			glRotatef(90,0,1,0);
			desenhaDegrau(30,30,3,-1,-1);
		glPopMatrix();

		//quadro
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[4]);
		glPushMatrix();
			glTranslatef(413.1,8,330);
			glRotatef(-90,0,1,0);
			glRotatef(90,0,0,1);
			glBegin(GL_QUADS);
				glNormal3i(0,1,0);
				glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmb);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDif);
				glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpec);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 60, 0);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(60, 60, 0);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(60, 0, 0);
			glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	}
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
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-2000, -1, -2000);
			glTexCoord2f(0.0f, 20.0f); glVertex3f(-2000, -1, 2000);
			glTexCoord2f(20.0f, 20.0f); glVertex3f(2000, -1, 2000);
			glTexCoord2f(20.0f, 0.0f); glVertex3f(2000, -1, -2000);
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
		glTexCoord2f(0.055f, 0.0f); glVertex3f(-2000, -1, -2000);
		glTexCoord2f(0.055f, 1.0f); glVertex3f(-2000, 2000, -2000);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2000, 2000, 2000);
		glTexCoord2f(1.0f, 0.055f); glVertex3f(-2000, -1, 2000);

		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

