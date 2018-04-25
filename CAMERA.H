


#ifndef __CAMERA
#define __CAMERA


#include "vecteur.h"


typedef struct {
	t_vecteur pos;
	t_vecteur dir;
	double spin;
	double angle;
	double width,height;
	double focal;
} t_camera;





#endif