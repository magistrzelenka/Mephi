#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "RingInfo.h"
#include "additionalFunc.h"


typedef struct {
    struct RingInfo* ring;
    float f;
} Float;

//Float F_zero = {.f = 0};
//Float F_one;
void* createF();
void* sumF(void* f1, void* f2);
void* minusF(void* f1, void* f2);
void* multF(void* f1, void* f2);
void* skalmultF(void* F, double x);

Float gen_Float();

void print_Float(Float F);


