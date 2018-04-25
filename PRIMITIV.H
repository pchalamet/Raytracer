
#ifndef __PRIMITIVE
#define __PRIMITIVE



#include "ray.h"
#include "segment.h"
#include "csg.h"


t_segment *primitive_Quadric(t_ray *r, t_quadric *q);
t_segment *primitive_Sphere(t_ray *r, t_sphere *sphere);
t_segment *primitive_Plane(t_ray *r, t_plane *plane);

#endif