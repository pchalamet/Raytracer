

#ifndef __INTER
#define __INTER


#include "property.h"
#include "vecteur.h"




typedef struct t_inter {
	int intersection;
	double t;
	t_vecteur n;
	t_properties prop;
} t_inter;


#endif