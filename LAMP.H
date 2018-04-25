

#ifndef __LAMP
#define __LAMP


#include "vecteur.h"



typedef struct t_lamp {
	t_vecteur pos;
	double intensity;
	struct t_lamp *next;
} t_lamp;


#endif