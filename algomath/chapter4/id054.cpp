#include <iostream>
using namespace std;
using ll = long long;

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

Matrix Power(Matrix A, ll n){
    Matrix P = A;
    Matrix Q;
    bool flag = false;

    for(ll i = 0; i < 60; i++){
        if((n & (1LL << i)) != 0){
            if(flag == false){
                Q = P;
                flag = true;
            }
            else{
                Q = Malutiplication(Q, P);
            }
        }
        P = Malutiplication(P, P);
    }
    return Q;
}


int main(){
    ll N;
    ll mod = 1000000000;
    cin >> N;
    Matrix A;
    A.p[0][0] = 1;
    A.p[0][1] = 1;
    A.p[1][0] = 1;
    //A.p[1][1] = 0;
    
    Matrix B = Power(A, N-1);

    cout << (B.p[0][0])%mod << endl;
    

    return 0;
}