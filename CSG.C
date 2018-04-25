
#include <stdlib.h>
#include <stdio.h>


#include "csg.h"





void csg_Free(t_csg *csg)
{
  switch (csg->type)
    {
      /* operation booleenne */
    case CSG_INTERSECTION:
    case CSG_UNION:
      csg_Free(csg->u_objet.deux_fils.fils_g);
      csg_Free(csg->u_objet.deux_fils.fils_d);
      break;

    case CSG_NEGATION:
      csg_Free(csg->u_objet.un_fils.fils);
      break;

      /* transformations */
    case CSG_TRANSLATION:
      csg_Free(csg->u_objet.translation.csg);
      break;

    case CSG_ROTATION:
      csg_Free(csg->u_objet.scale.csg);
      break;

    case CSG_SCALE:
      csg_Free(csg->u_objet.scale.csg);
      break;

      /* objet unitaire */
    case CSG_SPHERE:
      break;

    default:
      printf("Erreur dans l'arbre csg\n");
      exit(5);
    }
  free(csg);
}







void csg_Display(t_csg *csg)
{
}