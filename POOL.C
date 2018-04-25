
#include <stdlib.h>
#include <stdio.h>


#include "pool.h"




/* allocation d'un pool */
t_pool *pool_Allocate(int size)
{
	t_pool *pool;


	pool = (t_pool *)malloc(sizeof(t_pool));
	if (!pool)
		return NULL;

	pool->Original_Size = size;
	pool->Original_Mem = malloc(size);
	if (!pool->Original_Mem)
	{
		free(pool);
		return NULL;
	}

	return pool;
}





/* initialisation d'un pool */
void pool_Init(t_pool *p)
{
	p->Mem = p->Original_Mem;
	p->Size = p->Original_Size;
}





void *pool_Alloc(t_pool *p, int size)
{
	void *t;


	if (p->Size > size)
		{
			p->Size -= size;
			t = p->Mem;
			p->Mem += size;
			return t;
		}
	else
		return NULL;
}





void pool_Free(t_pool *p)
{
	if (p)
	{
		free(p->Original_Mem);
		free(p);
	}
}




