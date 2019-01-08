#include "openGLWindow.h"

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_STENCIL | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Proiect OPENGL - Decupare Imagini");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(renderScene);
	
	glutMouseFunc(desenareMouse);

	createMenu();

	init();
	glutMainLoop();

	initShutDown();
	return 0;
}