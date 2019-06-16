#include "definitions.h"
#include "materials.h"

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

