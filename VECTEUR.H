
#ifndef __VECTEUR
#define __VECTEUR


typedef struct t_vecteur {
	double x,y,z;
} t_vecteur;



double inline vecteur_Norme(t_vecteur *v);
void inline vecteur_Normalize(t_vecteur *v);


#endif