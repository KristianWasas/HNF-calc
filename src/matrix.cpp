#pragma once
#include "hermite.cpp"
#include "matrix.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>

Matrix::Matrix(int n, int m, int elementRange){
    //Make sure no infinite loop is created, ie. only calculate hermite matricies once
    hermiteCalculated = false;
    rows = n;
    colums = m;
    //Reserve memory for matrix and its hermite form
    elements = (int**)malloc(sizeof(int*)*rows);
    H = (int**)malloc(sizeof(int*)*rows);
    U = (int**)malloc(sizeof(int*)*rows);

    for(int i=0; i<rows; i++){
        elements[i] = (int*)malloc(sizeof(int)*colums);
        H[i] = (int*)malloc(sizeof(int)*colums);
        U[i] = (int*)malloc(sizeof(int)*rows);
        //Generate random floats/ints between -100 and 100 for the matrix
        for(int j=0; j<colums; j++){
            float a = (float)(rand()) / (float)(RAND_MAX);
            //int b = a * 2.f + 1;
            //int c = b*2 - 3;
            //elements[i][j] = (int)(c);       //Just for generating matrix with -1 and 1 elements for testing
            elements[i][j] = (int)((a) * (float)(2*elementRange) - (float)(elementRange));
            H[i][j] = elements[i][j];
        }
        for(int j=0; j<rows; j++){
            U[i][j] = 0;
        }
        U[i][i] = 1;
    }

    //Create the simple matrix Ui for hermite calculations
    Ui = (int**)malloc(sizeof(int*)*rows);
    for(int i=0; i<rows; i++){
        Ui[i] = (int*)malloc(sizeof(int)*rows);
        for(int j=0; j<rows; j++){
            Ui[i][j] = 0;
        }
        Ui[i][i] = 1;
    }

}

Matrix::~Matrix(){
    for(int i=0; i<rows; i++){
        free(Ui[i]);
        free(U[i]);
        free(H[i]);
        free(elements[i]);
    }
    free(Ui);
    free(U);
    free(H);
    free(elements);
}

void Matrix::print(int format){

    printf("Printing the matrix M\n");
    if(format == 0){
        for(int i=0; i<rows; i++){
            for(int j=0; j<colums; j++){
                printf("%d\t", elements[i][j]);
            }
            printf("\n");
        }

        if(!isHermite && hermiteCalculated){
            printf("Printing matrices U, H such that UM=H and H is in HNF and U is unimodular\nU is \n");
            for(int i=0; i<rows; i++){
                for(int j=0; j<rows; j++){
                    printf("%d\t", U[i][j]);
                }
                printf("\n");
            }
            printf("and H is\n");
            for(int i=0; i<rows; i++){
                for(int j=0; j<colums; j++){
                    printf("%d\t", H[i][j]);
                }
                printf("\n");
            }
        }else if(!isHermite && !hermiteCalculated){
            printf("Hermite form is not calclulated yet\n");
        }
    }else if(format == 1){
        printf("M=[");
        for(int i=0; i<rows; i++){
            for(int j=0; j<colums; j++){
                printf("%d", elements[i][j]);
                if(j != colums-1){
                    printf(",");
                }
            }
            if(i != rows-1){
                printf(";\n");
            }else{
                printf("];\n");
            } 
        }

        if(!isHermite && hermiteCalculated){
            printf("U=[");
            for(int i=0; i<rows; i++){
                for(int j=0; j<rows; j++){
                    printf("%d", U[i][j]);
                    if(j != rows-1){
                        printf(",");
                    }
                }
                if(i != rows-1){
                    printf(";\n");
                }else{
                    printf("];\n");
                } 
            }
            printf("H=[");
            for(int i=0; i<rows; i++){
                for(int j=0; j<colums; j++){
                    printf("%d", H[i][j]);
                    if(j != colums-1){
                        printf(",");
                    }
                }
                if(i != rows-1){
                    printf(";\n");
                }else{
                    printf("];\n");
                } 
            }
        }else if(!isHermite && !hermiteCalculated){
            printf("Hermite form is not calclulated yet\n");
        }
    }else{
        printf("M={");
        for(int i=0; i<rows; i++){
            printf("{");
            for(int j=0; j<colums; j++){
                printf("%d", elements[i][j]);
                if(j != colums-1){
                    printf(",");
                }
            }
            if(i != rows-1){
                printf("},\n");
            }else{
                printf("}}\n");
            } 
        }

        if(!isHermite && hermiteCalculated){
            printf("U={");
            for(int i=0; i<rows; i++){
                printf("{");
                for(int j=0; j<rows; j++){
                    printf("%d", U[i][j]);
                    if(j != rows-1){
                        printf(",");
                    }
                }
                if(i != rows-1){
                    printf("},\n");
                }else{
                    printf("}}\n");
                } 
            }
            printf("H={");
            for(int i=0; i<rows; i++){
                printf("{");
                for(int j=0; j<colums; j++){
                    printf("%d", H[i][j]);
                    if(j != colums-1){
                        printf(",");
                    }
                }
                if(i != rows-1){
                    printf("},\n");
                }else{
                    printf("}}\n");
                } 
            }
        }else if(!isHermite && !hermiteCalculated){
            printf("Hermite form is not calclulated yet\n");
        }
    }
}