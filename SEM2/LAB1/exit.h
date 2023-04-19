#include <stdio.h>
#include <stdlib.h>

void terminate_and_exit(int Error_code);

//----------------------------------------------------------------------------
//exit.c

void terminate_and_exit(int Error_code) {
    switch (Error_code) {
    case 0:
        printf("You may rest now...\n");
        exit(0);
    case 1:
        printf(">>>SUM_ERROR\n>>>SIZES_ARE_NOT_EQUAL\n");
        printf("end of execution\n");
        exit(1);
        break;
    case 2:
        printf(">>>SUM_ERROR\n>>>TYPES_OF_ELEMENTS_IN_MATRIXES_ARE_NOT_THE_SAME\n");
        printf("end of execution\n");
        exit(1);
        break;
    case 3:
        printf(">>>GEN_ERROR\n>>>UNKNOWN_TYPE\n");
        printf("end of execution\n");
        exit(1);
        break;
    default:
        printf(">>>UNKNOWN_ERROR\n");
        printf("end of execution\n");
        exit(1);
        break;
    }
}

