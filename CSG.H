
#ifndef __CSG
#define __CSG


#include "property.h"
#include "vecteur.h"




/* operation booleenne */
#define CSG_INTERSECTION 0
#define CSG_UNION 1
#define CSG_NEGATION 2


typedef struct {
	struct t_csg *fils;
} t_un_fils;


typedef struct {
	struct t_csg *fils_g;
	struct t_csg *fils_d;
} t_deux_fils;






/* transformation sur les objets */
#define CSG_TRANSLATION 256
#define CSG_ROTATION 257
#define CSG_SCALE 258


typedef struct {
	t_vecteur v;
	struct t_csg *csg;
} t_translation;


typedef struct {
	t_vecteur r;
	struct t_csg *csg;
} t_rotation;


typedef struct {
	t_vecteur s;
	struct t_csg *csg;
} t_scale;





/* objets */
#define CSG_QUADRIC 512
#define CSG_SPHERE 513
#define CSG_PLANE 514





typedef struct t_quadric {
	double a,b,c;
	double d,e,f;
	double g,h,i;
	double j;
	t_properties prop;
} t_quadric;


typedef struct t_sphere {
	t_properties prop;
} t_sphere;



typedef struct t_plane {
	double tile;
	t_properties prop;
} t_plane;




typedef struct t_csg {
	int type;
	union {
		t_un_fils un_fils;
		t_deux_fils deux_fils;
		t_translation translation;
		t_rotation rotation;
		t_scale scale;

		t_quadric quadric;
		t_sphere sphere;
		t_plane plane;
	} u_objet;
} t_csg;




void csg_Free(t_csg *csg);
void csg_Display(t_csg *csg);



#endif