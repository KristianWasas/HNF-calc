#pragma once
#include "matrix.cpp"
#include "hermite.cpp"

//Matrix class
class Matrix {

    public:
        Matrix(int, int, int);
        ~Matrix();

        //Print the matrix, and if the hermite forms have been calculated, them also
        void print(int);

        //Calclute the hermite form
        void hermite();

    private:
        int** elements;
        int rows;
        int colums;

        //Hermite form matrices
        int** U;  //Of size rows*rows
        int** H;  //Of size rows*colums
        int** Ui; //Of size rows*rows, used for hermite calculation, initailized early for speed

        //We dont want to recursevly define hermite form matrices for hermite matrices
        bool hermiteCalculated;
        bool isHermite;
};