#include "cut.h"

OPENFILENAME ofn;
// a another memory buffer to contain the file name
TCHAR szFile[100];

void desenareMouse(int button, int state, int mx, int my)
{
	my = glutGet(GLUT_WINDOW_HEIGHT) - my;
	printf(" %d %d", mx, my);

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (isPatrat){
			glColor3f(1.0, 0.0, 0.0);
			desenarePatratConturCuMouse(mx, my, dimensiuneX, dimensiuneY);
		}
		else if (isTriunghi) {
			glColor3f(1.0, 0.0, 0.0);
			desenareTriunghiConturCuMouse(mx, my, dimensiuneX, dimensiuneY);
		}
		else if (isCerc) {
			glColor3f(1.0, 0.0, 0.0);
			desenareCercConturCuMouse(mx, my, razaCerc);
		}
		mouseX = mx;
		mouseY = my;
		glFlush();
	}
}

void decupareImagine()
{
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_STENCIL_TEST);
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);//inactivarea desenarii in buffer-ul de culoare


	if (isPatrat) {
		glStencilFunc(GL_ALWAYS, 0x01, 0x01);
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
		desenarePatratCuMouse(mouseX, mouseY, dimensiuneX, dimensiuneY);

		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
		glStencilFunc(GL_ALWAYS, 0x01, 0x01);
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
		desenarePatratConturCuMouse(mouseX, mouseY, dimensiuneX, dimensiuneY);
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

		glStencilFunc(GL_NOTEQUAL, 0x01, 0x03);
		glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);// activarea desenarii in buffer-ul de culoare
		glColor3f(0.1f, 0.1f, 0.1f);
		desenarePatratCuMousePentruImagine(mouseX, mouseY, dimensiuneX, dimensiuneY);
		glDisable(GL_STENCIL_TEST);

		glColor3f(0.1f, 0.1f, 0.1f);
		desenarePatratConturCuMouse(mouseX, mouseY, dimensiuneX, dimensiuneY);
	}
	else if (isTriunghi) {
		glStencilFunc(GL_ALWAYS, 0x01, 0x01);
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
		desenareTriunghiCuMouse(mouseX, mouseY, dimensiuneX, dimensiuneY);

		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
		glStencilFunc(GL_ALWAYS, 0x01, 0x01);
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
		desenareTriunghiConturCuMouse(mouseX, mouseY, dimensiuneX, dimensiuneY);
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

		glStencilFunc(GL_NOTEQUAL, 0x01, 0x03);
		glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);// activarea desenarii in buffer-ul de culoare
		glColor3f(0.1f, 0.1f, 0.1f);
		desenarePatratCuMousePentruImagine(mouseX, mouseY, dimensiuneX, dimensiuneY);
		glDisable(GL_STENCIL_TEST);

		glColor3f(0.1f, 0.1f, 0.1f);
		desenareTriunghiConturCuMouse(mouseX, mouseY, dimensiuneX, dimensiuneY);
	}
	else if (isCerc) {
		glStencilFunc(GL_ALWAYS, 0x01, 0x01);
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
		desenareCercCuMouse(mouseX, mouseY, razaCerc);

		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
		glStencilFunc(GL_ALWAYS, 0x01, 0x01);
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
		desenareCercConturCuMouse(mouseX, mouseY, razaCerc);
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

		glStencilFunc(GL_NOTEQUAL, 0x01, 0x03);
		glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);// activarea desenarii in buffer-ul de culoare
		glColor3f(0.1f, 0.1f, 0.1f);
		desenarePatratCuMousePentruImagine(mouseX, mouseY, dimensiuneX, dimensiuneY);
		glDisable(GL_STENCIL_TEST);

		glColor3f(0.1f, 0.1f, 0.1f);
		desenareCercConturCuMouse(mouseX, mouseY, razaCerc);
	}
}

void switchCase(int value)
{
	switch (value) {
		////////////////////////////////////////////////////////////////
		//Desenare Patrat
		////////////////////////////////////////////////////////////////
	case 2:
		dimensiuneX = 200;
		dimensiuneY = 200;
		booleanFunction(true, false, false);
		break;
	case 3:
		dimensiuneX = 175;
		dimensiuneY = 175;
		booleanFunction(true, false, false);
		break;
	case 4:
		dimensiuneX = 150;
		dimensiuneY = 150;
		booleanFunction(true, false, false);
		break;
	case 5:
		dimensiuneX = 125;
		dimensiuneY = 125;
		booleanFunction(true, false, false);
		break;
	case 6:
		dimensiuneX = 100;
		dimensiuneY = 100;
		booleanFunction(true, false, false);
		break;
		////////////////////////////////////////////////////////////////
		//Desenare Patrat
		////////////////////////////////////////////////////////////////
	case 7:
		dimensiuneX = 200;
		dimensiuneY = 200;
		booleanFunction(false, true, false);
		break;
	case 8:
		dimensiuneX = 175;
		dimensiuneY = 175;
		booleanFunction(false, true, false);
		break;
	case 9:
		dimensiuneX = 150;
		dimensiuneY = 150;
		booleanFunction(false, true, false);
		break;
	case 10:
		dimensiuneX = 125;
		dimensiuneY = 125;
		booleanFunction(false, true, false);
		break;
	case 11:
		dimensiuneX = 100;
		dimensiuneY = 100;
		booleanFunction(false, true, false);
		break;
		////////////////////////////////////////////////////////////////
		//Desenare Cerc
		////////////////////////////////////////////////////////////////
	case 12:
		razaCerc = 200;
		dimensiuneX = 100;
		dimensiuneY = 100;
		booleanFunction(false, false, true);
		break;
	case 13:
		razaCerc = 175;
		dimensiuneX = 100;
		dimensiuneY = 100;
		booleanFunction(false, false, true);
		break;
	case 14:
		razaCerc = 150;
		dimensiuneX = 100;
		dimensiuneY = 100;
		booleanFunction(false, false, true);
		break;
	case 15:
		razaCerc = 125;
		dimensiuneX = 100;
		dimensiuneY = 100;
		booleanFunction(false, false, true);
		break;
	case 16:
		razaCerc = 100;
		dimensiuneX = 100;
		dimensiuneY = 100;
		booleanFunction(false, false, true);
		break;
	case 17:
		alegeImaginea();
	case 1:
		decupareImagine();
		break;
	case 0:
	default: break;

	}
}

void alegeImaginea()
{
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = (szFile);
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	GetOpenFileName(&ofn);
	
	// Now simpley display the file name 
	MessageBox(NULL, ofn.lpstrFile, L"File Name", MB_OK);
}
void booleanFunction(bool patrat, bool triunghi, bool cerc)
{
	isPatrat = patrat;
	isTriunghi = triunghi;
	isCerc = cerc;
}


void desenarePatratConturCuMouse(int mX, int mY, int dimX, int dimY)
{
	glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(mX - dimX, mY - dimY);
		glVertex2f(mX - dimX, mY + dimY);
		glVertex2f(mX + dimX, mY + dimY);
		glVertex2f(mX + dimX, mY - dimY);
	glEnd();
	glFlush();
}

void desenarePatratCuMouse(int mX, int mY, int dimX, int dimY)
{
	glBegin(GL_QUADS);
		glVertex2f(mX - dimX, mY - dimY);
		glVertex2f(mX - dimX, mY + dimY);
		glVertex2f(mX + dimX, mY + dimY);
		glVertex2f(mX + dimX, mY - dimY);
	glEnd();
}

void desenarePatratCuMousePentruImagine(int mX, int mY, int dimX, int dimY)
{
	glBegin(GL_QUADS);
	glVertex2f(mX - 8 * dimX, mY - 8 * dimY);
	glVertex2f(mX - 8 * dimX, mY + 8 * dimY);
	glVertex2f(mX + 8 * dimX, mY + 8 * dimY);
	glVertex2f(mX + 8 * dimX, mY - 8 * dimY);
	glEnd();
}

void desenareTriunghiConturCuMouse(int mX, int mY, int dimX, int dimY)
{
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
		glVertex2f(mX - dimX, mY);
		glVertex2f(mX + dimX, mY);
		glVertex2f(mX, mY + dimY);
		glVertex2f(mX - dimX, mY);
	glEnd();
	glFlush();
}

void desenareTriunghiCuMouse(int mX, int mY, int dimX, int dimY)
{
	glBegin(GL_TRIANGLES);
		glVertex2f(mX - dimX, mY);
		glVertex2f(mX + dimX, mY);
		glVertex2f(mX, mY + dimY);
		glVertex2f(mX - dimX, mY);
	glEnd();
}

void desenareCercConturCuMouse(int mX, int mY, float raza)
{
	glLineWidth(3);
	
	int i;
	double PI = 3.1415926535;
	glPushMatrix();
	glTranslatef(mX, mY, 0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 360; i++)
		glVertex2f(raza*cos(PI*i / 180.0), raza*sin(PI*i / 180.0));
	glEnd();
	glPopMatrix();
	glTranslatef(0, 0, 0);
}

void desenareCercCuMouse(int mX, int mY, float raza)
{
	int i;
	double PI = 3.1415926535;
	glPushMatrix();
	glTranslatef(mX, mY, 0);
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++)
		glVertex2f(raza*cos(PI*i / 180.0), raza*sin(PI*i / 180.0));
	glEnd();
	glPopMatrix();
	glTranslatef(0, 0, 0);
}






