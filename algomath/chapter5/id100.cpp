#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;

struct matrix{
    double p[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
};

matrix multi(matrix A, matrix B){
    matrix C;
    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 3; j++){
            for(ll k = 0; k < 3; k++){
                C.p[i][j] += A.p[i][k]*B.p[k][j];
            }
        }
    }
    return C;
}

matrix matrix_pow(matrix A, ll n){
    matrix E;
    E.p[0][0] = 1;
    E.p[1][1] = 1;
    E.p[2][2] = 1;
    for(ll i = 0; i <= 30; i++){
        if((n & (1LL << i)) != 0LL){
            E = multi(E,A);
        }
        A = multi(A,A);
    }
    return E;
}


int main(){
    ll Q;
    cin >> Q;
    double X[Q+1], Y[Q+1], Z[Q+1];
    ll T[Q+1];
    for(ll i = 1; i <= Q; i++) cin >> X[i] >> Y[i] >> Z[i] >> T[i];

    

    

    for(ll i = 1; i <= Q; i++){
        matrix S;
        S.p[0][0] = 1-X[i];
        S.p[1][1] = 1-Y[i];
        S.p[2][2] = 1-Z[i];
        S.p[0][1] = Y[i];
        S.p[1][2] = Z[i];
        S.p[2][0] = X[i];
        double a, b, c;
        a = 1; b = 1; c = 1; 

        matrix A = matrix_pow(S, T[i]);
        double new_a = A.p[0][0] * a + A.p[0][1] * b + A.p[0][2] * c;
        double new_b = A.p[1][0] * a + A.p[1][1] * b + A.p[1][2] * c;
        double new_c = 3 - new_a - new_b;//A.p[2][0] * a + A.p[2][1] * b + A.p[2][2] * c;

        cout << fixed << setprecision(15) << new_a << " " << new_b << " " << new_c << endl;
    }

    return 0;
}