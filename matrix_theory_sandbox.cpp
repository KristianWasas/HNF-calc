#include <iostream>
#include <string.h>

#include <benchmark/benchmark.h>

//Define true if you wish elemnts to be 1 and -1, else they are between -range to range
#define ONES !true

#include "src/matrix.cpp"
#include "src/hermite.cpp"


int main(){
    srand (time(NULL));

    Matrix* intMat = new Matrix(1, 1, 1);

    int format = 0;
    int elementRange = 10;
    bool hasIntMat = false;
    bool quit = false;

    while(!quit){
        printf("Enter input\n");
        bool invalidInput = false;
        std::string input;
        std::getline(std::cin, input); 
        input += '\n';
        switch (input[0])
        {
        //Quit the program
        case 'q':
            if(input[1] == '\n'){ quit = true; }
            else{ invalidInput = true; }
            break;
        //Calculate and print hermite form of matrix currently stored
        case 'h':
            if(input[1] == '\n'){
                if(hasIntMat){
                    intMat->hermite();
                    intMat->print(format);
                }else{ printf("No matrix stored currently\n"); }
            }else{ invalidInput = true; }
            break;
        //Generate new random int/float matrix of size nxm
        case 'r':
            if(input[1] == ' '){
                int count = 2;
                std::string rows = "";
                std::string colums = "";
                int rowNums;
                int columNums;
                while(input[count] != ' '){
                    if(input[count] < '0' || input[count] > '9'){
                        invalidInput = true;
                        break;
                    }else{
                        rows = rows + input[count];
                        count += 1;
                    }
                }
                if(!invalidInput){
                    count += 1;
                    rowNums = std::stoi(rows);
                    if(rowNums == 0){
                        invalidInput = true;
                    }
                    while(input[count] != '\n'){
                        if(input[count] < '0' || input[count] > '9'){
                            invalidInput = true;
                            break;
                        }else{
                            colums = colums + input[count];
                            count += 1;
                        }
                    }
                }
                if(!invalidInput){
                    count += 1;
                    columNums = std::stoi(colums);
                    if(columNums == 0){
                        invalidInput = true;
                    }else{
                        delete(intMat);
                        intMat = new Matrix(rowNums, columNums, elementRange);
                        hasIntMat = true;
                        intMat->print(format);
                    }
                }
            }else{ invalidInput = true; }
            break;
        //Change print format
        case 'f':
            if(input[1] == ' '){
                if(input[3] == '\n'){
                    //Human readable
                    if(input[2] == 'r'){
                        format = 0;
                    //Matlab
                    }else if(input[2] == 'm'){
                        format = 1;
                    //Wolfram alpha
                    }else if(input[2] == 'w'){
                        format = 2;
                    }else{
                        invalidInput = true;
                    }
                }else{
                    invalidInput = true;
                }
            }else{
                invalidInput = true;
            }
            break; 
        //Change element range
        case 's':
            if(input[1] == ' ' && input[2] != '\n'){
                int count = 2;
                std::string size = "";
                while(input[count] != '\n'){
                    if(input[count] < '0' || input[count] > '9'){
                        invalidInput = true;
                        break;
                    }else{
                        size = size + input[count];
                        count += 1;
                    }
                }
                if(!invalidInput){
                    int sizeNum = std::stoi(size);
                    if(sizeNum == 0){
                        invalidInput = true;
                    }else{
                        elementRange = sizeNum;
                    }
                }
            }else{
                invalidInput = true;
            }
            break;   
        default:
            invalidInput = true; 
            break;
        }
        if(invalidInput){
            printf("INVALID INPUT \n");
        }
    }
    return 0;
}
