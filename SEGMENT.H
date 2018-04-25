


#ifndef __SEGMENT
#define __SEGMENT



#include "vecteur.h"
#include "csg.h"



typedef struct t_segment {
	double t1,t2;
	t_vecteur n1,n2;
	t_properties p1,p2;
	struct t_segment *next;
} t_segment;



t_segment *segment_Alloc(void);
void segment_Free(t_segment *seg);

t_segment *segment_Union(t_segment *seg1, t_segment *seg2);
t_segment *segment_Intersection(t_segment *seg1, t_segment *seg2);
t_segment *segment_Negation(t_segment *seg);



#endif