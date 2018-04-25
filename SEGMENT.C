
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

#include "segment.h"






t_segment *segment_Alloc(void)
{
	t_segment *seg;

  seg = (t_segment *)malloc(sizeof(t_segment));
	if (!seg)
	{
		printf("pas assez de memoire dans segment_Alloc()\n");
		exit(5);
	}
	return seg;
}


void segment_Free(t_segment *seg)
{
  t_segment *next;


  while (seg)
    {
      next = seg->next;
      free(seg);
      seg = next;
    }
}







t_segment *segment_Union(t_segment *seg1, t_segment *seg2)
{
  t_segment *seg;


  if (!seg1)
    return seg2;

  if (!seg2)
    return seg1;

  if (seg1->t1 <= seg2->t1)
	  if (seg1->t2 < seg2->t1)
		{
	  	seg1->next = segment_Union(seg1->next, seg2);
		  return seg1;
		}
    else
		{
		  seg2->t1 = seg1->t1;
		  seg2->n1 = seg1->n1;
		  seg2->p1 = seg1->p1;
		  seg = seg1->next;
		  free(seg1);
		  return segment_Union(seg, seg2);
		}
  else
    return segment_Union(seg2, seg1);
}





t_segment *segment_Intersection(t_segment *seg1, t_segment *seg2)
{
  t_segment *seg;


  if (!seg1)
    {
      segment_Free(seg2);
      return NULL;
    }

  if (!seg2)
    {
      segment_Free(seg1);
      return NULL;
    }

  if (seg1->t1 <= seg2->t1)
    if (seg1->t2 < seg2->t1)
		{
		  seg = seg1->next;
		  free(seg1);
		  return segment_Intersection(seg, seg2);
		}
    else
		{
		  seg1->t1 = seg2->t1;
		  seg1->n1 = seg2->n1;
		  seg1->p1 = seg2->p1;
		  seg1->next = segment_Intersection(seg1->next, seg2);
		  return seg1;
		}
  else
    return segment_Intersection(seg2, seg1);
}








static t_segment *segment_NegationRec(t_segment *seg, t_segment *prev)
{
	t_segment *new_seg;

	if (!seg) {
		new_seg = segment_Alloc();
		new_seg->t1 = prev->t2;
		new_seg->n1 = prev->n2;
		new_seg->p1 = prev->p2;
		new_seg->t2 = HUGE_VAL;
		/* mettre des valeurs bidons pour n2 et p2 */
		return new_seg;
	}
	else {
		seg->t1 = prev->t2;
		seg->n1 = prev->n2;
		seg->p1 = prev->p1;
		seg->t2 = seg->t1;
		seg->n2 = seg->n1;
		seg->p2 = seg->p1;
		seg->next = segment_NegationRec(seg->next, seg);
		return seg;
	}
}


t_segment *segment_Negation(t_segment *seg)
{
	t_segment prev;
	t_segment *tmp;
	prev.t2 = -HUGE_VAL;

	/* ~neant = neant, c'est zarbi mais c'est comme ca */
	if (!seg)
		return NULL;
	else if (seg->t1 == -HUGE_VAL) {
		if (seg->t2 == HUGE_VAL)
			return NULL;
		else {
			tmp = segment_NegationRec(seg->next, seg);
			free(seg);
			return tmp;
		}
	}
	else
		return segment_NegationRec(seg, &prev);
}