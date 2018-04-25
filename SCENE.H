

#ifndef __SCENE
#define __SCENE


#include "camera.h"
#include "lamp.h"
#include "objet.h"




typedef struct {
  t_camera *camera;
  t_lamp *lamps;
  t_objet *objets;
  double ambiant;      
} t_scene;



t_scene *scene_Load(char *filename);
void scene_Free(t_scene *scene);

#endif
