#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "RingInfo.h"
#include "complex.h"
#include "float.h"
#include "Matrix.h"
#include "exit.h"
//#include "test.h"


void menu(struct Matrix* M_data);


int main() {

    srand(time(NULL));

    printf(">>>Hello! This program is made to test struct Square Matrix (SEM2LAB1VAR12).\n");
    struct Matrix* M_data;
    menu(M_data);

    return 0;
}



void menu(struct Matrix* M_data) {
    printf("INSTRUCTIONS:\nFirst, you need to generate required quantity of matrices and then, do any operations with them\n\n");
    int cnt = 0, command = 0, ind, ind1, ind2, data_size = 20;
    M_data = calloc(data_size, sizeof(struct Matrix));

    while (true) {

        printf(">>>MENU:\n");
        printf(">>>>>>use '1' to GEN matrix No[%d]\n", cnt);
        printf(">>>>>>use '2' to PRINT matrix you want(INDEX)\n");
        printf(">>>>>>use '3' to SUM 2 matrices\n");
        printf(">>>>>>use '4' to MULT 2 matrices\n");
        printf(">>>>>>use '5' to SKALMULT 2 matrices\n");
        printf(">>>>>>use '0' to END running\n");
        printf(">>>enter command: ");
        scanf("%d", &command);
        printf("\n");

        switch(command) {
        case 1:
            int Size, Type;
            printf(">>>Enter Size and Type(1 - Float, 2 - Complex) of Matrix: ");
            scanf("%d %d", &Size, &Type);
            M_data[cnt] = gen_Matrix(Size, Type);
            print_Matrix(M_data[cnt]);
            cnt++;
            printf("\n");
            break;
        case 2:
            printf(">>>Enter index: ");
            scanf("%d", &ind); //WWWWWWWAAAAAAARRRRRRRNNNNNIIIIIINNNNNGGGGGG "&"
            print_Matrix(M_data[ind]);
            printf("\n");
            break;

        case 3:
            printf(">>>Enter indexes of 2 matrices: ");
            scanf("%d%d", &ind1, &ind2);
            M_data[cnt] = sumM(M_data[ind1], M_data[ind2]);
            print_Matrix(M_data[cnt]);
            cnt++;
            printf("\n");
            break;

        case 4:
            printf(">>>Enter indexes of 2 matrices: ");
            scanf("%d%d", &ind1, &ind2);
            M_data[cnt] = multM(M_data[ind1], M_data[ind2]);
            print_Matrix(M_data[cnt]);
            cnt++;
            printf("\n");
            break;

        case 5:
            double x;
            printf(">>>Enter index of matrix and scalar: ");
            scanf("%d%lf", &ind, &x);
            M_data[cnt] = skalmultM(M_data[ind], x);
            print_Matrix(M_data[cnt]);
            cnt++;
            printf("\n");
            break;
        case 0:
            terminate_and_exit(0);
            break;
        default:
            printf(">>>UNKOWN_COMMAND\n");
            break;
        }
        scanf("*[^\n]");
    }
}

