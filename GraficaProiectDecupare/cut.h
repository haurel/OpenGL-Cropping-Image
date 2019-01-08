#pragma once
#include "GLOS.H"
#include "global.h"
#include <Commdlg.h>
////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
//Methods
////////////////////////////////////////////////////////////////////////////////////////////
void desenareMouse(int button, int state, int mx, int my);
void decupareImagine();
void switchCase(int value);
void alegeImaginea();
void booleanFunction(bool patrat, bool triunghi, bool cerc);
//Patrat
void desenarePatratConturCuMouse(int mX, int mY, int dimX, int dimY);
void desenarePatratCuMouse(int mX, int mY, int dimX, int dimY);
void desenarePatratCuMousePentruImagine(int mX, int mY, int dimX, int dimY);
//Triunghi
void desenareTriunghiConturCuMouse(int mX, int mY, int dimX, int dimY);
void desenareTriunghiCuMouse(int mX, int mY, int dimX, int dimY);
//Cerc
void desenareCercConturCuMouse(int mX, int mY, float raza);
void desenareCercCuMouse(int mX, int mY, float raza);

