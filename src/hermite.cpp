#pragma once
#include "matrix.hpp"
#include <algorithm>
#include <numeric>

//Forward declarations, see bottom of file
void DioSolv(int, int, int, int*);
void MxM(int**, int, int, int**, int, int, int);

//Note that H is initialized as M in Matrix constructor, and U is initialized as a identity matrix Ui us Identity
void Matrix::hermite(){
    if(!hermiteCalculated){
        //Variable for 
        int* xy = (int*)malloc(sizeof(int)*2);
        hermiteCalculated = true;
        for(int j=0; j<colums; j++){
            for(int i=rows-1; i>j; i--){
                //First handle the cases were one of the elements is 0, since then its just a premutation matrix
                //And doing Diophantes equation/gcd is kinda wonky behaviour with 0
                //Nothing, since the element we are trying to change to 0 is already 0
                if(H[i][j] == 0){
                    continue;
                //The case that Ui would jsut be a permutation matrix of rows j and j-1
                //Note the 2x2 matrix has to have det = 1, hence the -1
                }else if(H[i-1][j] == 0){
                    Ui[i][i] = 0;
                    Ui[i-1][i] = 1;
                    Ui[i][i-1] = -1;
                    Ui[i-1][i-1] = 0;
                //And the base case as in the lecture notes
                }else{
                    //Calculate values to go into Ui
                    int a = H[i-1][j];
                    int b = H[i][j];
                    int g = std::__gcd(a, b);
                    DioSolv(a, b, g, xy); 
                    int alpha = a/g;
                    int beta  = b/g;

                    //Update Ui
                    Ui[i][i] = alpha;
                    Ui[i][i-1] = -beta;
                    Ui[i-1][i] = xy[1];
                    Ui[i-1][i-1] = xy[0];
                }
                //Calculate new H and U for tracking, note that H and U are replaced with new values
                MxM(Ui, rows, rows, H, rows, colums, i);
                MxM(Ui, rows, rows, U, rows, rows, i);

                //Reset Ui to identity matrix
                Ui[i][i] = 1;
                Ui[i][i-1] = 0;
                Ui[i-1][i] = 0;
                Ui[i-1][i-1] = 1;
            }
        }
        free(xy);
    }
}


int DioSolvRec(int a, int b, int& x, int& y){
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }else{
        int g = DioSolvRec(b, a % b, x, y);
        int x1 = x, y1 = y;
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }
}

void DioSolv(int a, int b, int c, int* xy){
    int x, y;
    int gcd = DioSolvRec(a, b, x, y);

    xy[0] = x * (c / gcd);
    xy[1] = y * (c / gcd);
}

//Note that the matrix B is updated
void MxM(int** A, int a_rows, int a_colums, int** B, int b_rows, int b_colums, int i_row){
    
    //The only elements that are relevant for the multiplication
    int a11 = A[i_row-1][i_row-1];
    int a12 = A[i_row-1][i_row];
    int a21 = A[i_row][i_row-1];
    int a22 = A[i_row][i_row];
    
    for(int j=0; j<b_colums; j++){
        int temp1 = B[i_row-1][j];
        int temp2 = B[i_row][j];
        B[i_row-1][j] = a11*temp1+a12*temp2;
        B[i_row][j] = a21*temp1+a22*temp2;
    }
    /*
    //Naive multiplication implementation
    int** C = (int**)malloc(sizeof(int*)*a_rows);
    for(int i=0; i<a_rows; i++){
        C[i] = (int*)malloc(sizeof(int)*b_colums);
        for(int j=0; j<b_colums; j++){
            int sum = 0;
            for(int k=0; k<a_colums; k++){
                sum = sum + A[i][k]*B[k][j];
            }
            C[i][j] = sum;
        }
    }
    for(int i=0; i<a_rows; i++){
        for(int j=0; j<b_colums; j++){
            B[i][j] = C[i][j];
        }
        free(C[i]);
    }
    free(C);
    */
}