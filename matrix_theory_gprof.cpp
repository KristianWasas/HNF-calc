#include "src/matrix.cpp"
#include "src/hermite.cpp"

int main(){
    
    for(int i=0; i<999; i++){
        Matrix a(64, 64, 10);
        a.hermite();
    }

    return 0;
}