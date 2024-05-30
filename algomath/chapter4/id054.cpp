#include <iostream>
using namespace std;

struct Matrix{
    long long p[2][2] = {{0,0}, {0,0}};
};

Matrix Malutiplication(Matrix A, Matrix B){
    Matrix C;
    for(int i = 0; i <= 1; i++){
        for(int k = 0; k <= 1; k++){
            for(int j = 0; j <= 1; j++){
                C.p[i][j] += A.p[i][k]*B.p[k][j];
                C.p[i][j] %= 1000000000;
            }
        }
    }
    return C;
}

Matrix Power(Matrix A, long long n){
    Matrix P = A;
    Matrix Q;
    bool flag = false;
    for(int i = 0; i < 60; i++){}

}


int main(){

}