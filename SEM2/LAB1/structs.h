#pragma once

#include <stdio.h>
#include <stdlib.h>
//#include "typedefs.h"
#include "exit.h"
#include "complex.h"
//#include "float.h"


struct Box {
    //struct RingInfo* ring;
    int type;  // 1-Float, 2-Complex
    void* address;
};

struct Matrix {
    //struct RingInfo* ring;
    int elem_type;  // 1-Float, 2-Complex
    int size;
    struct Box** cells;
};

void* createM();


struct Matrix gen_Matrix(int Size, int Type);

void print_Matrix(struct Matrix M);
