// GLOS.H
//
// This is an OS specific header file

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// disable data conversion warnings

#pragma warning(disable : 4244)     // MIPS
#pragma warning(disable : 4136)     // X86
#pragma warning(disable : 4051)     // ALPHA
#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")
