

#ifndef __PROPERTY
#define __PROPERTY


typedef struct t_composante {
	double red;
	double green;
	double blue;
} t_composante;


typedef struct t_properties {
  double n;
  t_composante ambiant;
  t_composante diffuse;
  t_composante specular;
  t_composante reflect;
} t_properties;



#endif