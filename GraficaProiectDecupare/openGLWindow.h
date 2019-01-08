#pragma once
#include "cut.h"
#pragma pack(1)
typedef struct
{
	GLbyte	identsize;              // Size of ID field that follows header (0)
	GLbyte	colorMapType;           // 0 = None, 1 = paletted
	GLbyte	imageType;              // 0 = none, 1 = indexed, 2 = rgb, 3 = grey, +8=rle
	unsigned short	colorMapStart;          // First colour map entry
	unsigned short	colorMapLength;         // Number of colors
	unsigned char 	colorMapBits;   // bits per palette entry
	unsigned short	xstart;                 // image x origin
	unsigned short	ystart;                 // image y origin
	unsigned short	width;                  // width in pixels
	unsigned short	height;                 // height in pixels
	GLbyte	bits;                   // bits per pixel (8 16, 24, 32)
	GLbyte	descriptor;             // image descriptor
} TGAHEADER;
#pragma pack(8)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Variable
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static GLbyte *pImage = NULL;
static GLint iWidth, iHeight, iComponents;
static GLenum eFormat;

static int menu_id;
static int subMenuPatrat, subMenuTriunghi, subMenuCerc;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Methods
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init();
void initShutDown();
void myReshape(int w, int h);
void renderScene(void);
void createMenu();
void menu(int num);

GLint gltWriteTGA(const char *szFileName);
GLbyte *gltLoadTGA(const char *szFileName, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat);