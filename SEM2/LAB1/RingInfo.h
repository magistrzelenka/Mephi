#include <stdio.h>
#include <stdlib.h>

struct RingInfo {
	size_t size;
	//void* zero;
	//void* one;
	void* (*sum)(void*, void*);
	//void* (*minus)(void*);
	void* (*mult)(void*, void*);
	void* (*skalmult)(void*, double);
};

struct RingInfo* Create(size_t size, void* (*sum)(void*, void*), /*void* (*minus)(void*),*/ void* (*mult)(void*, void*), void* (*skalmult)(void*, double));


//--------------------------------------------------------------------
//RingInfo.c

struct RingInfo* Create(size_t size, void* (*sum)(void*, void*), /*void* (*minus)(void*),*/ void* (*mult)(void*, void*), void* (*skalmult)(void*, double)) {
	struct RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
	//ringInfo->zero = zero;
	//ringInfo->one = one;
	ringInfo->size = size;
	ringInfo->sum = sum;
	//ringInfo->minus = minus;
	ringInfo->mult = mult;
	ringInfo->skalmult = skalmult;
}
//struct RingInfo* Create(size_t size, void* zero, void* one, void* (*sum)(void*, void*), void* (*minus)(void*), void* (*mult)(void*, void*), void* (*skalmult)(void*, double)) {


