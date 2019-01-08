#include "openGLWindow.h"

void init()
{
	//glClearColor(0.0, 1.0, 1.0, 0.0);
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	glShadeModel(GL_FLAT);
	//glEnable(GL_DEPTH_TEST);

	//Load HORSE IMAGE
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	pImage = gltLoadTGA("horse.tga", &iWidth, &iHeight, &iComponents, &eFormat);
	//pImage = gltLoadTGA(, &iWidth, &iHeight, &iComponents, &eFormat);
}

void initShutDown() {
	free(pImage);
}

void myReshape(int w, int h)
{
	if (h == 0) h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0.0f, (GLfloat)w, 0.0f, (GLfloat)h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void renderScene(void)
{
	/////////////////////////////////////////////
	//Variable
	GLbyte *pModifiedBytes = NULL;


	glClearStencil(0x0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
	glRasterPos2i(35, 35);
	glDrawPixels(iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pImage);
	
	switchCase(value);
	
	glFlush();
}

void createMenu(void) {
	/////////////////////////////////////////
	// SUB MENU PATRAT
	subMenuPatrat = glutCreateMenu(menu);
	glutAddMenuEntry("200x200", 2);
	glutAddMenuEntry("175x175", 3);
	glutAddMenuEntry("150x150", 4);
	glutAddMenuEntry("125x125", 5);
	glutAddMenuEntry("100x100", 6);
	/////////////////////////////////////////
	// SUB MENU PATRAT
	subMenuTriunghi = glutCreateMenu(menu);
	glutAddMenuEntry("200x200", 7);
	glutAddMenuEntry("175x175", 8);
	glutAddMenuEntry("150x150", 9);
	glutAddMenuEntry("125x125", 10);
	glutAddMenuEntry("100x100", 11);
	/////////////////////////////////////////
	// SUB MENU CERC
	subMenuCerc = glutCreateMenu(menu);
	glutAddMenuEntry("200x200", 12);
	glutAddMenuEntry("175x175", 13);
	glutAddMenuEntry("150x150", 14);
	glutAddMenuEntry("125x125", 15);
	glutAddMenuEntry("100x100", 16);
	///////////////////////////////////////
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Alege imagine", 17);
	glutAddMenuEntry("Decupeaza", 1);
	glutAddSubMenu("Patrat", subMenuPatrat);
	glutAddSubMenu("Triunghi", subMenuTriunghi);
	glutAddSubMenu("Cerc", subMenuCerc);
	glutAddMenuEntry("Quit", 0);     
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu(int num) {
	if (num == 0) {
		exit(0);
	}
	else {
		value = num;
	}
	glutPostRedisplay();
}

GLint gltWriteTGA(const char * szFileName)
{
	FILE *pFile;                // File pointer
	TGAHEADER tgaHeader;		// TGA file header
	unsigned long lImageSize;   // Size in bytes of image
	GLbyte	*pBits = NULL;      // Pointer to bits
	GLint iViewport[4];         // Viewport in pixels
	GLenum lastBuffer;          // Storage for the current read buffer setting

	// Get the viewport dimensions
	glGetIntegerv(GL_VIEWPORT, iViewport);

	// How big is the image going to be (targas are tightly packed)
	lImageSize = iViewport[2] * 3 * iViewport[3];

	// Allocate block. If this doesn't work, go home
	pBits = (GLbyte *)malloc(lImageSize);
	if (pBits == NULL)
		return 0;

	// Read bits from color buffer
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glPixelStorei(GL_PACK_ROW_LENGTH, 0);
	glPixelStorei(GL_PACK_SKIP_ROWS, 0);
	glPixelStorei(GL_PACK_SKIP_PIXELS, 0);

	// Get the current read buffer setting and save it. Switch to
	// the front buffer and do the read operation. Finally, restore
	// the read buffer state
	glGetIntegerv(GL_READ_BUFFER, (GLint *)&lastBuffer);
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, iViewport[2], iViewport[3], GL_BGR_EXT, GL_UNSIGNED_BYTE, pBits);
	glReadBuffer(lastBuffer);

	// Initialize the Targa header
	tgaHeader.identsize = 0;
	tgaHeader.colorMapType = 0;
	tgaHeader.imageType = 2;
	tgaHeader.colorMapStart = 0;
	tgaHeader.colorMapLength = 0;
	tgaHeader.colorMapBits = 0;
	tgaHeader.xstart = 0;
	tgaHeader.ystart = 0;
	tgaHeader.width = iViewport[2];
	tgaHeader.height = iViewport[3];
	tgaHeader.bits = 24;
	tgaHeader.descriptor = 0;


	// Attempt to open the file
	pFile = fopen(szFileName, "wb");
	if (pFile == NULL)
	{
		free(pBits);    // Free buffer and return error
		return 0;
	}

	// Write the header
	fwrite(&tgaHeader, sizeof(TGAHEADER), 1, pFile);

	// Write the image data
	fwrite(pBits, lImageSize, 1, pFile);

	// Free temporary buffer and close the file
	free(pBits);
	fclose(pFile);

	// Success!
	return 1;
}

GLbyte * gltLoadTGA(const char * szFileName, GLint * iWidth, GLint * iHeight, GLint * iComponents, GLenum * eFormat)
{
	FILE *pFile;			// File pointer
	TGAHEADER tgaHeader;		// TGA file header
	unsigned long lImageSize;		// Size in bytes of image
	short sDepth;			// Pixel depth;
	GLbyte	*pBits = NULL;          // Pointer to bits

	// Default/Failed values
	*iWidth = 0;
	*iHeight = 0;
	*eFormat = GL_BGR_EXT;
	*iComponents = GL_RGB8;

	// Attempt to open the file
	pFile = fopen(szFileName, "rb");
	if (pFile == NULL)
		return NULL;

	// Read in header (binary)
	fread(&tgaHeader, sizeof(TGAHEADER), 1, pFile);


	// Get width, height, and depth of texture
	*iWidth = tgaHeader.width;
	*iHeight = tgaHeader.height;
	sDepth = tgaHeader.bits / 8;
	printf("a citit fisierul %d\n", tgaHeader.height);
	printf("a citit fisierul %d\n", tgaHeader.width);
	// Put some validity checks here. Very simply, I only understand
	// or care about 8, 24, or 32 bit targa's.
   // if(tgaHeader.bits != 8 && tgaHeader.bits != 24 && tgaHeader.bits != 32)
   //    return NULL;

	// Calculate size of image buffer
	lImageSize = tgaHeader.width * tgaHeader.height * sDepth;
	printf("a citit fisierul %d\n", lImageSize);
	// Allocate memory and check for success
	pBits = (GLbyte*)malloc(lImageSize * sizeof(GLbyte));
	if (pBits == NULL)
		return NULL;

	// Read in the bits
	// Check for read error. This should catch RLE or other 
	// weird formats that I don't want to recognize
	if (fread(pBits, lImageSize, 1, pFile) != 1)
	{
		free(pBits);
		return NULL;
	}

	// Set OpenGL format expected
	switch (sDepth)
	{
	case 3:     // Most likely case
		*eFormat = GL_BGR_EXT;
		*iComponents = GL_RGB8;
		break;
	case 4:
		*eFormat = GL_BGRA_EXT;
		*iComponents = GL_RGBA8;
		break;
	case 1:
		*eFormat = GL_LUMINANCE;
		*iComponents = GL_LUMINANCE8;
		break;
	};


	// Done with File
	fclose(pFile);

	// Return pointer to image data
	return pBits;
}
