#include <stdio.h>
#include <stdlib.h>

#include "float.h"


void* createF() {
    void* res = malloc(sizeof(Float));
    (*((Float*) res)).ring = Create(sizeof(Float), sumF, /*minusF,*/ multF, skalmultF);
    return res;
}

void* sumF(void* F1, void* F2) {
    void* res = createF();
    (*((Float*) res)).f = (*((Float*) F1)).f + (*((Float*) F2)).f;
	return res;
}
/*
void* minusF(void* F1, void* F2) {
	void* res = createF();
    (*((Float*) res)).f = (*((Float*) F1)).f - (*((Float*) F2)).f;
	return res;
}
*/

void* multF(void* F1, void* F2) {
	void* res = createF();
    (*((Float*) res)).f = (*((Float*) F1)).f * (*((Float*) F2)).f;
	return res;
}

void* skalmultF(void* F, double x) {
    void* res = createF();
    (*((Float*) res)).f = (*((Float*) F)).f * x;
	return res;
}


Float gen_Float() {
    Float F;
    //F.ring = Create(sizeof(Float), sumF, minusF, multF, skalmultF);
    F = *((Float*) createF());
    F.f = randfloatfrom(-100, 100);

    return F;
}


void print_Float(Float F) {
    printf("%6.2f", F.f);
}

