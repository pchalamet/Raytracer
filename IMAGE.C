


#include <stdlib.h>
#include <stdio.h>


#include "image.h"



t_image *image_Alloc(int width, int height)
{
  t_image *image;
  t_pixel *pixels;
  int j;


  image = (t_image *)malloc(sizeof(t_image));
  if (!image)
    return NULL;

  image->Width = width;
  image->Height = height;

  image->pixels = (t_pixel **)malloc(height*sizeof(t_pixel *));
  if (!image->pixels)
    {
      free(image);
      return NULL;
    }

  pixels = (t_pixel *)malloc(width*height*3);
  if (!pixels)
    {
      free(image->pixels);
      free(image);
    }

  for (j=0; j<height; j++)
    image->pixels[j] = pixels+j*width;

  return image;
}


void image_Free(t_image *image)
{
  if (image)
    {
      free(image->pixels[0]);
      free(image->pixels);
      free(image);
    }
}

/* generation d'un fichier PPM */
void image_Write(t_image *image, char *filename)
{
  FILE *F;


  F = fopen(filename, "w+b");
  if (!F)
    {
      printf("impossible d'ouvrir le fichier '%s'\n", filename);
      return;
    }


  fprintf(F,"P6\n%d %d\n255\n", image->Width, image->Height);
  fwrite(image->pixels[0], 3*image->Width*image->Height,1 , F);

  fclose(F);
}

    
    
