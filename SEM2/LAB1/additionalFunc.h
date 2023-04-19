#include <stdio.h>
#include <stdlib.h>

float randfloatfrom(float min, float max);
double randdoublefrom(double min, double max);
void SWAP(void* a, void* b, size_t len);

//-------------------------------------------------------------
//additionalFunc.c

float randfloatfrom(float min, float max) {
    float range = (max - min);
    float div = RAND_MAX / range;
    return min + (rand() / div);
}

double randdoublefrom(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void SWAP(void* a, void* b, size_t len) {
    unsigned char* p = a;
    unsigned char* q = b;
    unsigned char tmp;
    for (size_t i = 0; i != len; ++i) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}
