
%{


#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

#include "csg.h"
#include "scene.h"
#include "camera.h"
#include "lamp.h"
#include "objet.h"
#include "vecteur.h"
#include "property.h"
#include "lexyy.h"

/* prototypes des fonctions */

void yyerror(char *);
int yywrap(void);



t_camera *h_camera;
t_lamp *h_lamp;
t_properties *h_property;
int h_kind_composante;
double s_ambiant = 0.2;
t_csg *h_csg,*temp_csg,*org_csg;



%}


%union {
	t_csg *csg;
	t_scene *scene;
	t_objet *objet;
	t_camera *camera;
	t_lamp *lamp;
	t_vecteur vecteur;
	t_composante composante;
	double val;
}



%token TK_ERROR

%token TK_PARO
%token TK_PARF
%token TK_CHEVO
%token TK_CHEVF
%token TK_VIRG
%token TK_ACCO
%token TK_ACCF
%token TK_CROCHO
%token TK_CROCHF
%token TK_NEW_SECTION


%token <val> TK_CONST

%token TK_INTERSECTION
%token TK_UNION
%token TK_NEGATION

%token TK_TRANSLATION
%token TK_ROTATION
%token TK_SCALE

%token TK_QUADRIC
%token TK_SPHERE
%token TK_PLANE

%token TK_TILE

%token TK_CAMERA
%token TK_POSITION
%token TK_LOOK_AT
%token TK_SPIN
%token TK_WIDTH
%token TK_HEIGHT
%token TK_FOCAL

%token TK_LAMP
%token TK_INTENSITY

%token TK_AMBIANT
%token TK_DIFFUSE
%token TK_SPECULAR
%token TK_REFLECT
%token TK_ASPECT
%token TK_RED
%token TK_GREEN
%token TK_BLUE


%type <scene> main

%type <camera> camera

%type <lamp> liste_lampes
%type <lamp> lamp

%type <objet> liste_objets
%type <objet> objet
%type <csg> csg

%type <vecteur> vecteur
%type <composante> compo

%start main



%%



main : camera
       TK_NEW_SECTION
       liste_lampes
       TK_NEW_SECTION
       liste_objets
       { $$ = (t_scene *)alloca(sizeof(t_scene));
         $$->camera = $1;
         $$->lamps = $3;
	       $$->objets = $5;
	 $$->ambiant = s_ambiant;
	 return (int)$$; }
     | error { return (int)NULL; }
     ;







camera : TK_CAMERA TK_ACCO
	 { h_camera = (t_camera *)alloca(sizeof(t_camera));
	   h_camera->pos.x = 0.0;
	   h_camera->pos.y = 0.0;
	   h_camera->pos.z = -20.0;
	   h_camera->dir.x = 0.0;
	   h_camera->dir.y = 0.0;
	   h_camera->dir.z = 1.0;
	   h_camera->spin = 0.0;
	   h_camera->width = 64.0;
	   h_camera->height = 40.0;
	   h_camera->focal = 10.0; }
	 params_camera
	 TK_ACCF
	 { $$ = h_camera; }
       ;


params_camera : /* empty */
              | camera_position params_camera
	      | camera_look_at params_camera
	      | camera_spin params_camera
	      | camera_width params_camera
	      | camera_height params_camera
 	      | camera_focal params_camera
	      ;


camera_position : TK_POSITION vecteur
		  { h_camera->pos = $2; }
                ;

camera_look_at : TK_LOOK_AT vecteur
		 { h_camera->dir = $2; }
               ;

camera_spin : TK_SPIN
	      TK_CONST { h_camera->spin = vallex_double; }
	    ;

camera_width : TK_WIDTH
	       TK_CONST { h_camera->width = vallex_double; }
	     ;

camera_height : TK_HEIGHT
		TK_CONST { h_camera->height = vallex_double; }
	      ;

camera_focal : TK_FOCAL
	       TK_CONST { h_camera->focal = vallex_double; }
	     ;






liste_lampes : /* empty */
	       { $$ =NULL; }
	     | lamp liste_lampes
	       { $$ = $1;
		 $$->next = $2; }
	     ;


lamp : TK_LAMP TK_ACCO
       { h_lamp = (t_lamp *)alloca(sizeof(t_lamp));
	 h_lamp->pos.x = 0.0;
	 h_lamp->pos.y = 0.0;
	 h_lamp->pos.z = 0.0;
	 h_lamp->intensity = 1.0; }
	 params_lamp
	 TK_ACCF
	 { $$ = h_lamp; }
     ;

params_lamp : /* empty */
	    | lamp_position params_lamp
	    | lamp_intensity params_lamp
	    ;

lamp_position : TK_POSITION vecteur
		{ h_lamp->pos = $2; }
	      ;

lamp_intensity : TK_INTENSITY
		 TK_CONST { h_lamp->intensity = vallex_double; }
	       ;







liste_objets : /* empty */
	       { $$ = NULL; }
	     | objet liste_objets
	       { $$ = $1;
		 $$->next = $2; }
	     ;

objet : csg
	{ $$ = (t_objet *)alloca(sizeof(t_objet));
	  $$->csg = h_csg; }
      ;


csg : csg_intersection { $$ = h_csg; }
    | csg_union { $$ = h_csg; }
    | csg_negation { $$ = h_csg; }
    | csg_sphere { $$ = h_csg; }
    | csg_plane { $$ = h_csg; }
    ;


csg_intersection : TK_INTERSECTION TK_ACCO
		   csg
		   csg
		   TK_ACCF
		   { h_csg = (t_csg *)alloca(sizeof(t_csg));
		     h_csg->type = CSG_INTERSECTION;
		     h_csg->u_objet.deux_fils.fils_g = $3;
		     h_csg->u_objet.deux_fils.fils_d = $4; }
                 ;


csg_union : TK_UNION TK_ACCO
	    csg
	    csg
	    TK_ACCF
	    { h_csg = (t_csg *)alloca(sizeof(t_csg));
	      h_csg->type = CSG_UNION;
	      h_csg->u_objet.deux_fils.fils_g = $3;
	      h_csg->u_objet.deux_fils.fils_d = $4; }
	  ;


csg_negation : TK_NEGATION TK_ACCO
	       csg
	       TK_ACCF
	       { h_csg = (t_csg *)alloca(sizeof(t_csg));
		 h_csg->type = CSG_NEGATION;
		 h_csg->u_objet.un_fils.fils = $3; }
	     ;




csg_sphere : TK_SPHERE TK_ACCO
	     { h_csg = (t_csg *)alloca(sizeof(t_csg));
	       h_csg->type =CSG_SPHERE;
				 h_csg->u_objet.sphere.prop.ambiant.red = 1.0;
				 h_csg->u_objet.sphere.prop.ambiant.green = 1.0;
				 h_csg->u_objet.sphere.prop.ambiant.blue = 1.0;
				 h_csg->u_objet.sphere.prop.diffuse.red = 1.0;
				 h_csg->u_objet.sphere.prop.diffuse.green = 1.0;
				 h_csg->u_objet.sphere.prop.diffuse.blue = 1.0;
				 h_csg->u_objet.sphere.prop.specular.red = 1.0;
				 h_csg->u_objet.sphere.prop.specular.green = 1.0;
				 h_csg->u_objet.sphere.prop.specular.blue = 1.0;
				 h_csg->u_objet.sphere.prop.reflect.red = 0.0;
				 h_csg->u_objet.sphere.prop.reflect.green = 0.0;
				 h_csg->u_objet.sphere.prop.reflect.blue = 0.0;
 	       h_csg->u_objet.sphere.prop.n = 1.0;
	       h_property = &h_csg->u_objet.sphere.prop; }
	     params_sphere
	     TK_ACCF
	   ;

params_sphere : /* empty */
	      | transformations params_sphere
	      | properties params_sphere
	      ;



csg_plane : TK_PLANE TK_ACCO
	    { h_csg = (t_csg *)alloca(sizeof(t_csg));
	      h_csg->type =CSG_PLANE;
	      h_csg->u_objet.plane.tile = 0.0;
				h_csg->u_objet.plane.prop.ambiant.red = 1.0;
				h_csg->u_objet.plane.prop.ambiant.green = 1.0;
				h_csg->u_objet.plane.prop.ambiant.blue = 1.0;
				h_csg->u_objet.plane.prop.diffuse.red = 1.0;
				h_csg->u_objet.plane.prop.diffuse.green = 1.0;
				h_csg->u_objet.plane.prop.diffuse.blue = 1.0;
				h_csg->u_objet.plane.prop.specular.red = 1.0;
				h_csg->u_objet.plane.prop.specular.green = 1.0;
				h_csg->u_objet.plane.prop.specular.blue = 1.0;
				h_csg->u_objet.plane.prop.reflect.red = 0.0;
				h_csg->u_objet.plane.prop.reflect.green = 0.0;
				h_csg->u_objet.plane.prop.reflect.blue = 0.0;
 	      h_csg->u_objet.plane.prop.n = 1.0;
	      org_csg = h_csg;
	      h_property = &h_csg->u_objet.plane.prop; }
	      params_plane
	    TK_ACCF
	  ;

params_plane : /* empty */
	     | transformations params_plane
	     | properties params_plane
	     | plane_tile
	     ;


plane_tile : TK_TILE TK_CONST
	     { org_csg->u_objet.plane.tile = vallex_double; }
	   ;




transformations : transf_translation
		| transf_rotation
		| transf_scale
		;




transf_translation : TK_TRANSLATION vecteur
		     						 { temp_csg = (t_csg *)alloca(sizeof(t_csg));
		      						 temp_csg->type = CSG_TRANSLATION;
		       						 temp_csg->u_objet.translation.v = $2;
		       						 temp_csg->u_objet.translation.csg = h_csg;
		       						 h_csg = temp_csg; }
                   ;


transf_rotation : TK_ROTATION vecteur
                  { temp_csg = (t_csg *)alloca(sizeof(t_csg));
		    						temp_csg->type = CSG_ROTATION;
		    						temp_csg->u_objet.rotation.r = $2;
		    						temp_csg->u_objet.rotation.csg = h_csg;
		    						h_csg = temp_csg; }
                ;


transf_scale : TK_SCALE vecteur
	       			 { temp_csg = (t_csg *)alloca(sizeof(t_csg));
	         			 temp_csg->type = CSG_SCALE;
		 						 temp_csg->u_objet.scale.s = $2;
								 temp_csg->u_objet.scale.csg = h_csg;
								 h_csg = temp_csg; }
             ;



properties : ambiant
           | diffusion
	   			 | reflection
	   			 | speculaire
	   			 | aspect
	   			 ;



ambiant : TK_AMBIANT compo
          { h_property->ambiant = $2; }
        ;


diffusion : TK_DIFFUSE compo
	    			{ h_property->diffuse = $2 }
	  ;



reflection : TK_REFLECT compo
	     { h_property->reflect = $2 }
           ;


speculaire : TK_SPECULAR compo
	           { h_property->specular = $2 }
	   ;


aspect : TK_ASPECT TK_CONST { h_property->n = vallex_double; }
       ;



vecteur : TK_CHEVO TK_CONST { $2 = vallex_double; }
          TK_VIRG TK_CONST { $5 = vallex_double; }
          TK_VIRG TK_CONST { $8 = vallex_double; }
          TK_CHEVF
	  { $$.x = $2;
	    $$.y = $5;
	    $$.z = $8; }
        ;


compo : TK_CROCHO TK_CONST { $2 = vallex_double; }
          TK_VIRG TK_CONST { $5 = vallex_double; }
          TK_VIRG TK_CONST { $8 = vallex_double; }
          TK_CROCHF
	  { $$.red = $2;
	    $$.green = $5;
	    $$.blue = $8; }
        ;



%%


int yywrap(void)
{
  return(1);
}



void yyerror(char *s)
{
  /* evite que bison sorte des messages affreux... */
}