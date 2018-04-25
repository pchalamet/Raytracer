
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>

#include "raytrace.h"
#include "ray.h"
#include "segment.h"
#include "csg.h"
#include "primitive.h"
#include "objet.h"
#include "inter.h"
#include "intensity.h"




#define SCREEN_X 320
#define SCREEN_Y 200
#define ASPECT_RATIO ((double)SCREEN_X / (double)SCREEN_Y)




#define sq(x) ((x)*(x))

#define EPSILON (1e-10)



/* intersection d'un rayon avec un arbre csg */
t_segment *raytrace_CSG_Intersect(t_csg *csg, t_ray *r)
{
  t_ray new_ray;
  t_segment *seg,*temp;
	double mat[3][3];


  switch (csg->type)
    {
      /* operations booleenes */
    	case CSG_INTERSECTION:
      	return segment_Intersection(raytrace_CSG_Intersect(csg->u_objet.deux_fils.fils_g, r),
				  													raytrace_CSG_Intersect(csg->u_objet.deux_fils.fils_d, r));

    	case CSG_UNION:
      	return segment_Union(raytrace_CSG_Intersect(csg->u_objet.deux_fils.fils_g, r),
			  										 raytrace_CSG_Intersect(csg->u_objet.deux_fils.fils_d, r));

    	case CSG_NEGATION:
      	return segment_Negation(raytrace_CSG_Intersect(csg->u_objet.un_fils.fils, r));


      /* transformations */
    	case CSG_TRANSLATION:
      	new_ray.q.x = r->q.x - csg->u_objet.translation.v.x;
      	new_ray.q.y = r->q.y - csg->u_objet.translation.v.y;
      	new_ray.q.z = r->q.z - csg->u_objet.translation.v.z;
      	new_ray.v.x = r->v.x;
      	new_ray.v.y = r->v.y;
      	new_ray.v.z = r->v.z;
     	 	seg = raytrace_CSG_Intersect(csg->u_objet.translation.csg, &new_ray);
      	return seg;

   	 	case CSG_ROTATION:
#define ALPHA (180.0*csg->u_objet.rotation.r.x/M_PI)
#define BETA (180.0*csg->u_objet.rotation.r.y/M_PI)
#define GAMMA (180.0*csg->u_objet.rotation.r.z/M_PI)

				mat[0][0] = cos(GAMMA)*cos(BETA);
				mat[0][1] = -sin(GAMMA)*cos(ALPHA)+cos(GAMMA)*sin(BETA)*sin(ALPHA);
				mat[0][2] = sin(GAMMA)*sin(ALPHA)+cos(GAMMA)*sin(BETA)*cos(ALPHA);
				mat[1][0] = sin(GAMMA)*cos(BETA);
				mat[1][1] = cos(GAMMA)*cos(ALPHA)-sin(GAMMA)*sin(BETA)*sin(ALPHA);
				mat[1][2] = -cos(GAMMA)*sin(ALPHA)+sin(GAMMA)*sin(BETA)*cos(ALPHA);
				mat[2][0] = -sin(BETA);
				mat[2][1] = cos(BETA)*sin(ALPHA);
				mat[2][2] = cos(BETA)*cos(ALPHA);

				new_ray.q.x = r->q.x*mat[0][1] + r->q.y*mat[0][1] + r->q.z*mat[0][2];
				new_ray.q.y = r->q.x*mat[1][1] + r->q.y*mat[1][1] + r->q.z*mat[1][2];
				new_ray.q.z = r->q.x*mat[2][1] + r->q.y*mat[2][1] + r->q.z*mat[2][2];

				new_ray.v.x = r->v.x*mat[0][1] + r->v.y*mat[0][1] + r->v.z*mat[0][2];
				new_ray.v.y = r->v.x*mat[1][1] + r->v.y*mat[1][1] + r->v.z*mat[1][2];
				new_ray.v.z = r->v.x*mat[2][1] + r->v.y*mat[2][1] + r->v.z*mat[2][2];

				seg = raytrace_CSG_Intersect(csg->u_objet.rotation.csg, &new_ray);

      	/* mise a jour des vecteurs normaux la rotation */
				mat[0][0] = cos(-GAMMA)*cos(-BETA);
				mat[0][1] = -sin(-GAMMA)*cos(-ALPHA)+cos(-GAMMA)*sin(-BETA)*sin(-ALPHA);
				mat[0][2] = sin(-GAMMA)*sin(-ALPHA)+cos(-GAMMA)*sin(-BETA)*cos(-ALPHA);
				mat[1][0] = sin(-GAMMA)*cos(-BETA);
				mat[1][1] = cos(-GAMMA)*cos(-ALPHA)-sin(-GAMMA)*sin(-BETA)*sin(-ALPHA);
				mat[1][2] = -cos(-GAMMA)*sin(-ALPHA)+sin(-GAMMA)*sin(-BETA)*cos(-ALPHA);
				mat[2][0] = -sin(-BETA);
				mat[2][1] = cos(-BETA)*sin(-ALPHA);
				mat[2][2] = cos(-BETA)*cos(-ALPHA);

      	temp = seg;
      	while (temp)
				{
					new_ray.q.x = temp->n1.x*mat[0][1] + temp->n1.y*mat[0][1] + temp->n1.z*mat[0][2];
					new_ray.q.y = temp->n1.x*mat[1][1] + temp->n1.y*mat[1][1] + temp->n1.z*mat[1][2];
					new_ray.q.z = temp->n1.x*mat[2][1] + temp->n1.y*mat[2][1] + temp->n1.z*mat[2][2];
					temp->n1 = new_ray.q;

					new_ray.q.x = temp->n2.x*mat[0][1] + temp->n2.y*mat[0][1] + temp->n2.z*mat[0][2];
					new_ray.q.y = temp->n2.x*mat[1][1] + temp->n2.y*mat[1][1] + temp->n2.z*mat[1][2];
					new_ray.q.z = temp->n2.x*mat[2][1] + temp->n2.y*mat[2][1] + temp->n2.z*mat[2][2];
					temp->n2 = new_ray.q;

					temp = temp->next;
				}
				return seg;


    	case CSG_SCALE:
      	new_ray.q.x = r->q.x / csg->u_objet.scale.s.x;
      	new_ray.q.y = r->q.y / csg->u_objet.scale.s.y;
      	new_ray.q.z = r->q.z / csg->u_objet.scale.s.z;
      	new_ray.v.x = r->v.x / csg->u_objet.scale.s.x;
      	new_ray.v.y = r->v.y / csg->u_objet.scale.s.y;
      	new_ray.v.z = r->v.z / csg->u_objet.scale.s.z;
      	seg = raytrace_CSG_Intersect(csg->u_objet.scale.csg, &new_ray);

      	/* mise a jour des vecteurs normaux pour l'homothetie */
      	temp = seg;
      	while (temp)
				{
	  			temp->n1.x *= csg->u_objet.scale.s.x;
	  			temp->n1.y *= csg->u_objet.scale.s.y;
	  			temp->n1.z *= csg->u_objet.scale.s.z;
	  			temp->n2.x *= csg->u_objet.scale.s.x;
	  			temp->n2.y *= csg->u_objet.scale.s.y;
	  			temp->n2.z *= csg->u_objet.scale.s.z;
	  			temp = temp->next;
				}
				return seg;



    	/* objet unitaire */
   		case CSG_QUADRIC:
      	return primitive_Quadric(r, &csg->u_objet.quadric);

    	case CSG_SPHERE:
      	return primitive_Sphere(r, &csg->u_objet.sphere);

    	case CSG_PLANE:
      	return primitive_Plane(r, &csg->u_objet.plane);


      /* erreur */
    	default:
      	printf("Erreur dans l'arbre csg\n");
      	exit(5);
    }
}




/* retourne le point d'intersection le plus proche avec un objet */
void raytrace_Object_Intersection(t_csg *csg, t_ray *r, t_inter *inter)
{
  t_segment *seg, *temp;

  /* recherche de l'intersection du rayon avec cet objet */
  seg = raytrace_CSG_Intersect(csg, r);

  inter->intersection = 0;
  temp = seg;
  while (temp)
    {
      if (temp->t1 > EPSILON)
			{
	  		inter->intersection = 1;
	  		inter->t = temp->t1;
	  		inter->n = temp->n1;
				vecteur_Normalize(&inter->n);
	  		inter->prop = temp->p1;
	  		segment_Free(seg);
	  		return;
			}

      if (temp->t2 > EPSILON)
			{
	  		inter->intersection = 1;
	  		inter->t = temp->t2;
	  		inter->n = temp->n2;
				vecteur_Normalize(&inter->n);
	  		inter->prop = temp->p2;
	  		segment_Free(seg);
	  		return;
			}

      temp = temp->next;
    }

  segment_Free(seg);
}




void raytrace_Nearest_Intersection(t_scene *scene, t_ray *r, t_inter *inter)
{
  t_objet *temp;
  t_inter temp_inter;


  inter->intersection = 0;
  inter->t = HUGE_VAL;
  temp = scene->objets;
  while (temp)
    {
      raytrace_Object_Intersection(temp->csg, r, &temp_inter);
      /* s'il y a intersection et que c'est plus proche alors on garde */
      if ( temp_inter.intersection &&
	   		   (temp_inter.t < inter->t) )
				*inter = temp_inter;

      temp = temp->next;
    }
}




/* balance un rayon contre tous les objets, retourne l'intensite resultante */
t_intensity raytrace_Launch(t_scene *scene, t_ray *r, double distance)
{
  t_lamp *lamp;
  t_intensity I, Id, Is, Ir;
  t_inter inter, lamp_inter;
  t_ray lamp_ray;
  double dist, dist_lamp;
	double cos_theta, cos_alpha, coef;
  t_vecteur rr;


  I.red = 0.0;
  I.green = 0.0;
  I.blue = 0.0;


  /* regarde si le rayon n'aurait pas parcouru une trop grande distance */
  if (distance > 200.0)
    return I;


  /* recherche de l'intersection la plus proche */
  raytrace_Nearest_Intersection(scene, r, &inter);


  /* si pas d'intersection alors on sort */
  if (!inter.intersection)
    return I;


  /***********************************/
  /* calcul de l'intensite lumineuse */
  /***********************************/

  /* lumiere ambiante */
	I.red += scene->ambiant * inter.prop.ambiant.red;
  I.green += scene->ambiant * inter.prop.ambiant.green;
  I.blue += scene->ambiant * inter.prop.ambiant.blue;

  /* lumiere diffuse et speculaire */
  lamp = scene->lamps;
  lamp_ray.q.x = r->q.x+inter.t*r->v.x;
  lamp_ray.q.y = r->q.y+inter.t*r->v.y;
  lamp_ray.q.z = r->q.z+inter.t*r->v.z;
  dist = sqrt(sq(lamp_ray.q.x-r->q.x) + sq(lamp_ray.q.y-r->q.y) + sq(lamp_ray.q.z-r->q.z));
  while (lamp)
    {
      lamp_ray.v.x = lamp->pos.x - lamp_ray.q.x;
      lamp_ray.v.y = lamp->pos.y - lamp_ray.q.y;
      lamp_ray.v.z = lamp->pos.z - lamp_ray.q.z;
			dist_lamp = vecteur_Norme(&lamp_ray.v);
			vecteur_Normalize(&lamp_ray.v);

      /* la lampe eclaire le point ? */
      raytrace_Nearest_Intersection(scene, &lamp_ray, &lamp_inter);
      if (lamp_inter.t/dist_lamp >= 1.0)
			{
				/* cosinus entre le rayon vers la lampe et la normale */
	  		cos_theta = lamp_ray.v.x*inter.n.x + lamp_ray.v.y*inter.n.y + lamp_ray.v.z*inter.n.z;
	  		if (cos_theta > 0.02)
	    		{
     				/*******************/
   	  			/* lumiere diffuse */
     				/*******************/
	      		Id.red = inter.prop.diffuse.red * cos_theta;
	      		Id.green = inter.prop.diffuse.green * cos_theta;
	      		Id.blue = inter.prop.diffuse.blue * cos_theta;

     				/**********************/
     				/* lumiere speculaire */
     				/**********************/
						cos_theta *= 2.0;
						rr.x = inter.n.x*cos_theta - lamp_ray.v.x;
     				rr.y = inter.n.y*cos_theta - lamp_ray.v.y;
     				rr.z = inter.n.z*cos_theta - lamp_ray.v.z;
	      		cos_alpha = -r->v.x*rr.x - r->v.y*rr.y - r->v.z*rr.z;
						if (cos_alpha > 0.02)
							{
								coef = pow(cos_alpha, inter.prop.n);
	       				Is.red = inter.prop.specular.red * coef;
	      				Is.green = inter.prop.specular.green * coef;
	      				Is.blue = inter.prop.specular.blue * coef;
							}
						else
							{
								Is.red = 0.0;
								Is.green = 0.0;
								Is.blue = 0.0;
							}

	      		/* calcul final de l'intensite pour cette lampe */
  	    		I.red += (lamp->intensity * (Id.red + Is.red)) / (dist_lamp + dist);
    	   		I.green += (lamp->intensity * (Id.green + Is.green)) / (dist_lamp + dist);
      			I.blue += (lamp->intensity * (Id.blue + Is.blue)) / (dist_lamp + dist);
	 				}
			}

      lamp = lamp->next;
    }


  /*********************/
  /* lumiere reflechie */
  /*********************/
  if ( (inter.prop.reflect.red != 0.0) ||
       (inter.prop.reflect.green != 0.0) ||
       (inter.prop.reflect.blue != 0.0) )
    {
      cos_theta = -2.0*(r->v.x*inter.n.x + r->v.y*inter.n.y + r->v.z*inter.n.z);
			lamp_ray.v.x = inter.n.x*cos_theta + r->v.x;
      lamp_ray.v.y = inter.n.y*cos_theta + r->v.y;
      lamp_ray.v.z = inter.n.z*cos_theta + r->v.z;
			vecteur_Normalize(&lamp_ray.v);

      Ir = raytrace_Launch(scene, &lamp_ray,distance+dist);
      I.red += inter.prop.reflect.red * Ir.red;
      I.green += inter.prop.reflect.green * Ir.green;
      I.blue += inter.prop.reflect.blue * Ir.blue;
    }


  /* test la validite de l'intensite */
  if (I.red > 1.0)
    I.red = 1.0;

  if (I.green > 1.0)
    I.green = 1.0;

  if (I.blue > 1.0)
    I.blue = 1.0;

  return I;
}







/* calcul de tous les pixels de l'image */
t_image *raytrace_Compute(t_scene *scene)
{
  double pos_x,pos_y,pos_z;
  double inc_x,inc_y;
  int i,j;
  t_ray r;
  t_image *image;
  t_pixel *pixel;
  t_intensity intens;



  image = image_Alloc(SCREEN_X, SCREEN_Y);
  if (!image)
    {
      printf("impossible d'allouer une image\n");
      return NULL;
    }

  pixel = image->pixels[0];


  inc_x = (scene->camera->width/(double)SCREEN_X) * ASPECT_RATIO;
  inc_y = scene->camera->height/(double)SCREEN_Y;

  pos_y = -(double)(SCREEN_Y/2)*inc_y;
  pos_z = 0.0;

  for (j=0; j<SCREEN_Y; j++)
    {
      printf("rendering %%%d\r", (int)(100.0*(double)(j*SCREEN_X)/(double)(SCREEN_X*SCREEN_Y)));
      fflush(stdout);

      pos_x = -(double)(SCREEN_X/2)*inc_x;
      for (i=0; i<SCREEN_X; i++)
	{
	  /* mise en place du vecteur de vision */
	  r.q.x = scene->camera->pos.x;
	  r.q.y = scene->camera->pos.y;
	  r.q.z = scene->camera->pos.z;

	  r.v.x = pos_x - r.q.x;
	  r.v.y = pos_y - r.q.y;
	  r.v.z = pos_z - r.q.z;
		vecteur_Normalize(&r.v);


	  /* calcul du point */
		intens = raytrace_Launch(scene, &r, 0.0);
	  *pixel++ = (int)(intens.red*255.0);
	  *pixel++ = (int)(intens.green*255.0);
	  *pixel++ = (int)(intens.blue*255.0);

	  pos_x += inc_x;
	}
      pos_y += inc_y;
    }

  printf("\n");
  return image;
}