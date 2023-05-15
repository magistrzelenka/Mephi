/*
#include <stdio.h>
#include <stdlib.h>

#include "complex.h"

void* createC() {
    void* res = malloc(sizeof(Complex));
    (*((Complex*) res)).ring = Create(sizeof(Complex), sumC, multC, skalmultC);
    return res;
}

void* sumC(void* C1, void* C2) {
	void* res = createC();
	(*((Complex*) res)).re = (*((Complex*) C1)).re + (*((Complex*) C2)).re;
	(*((Complex*) res)).im = (*((Complex*) C1)).im + (*((Complex*) C2)).im;
	return res;
}

void* minusC(void* C1, void* C2) {
	void* res = createC();
	(*((Complex*) res)).re = (*((Complex*) C1)).re - (*((Complex*) C2)).re;
	(*((Complex*) res)).im = (*((Complex*) C1)).im - (*((Complex*) C2)).im;
	return res;
}


void* multC(void* C1, void* C2) {
    void* res = createC();
    (*((Complex*) res)).re = (*((Complex*) C1)).re * (*((Complex*) C2)).re - (*((Complex*) C1)).im * (*((Complex*) C2)).im;
    (*((Complex*) res)).im = (*((Complex*) C1)).re * (*((Complex*) C2)).im + (*((Complex*) C2)).re * (*((Complex*) C1)).im;
	return res;
}

void* skalmultC(void* C, double x) {
    void* res = createC();
    (*((Complex*) res)).re = (*((Complex*) C)).re * x;
    (*((Complex*) res)).im = (*((Complex*) C)).im * x;
	return res;
}


Complex gen_Complex() {
    Complex C;
    C.ring = Create(sizeof(Complex), sumC, multC, skalmultC);
    C.re = randdoublefrom(-100.0, 100.0);
    C.im = randdoublefrom(-100.0, 100.0);
    return C;
}


void print_Complex(Complex C) {
    if (C.im >= 0)
        printf("%6.2lf+%6.2lf*i", C.re,  C.im);
    else
        printf("%6.2lf-%6.2lf*i", C.re,  C.im*(-1));
}
*/
