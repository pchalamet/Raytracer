


#ifndef __OBJET
#define __OBJET


#include "csg.h"


typedef struct t_objet {
	t_csg *csg;
	struct t_objet *next;
} t_objet;


#endif