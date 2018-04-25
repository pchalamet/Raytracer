
#include <math.h>

#include "vecteur.h"




#define sq(x) ((x)*(x))


double inline vecteur_Norme(t_vecteur *v)
{
	return sqrt(sq(v->x) + sq(v->y) + sq(v->z));
}


void inline vecteur_Normalize(t_vecteur *v)
{
	double norme;

	norme = vecteur_Norme(v);
	v->x /= norme;
	v->y /= norme;
	v->z /= norme;
}

