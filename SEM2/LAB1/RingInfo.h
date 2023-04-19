#pragma once

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
