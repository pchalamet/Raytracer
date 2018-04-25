
#ifndef __IMAGE
#define __IMAGE


typedef unsigned char t_pixel;



typedef struct t_image {
  int Width;
  int Height;
  t_pixel **pixels;
} t_image;



t_image *image_Alloc(int width, int height);
void image_Free(t_image *image);
void image_Write(t_image *image, char *filename);



#endif

