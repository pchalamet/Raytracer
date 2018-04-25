

#include <stdlib.h>
#include <stddef.h>

#include <math.h>

#include "primitive.h"
#include "ray.h"
#include "segment.h"



#define sq(x) ((x)*(x))





t_segment *primitive_Quadric(t_ray *r, t_quadric *q)
{
  double a,b,c,delta;
  t_segment *seg;


  a = q->a*sq(r->v.x) + q->b*sq(r->v.y) + q->c*sq(r->v.z)
    + q->d*r->v.x*r->v.y + q->e*r->v.x*r->v.z + q->f*r->v.y*r->v.z;

  b = 2.0 * (q->a*r->q.x*r->v.x + q->b*r->q.y*r->v.y + q->c*r->q.z*r->v.z)
    + q->d * (r->q.x*r->v.y + r->v.x*r->q.y)
    + q->e * (r->q.x*r->v.z + r->v.x*r->q.z)
    + q->f * (r->q.y*r->v.z + r->v.y*r->q.z)
    + q->g*r->v.x + q->h*r->v.y + q->i*r->v.z;

  c = q->a*sq(r->q.x) + q->b*sq(r->q.y) + q->c*sq(r->q.z)
    + q->d*r->q.x*r->q.y + q->e*r->q.x*r->q.z + q->f*r->q.y*r->q.z
    + q->g*r->q.x + q->h*r->q.y + q->i*r->q.z
    - q->j;

  delta = sq(b) - 4.0*a*c;

  if (delta<=0.0)
    return NULL;
  else
    {
      seg = segment_Alloc();
      seg->t1 = (-b-sqrt(delta)) / (2.0*a);
      seg->t2 = (-b+sqrt(delta)) / (2.0*a);

      if (seg->t1 > seg->t2)
	{
	  delta = seg->t1;
	  seg->t1 = seg->t2;
	  seg->t2 = delta;
	}

      seg->p1 = q->prop;
      seg->p2 = q->prop;
      seg->next = NULL;

      /* calcul de la normale a la quadrique en ce point */
      return seg;
    }
}




t_segment *primitive_Sphere(t_ray *r, t_sphere *sphere)
{
  double delta;
  t_segment *seg;
  double a,b;


  a = sq(r->v.x) + sq(r->v.y) + sq(r->v.z);
  b = r->q.x*r->v.x + r->q.y*r->v.y + r->q.z*r->v.z;

  delta = sq(b) - a * (sq(r->q.x) + sq(r->q.y) + sq(r->q.z) - 1.0);

  if (delta < 0.0)
    return NULL;

  seg = segment_Alloc();

  /* mise en place des t parametriques */
  seg->t1 = ( -b - sqrt(delta)) / a;
  seg->t2 = ( -b + sqrt(delta)) / a;

  /* mise en place des normales */
  seg->n1.x = 2.0 * (r->q.x + seg->t1*r->v.x);
  seg->n1.y = 2.0 * (r->q.y + seg->t1*r->v.y);
  seg->n1.z = 2.0 * (r->q.z + seg->t1*r->v.z);

  seg->n2.x = 2.0 * (r->q.x + seg->t2*r->v.x);
  seg->n2.y = 2.0 * (r->q.y + seg->t2*r->v.y);
  seg->n2.z = 2.0 * (r->q.z + seg->t2*r->v.z);

  /* mise en place des proprietes */
  seg->p1 = sphere->prop;
  seg->p2 = sphere->prop;


  seg->next = NULL;
  return seg;
}





t_segment *primitive_Plane(t_ray *r, t_plane *plane)
{
  t_segment *seg;
  double ix,iz;
  double norme;


  norme = 1.0;
  if (r->v.y == 0.0)
    return NULL;
  else
    {
      if (plane->tile != 0.0)
	{
	  ix = fmod(r->q.x + (-r->q.y/r->v.y)*r->v.x, plane->tile*2.0);
	  iz = fmod(r->q.x + (-r->q.y/r->v.y)*r->v.z, plane->tile*2.0);

	  if (ix < 0.0)
	    ix += plane->tile*2.0;

	  if (iz < 0.0)
	    iz += plane->tile*2.0;

	  if ( ((ix >= plane->tile) && (iz < plane->tile)) ||
	       ((ix < plane->tile) && (iz >= plane->tile)) )
	    norme = 0.8;
	}

      seg = segment_Alloc();

      /* mise en place des t parametriques */
      seg->t1 = -r->q.y/r->v.y;
      seg->t2 = HUGE_VAL; /* sense etre + l'infini... pfeu ! */

      /* mise en place des normales */
      seg->n1.x = 0.0;
      seg->n1.y = -1.0;
      seg->n1.z = 0.0;

      seg->n2.x = 0.0;
      seg->n2.y = -1.0;
      seg->n2.z = 0.0;

      /* mise en place des proprietes */
      seg->p1.ambiant.red = plane->prop.ambiant.red*norme;
      seg->p1.ambiant.green = plane->prop.ambiant.green*norme;
      seg->p1.ambiant.blue = plane->prop.ambiant.blue*norme;
      seg->p1.diffuse.red = plane->prop.diffuse.red*norme;
      seg->p1.diffuse.green = plane->prop.diffuse.green*norme;
      seg->p1.diffuse.blue = plane->prop.diffuse.blue*norme;
      seg->p1.specular.red = plane->prop.specular.red*norme;
      seg->p1.specular.green = plane->prop.specular.green*norme;
      seg->p1.specular.blue = plane->prop.specular.blue*norme;
      seg->p1.reflect.red = plane->prop.reflect.red*norme;
      seg->p1.reflect.green = plane->prop.reflect.green*norme;
      seg->p1.reflect.blue = plane->prop.reflect.blue*norme;
			seg->p1.n = plane->prop.n*norme;

			seg->p2 = seg->p1;

      seg->next = NULL;
      return seg;
    }
}