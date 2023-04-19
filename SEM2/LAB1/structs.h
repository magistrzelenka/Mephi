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




//-----------------------------------------------------------------------------------
// structs.c
/*
void* createM() {
    void* res = malloc(sizeof(struct Matrix));
    *((struct Matrix*) res).ring = Create(sizeof(struct Matrix), sumM, minusM, multM, skalmultM);
    return res;
}
*/
struct Matrix gen_Matrix(int Size, int Type) {
    //int Size, Type;
    /*
    printf(">>>Enter Size and Type of Matrix: ");
    scanf("%d %d", &Size, &Type);
    */
    struct Matrix M;
    // int Type = rand() % 2 + 1;  // may be...
    M.elem_type = Type;
    M.size = Size;

    M.cells = calloc(Size, sizeof(struct Box*));
    for (int i = 0; i < Size; ++i) {

        M.cells[i] = calloc(Size, sizeof(struct Box));
        for (int j = 0; j < Size; ++j) {
            // ...here
            if (Type == 1) {
                M.cells[i][j].address = malloc(sizeof(Float));
                *((Float*) M.cells[i][j].address) = gen_Float();
            }
            else if (Type == 2) {
                M.cells[i][j].address = malloc(sizeof(Complex));
                *((Complex*) M.cells[i][j].address) = gen_Complex();
            }
            else {
                terminate_and_exit(3);
            }

            M.cells[i][j].type = Type;
        }
    }
    return M;
};


void print_Matrix(struct Matrix M) {
    int Size = M.size;
    /*
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            int Type = M.cells[i][j].type;
            printf("%d, ", Type);
        }
        printf("\n");
    }
    */
    //printf("[\n");
    printf("\n");
    for (int i = 0; i < Size; ++i) {
        printf("[");
        for (int j = 0; j < Size; ++j) {
            int Type = M.cells[i][j].type;

            if (Type == 1) {
                print_Float(*((Float*) M.cells[i][j].address));
            }
            else if (Type == 2) {
                print_Complex(*((Complex*) M.cells[i][j].address));
            }
            if (j != Size-1) printf(" | ");
        }
        printf("]\n");
    }
    //printf("]\n");
    printf("\n");
}


struct Matrix sumM(struct Matrix M1, struct Matrix M2) {

    int Size1 = M1.size;
    int Size2 = M2.size;
    int Type1 = M1.elem_type;
    int Type2 = M2.elem_type;
    if (Size1 == Size2 && Type1 == Type2) {

        int Size = Size1;
        int Type = Type1;

        struct Matrix M_res;
        M_res.elem_type = Type1;
        M_res.size = Size;

        M_res.cells = calloc(Size, sizeof(struct Box*));
        for (int i = 0; i < Size; ++i) {

            M_res.cells[i] = calloc(Size, sizeof(struct Box));
            for (int j = 0; j < Size; ++j) {

                M_res.cells[i][j].type = Type;
                if (Type == 1) {
                    M_res.cells[i][j].address = createF();
                    *((Float*) M_res.cells[i][j].address) = *((Float*) (*((Float*) M_res.cells[i][j].address)).ring->sum(M1.cells[i][j].address, M2.cells[i][j].address));
                }
                else if (Type == 2) {
                    M_res.cells[i][j].address = createC();
                    *((Complex*) M_res.cells[i][j].address) = *((Complex*)(*((Complex*) M_res.cells[i][j].address)).ring->sum(M1.cells[i][j].address, M2.cells[i][j].address));
                }
            }
        }

        return M_res;
    }
    else if (Size1 != Size2) {
        terminate_and_exit(1);
    }
    else if (Type1 != Type2) {
        terminate_and_exit(2);
    }
}

/*
struct Matrix minusM(struct Matrix M1, struct Matrix M2) {

    int Size1 = M1.size;
    int Size2 = M2.size;
    int Type1 = M1.elem_type;
    int Type2 = M2.elem_type;
    if (Size1 == Size2 && Type1 == Type2) {

        int Size = Size1;
        int Type = Type1;

        struct Matrix M_res;
        M_res.elem_type = Type1;
        M_res.size = Size;

        M_res.cells = calloc(Size, sizeof(struct Box*));
        for (int i = 0; i < Size; ++i) {

            M_res.cells[i] = calloc(Size, sizeof(struct Box));
            for (int j = 0; j < Size; ++j) {

                M_res.cells[i][j].type = Type;
                if (Type == 1) {
                    M_res.cells[i][j].address = createF();
                    *((Float*) M_res.cells[i][j].address) = *((Float*) (*((Float*) M_res.cells[i][j].address)).ring->minus(M1.cells[i][j].address, M2.cells[i][j].address));
                }
                else if (Type == 2) {
                    M_res.cells[i][j].address = createC();
                    *((Complex*) M_res.cells[i][j].address) = *((Complex*)(*((Complex*) M_res.cells[i][j].address)).ring->minus(M1.cells[i][j].address, M2.cells[i][j].address));
                }
            }
        }

        return M_res;
    }
    else if (Size1 != Size2) {
        terminate_and_exit(1);
    }
    else if (Type1 != Type2) {
        terminate_and_exit(2);
    }
}
*/


struct Matrix multM(struct Matrix M1, struct Matrix M2) { //Wrong

    int Size1 = M1.size;
    int Size2 = M2.size;
    int Type1 = M1.elem_type;
    int Type2 = M2.elem_type;
    if (Size1 == Size2 && Type1 == Type2) {

        int Size = Size1;
        int Type = Type1;

        struct Matrix M_res;
        M_res.elem_type = Type1;
        M_res.size = Size;

        M_res.cells = calloc(Size, sizeof(struct Box*));
        for (int i = 0; i < Size; ++i) {

            M_res.cells[i] = calloc(Size, sizeof(struct Box));
            for (int j = 0; j < Size; ++j) {

                M_res.cells[i][j].type = Type;

                if (Type == 1) {
                    M_res.cells[i][j].address = createF();
                    (*((Float*) M_res.cells[i][j].address)).f = 0;
                }
                else if (Type == 2) {
                    M_res.cells[i][j].address = createC();
                    (*((Complex*) M_res.cells[i][j].address)).re = 0;
                    (*((Complex*) M_res.cells[i][j].address)).im = 0;
                }

                for (int k = 0; k < Size; ++k) {
                    if (Type == 1)
                        *((Float*) M_res.cells[i][j].address) = *((Float*) (*((Float*) M_res.cells[i][j].address)).ring->sum(M_res.cells[i][j].address, (*((Float*) M_res.cells[i][j].address)).ring->mult(M1.cells[i][k].address, M2.cells[k][j].address)));
                    else if (Type == 2)
                        *((Complex*) M_res.cells[i][j].address) = *((Complex*) (*((Complex*) M_res.cells[i][j].address)).ring->sum(M_res.cells[i][j].address, (*((Complex*) M_res.cells[i][j].address)).ring->mult(M1.cells[i][k].address, M2.cells[k][j].address)));

                }
            }
        }

        return M_res;
    }
    else if (Size1 != Size2) {
        terminate_and_exit(1);
    }
    else if (Type1 != Type2) {
        terminate_and_exit(2);
    }
}


struct Matrix skalmultM(struct Matrix M, double x) {

    int Size = M.size;
    int Type = M.elem_type;

    struct Matrix M_res;
    M_res.elem_type = Type;
    M_res.size = Size;

    M_res.cells = calloc(Size, sizeof(struct Box*));
    for (int i = 0; i < Size; ++i) {

        M_res.cells[i] = calloc(Size, sizeof(struct Box));
        for (int j = 0; j < Size; ++j) {

            M_res.cells[i][j].type = Type;
            if (Type == 1) {
                M_res.cells[i][j].address = createF();
                *((Float*) M_res.cells[i][j].address) = *((Float*) (*((Float*) M_res.cells[i][j].address)).ring->skalmult(M.cells[i][j].address, x));
            }
            else if (Type == 2) {
                M_res.cells[i][j].address = createC();
                *((Complex*) M_res.cells[i][j].address) = *((Complex*)(*((Complex*) M_res.cells[i][j].address)).ring->skalmult(M.cells[i][j].address, x));
            }
        }
    }

    return M_res;
}


//----------------------------------------------------------------------------------------------------------------
//trashcan

/*
struct Matrix sumM(struct Matrix M1, struct Matrix M2) {

    int Size1 = M1.size;
    int Size2 = M2.size;
    int Type1 = M1.elem_type;
    int Type2 = M2.elem_type;
    if (Size1 == Size2 && Type1 == Type2) {

        int Size = Size1;
        int Type = Type1;

        struct Matrix M_res;
        M_res.elem_type = Type1;
        M_res.size = Size;

        M_res.cells = calloc(Size, sizeof(struct Box*));
        for (int i = 0; i < Size; ++i) {

            M_res.cells[i] = calloc(Size, sizeof(struct Box));
            for (int j = 0; j < Size; ++j) {

                M_res.cells[i][j].type = Type;
                if (Type == 1) {
                    M_res.cells[i][j].address = createF();

                    Float F1;
                    F1 = *((Float*) createF());
                    F1.f = (*((Float*) M1.cells[i][j].address)).f;
                    Float F2;
                    F2 = *((Float*) createF());
                    F2.f = (*((Float*) M2.cells[i][j].address)).f;
                     *((Float*) M_res.cells[i][j].address) = *((Float*) F1.ring->sum(&F1, &F2));
                    //*((Float*) M_res.cells[i][j].address) = sumF(F1, F2);
                    *((Float*) M_res.cells[i][j].address) = *((Float*) (*((Float*) M_res.cells[i][j].address)).ring->sum(M1.cells[i][j].address, M2.cells[i][j].address));
                }
                else if (Type == 2) {
                    M_res.cells[i][j].address = createC();
                    Complex C1 = *((Complex*) M1.cells[i][j].address);
                    Complex C2 = *((Complex*) M2.cells[i][j].address);
                    //*((Complex*) M_res.cells[i][j].address) = *((Complex*) *((Complex*) M_res.cells[i][j]->address).ring->sum(&C1, C2));
                    //*((Complex*) M_res.cells[i][j].address) = sumC(C1, C2);
                }
            }
        }

        return M_res;
    }
    else if (Size1 != Size2) {
        terminate_and_exit(1);
    }
    else if (Type1 != Type2) {
        terminate_and_exit(2);
    }
}
*/













