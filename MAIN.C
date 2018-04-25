
#include <stdio.h>


#include "scene.h"
#include "raytrace.h"
#include "objet.h"
#include "image.h"




int main(int argc, char *argv[])
{
  t_scene *scene;
  t_image *image;
  

  if (argc != 3)
    {
      printf("usage:\n %s <in file> <out file\n",argv[0]);
      return 5;
    }

  scene = scene_Load(argv[1]);

  if (!scene)
    return 5;

  image = raytrace_Compute(scene);

  if (image)
    {
      printf("sauvegarde de l'image\n");
      image_Write(image, argv[2]);
      return 0;
    }
  else
    return 5;
}
