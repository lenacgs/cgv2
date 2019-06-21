#include "definitions.h"

#define frand()	((float)rand()/RAND_MAX)

void showParticulas(Particula *particula, GLfloat px, GLfloat py, GLfloat pz) {
	int i;
	int numero;
	GLfloat v;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[7]);

	numero = (int)(frand()*10.0);
	
	for (i = 0; i < MAX_PARTICULAS; i++) {
		if (particula[i].vida > 0 && (particula[i].x < px + 11 && particula[i].x > px - 4)) {
			
			glPushMatrix();
			glRotatef(90, 0, 1, 0);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex3f(particula[i].x - particula[i].vida, particula[i].y - particula[i].tam, particula[i].z);
			glTexCoord2d(0, 1); glVertex3f(particula[i].x - particula[i].vida, particula[i].y + particula[i].tam, particula[i].z);
			glTexCoord2d(1, 1); glVertex3f(particula[i].x + particula[i].vida, particula[i].y + particula[i].tam, particula[i].z);
			glTexCoord2d(1, 0); glVertex3f(particula[i].x + particula[i].vida, particula[i].y - particula[i].tam, particula[i].z);
			glEnd();
			glPopMatrix();
			particula[i].x += particula[i].vx;
			particula[i].y += particula[i].vy;

			particula[i].vx /= (particula[i].y) * 5;
			
			if (particula[i].vx > 1) {
				particula[i].vx = 0.1;
			}
			else if (particula[i].vx < -1) {
				particula[i].vx = -0.1;
			}

			particula[i].vida -= particula[i].fade;
		}
		else {
			v = frand() + 0.02;

			particula[i].x = px + frand()*px;   
			particula[i].y = py + frand()*py;
			particula[i].z = pz + 0.05*frand()*pz;	

			if (particula[i].x > 0.1 * 0.5 * px + px) {
				particula[i].vx = v * -frand() * (particula[i].x - (0.1 * 0.5 * px + px)) * 0.025;//.025;
			}
			else {
				particula[i].vx = v * frand() * (0.1 * 0.5 * px + px - particula[i].x) * 0.025;//.025;
			}

			particula[i].vy = v * 0.05;


			particula[i].vida = 1.0f;
			particula[i].fade = frand() * .01f + .005;	// Em 100=1/0.01 iteracoes desaparece
		}
	}

	glDisable(GL_TEXTURE_2D);
}

void initParticulas(Particula *particula) {
	GLfloat v;
	int i;
	GLfloat ps;
	ps = 0.1;

	for (i = 0; i<MAX_PARTICULAS; i++) {
		particula[i].tam = ps;		// tamanho de cada particula

		particula[i].vida = 0;
	}
}