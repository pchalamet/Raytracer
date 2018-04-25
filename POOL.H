
#ifndef __POOL
#define __POOL



typedef struct t_pool {
	void *Mem;
	int Size;
	void *Original_Mem;
	int Original_Size;
} t_pool;




t_pool *pool_Allocate(int size);
void pool_Init(t_pool *p);
void *pool_Malloc(t_pool *p, int size);
void pool_Free(t_pool *p);

#endif