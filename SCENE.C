
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#include "csg.h"
#include "scene.h"
#include "objet.h"
#include "camera.h"
#include "lamp.h"
#include "vecteur.h"
#include "csg_tab.h"
#include "lexyy.h"
#include "scene.h"
#include "csg.h"
#include "camera.h"
#include "objet.h"



extern t_scene *yyparse();


t_scene *scene_Load(char *filename)
{
  FILE *F, *old_F;
  t_scene *scene;



  F = fopen(filename, "r+t");
  if (!F)
    {
      printf("impossible d'ouvrir le fichier '%s'",filename);
      return NULL;
    }

  old_F = yyin;
	yyin = F;

  printf("lecture du fichier '%s'\n", filename);
  current_line = 1;
  scene = (t_scene *)yyparse();

  if (!scene)
    printf("erreur dans le fichier '%s' a la ligne %d\n",filename,current_line);

  fclose(F);
	yyin = old_F;

	return scene;
}





void scene_Free(t_scene *scene)
{
  t_objet *obj;

  /* liberation de la camera */
  free(scene->camera);

  /* liberation de l'arbre csg */
  obj = scene->objets;
  while (obj)
    {
      csg_Free(obj->csg);
      obj = obj->next;
    }

  free(scene);
}