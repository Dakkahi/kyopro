#include <iostream>
using namespace std;
using ll = long long;

struct mat{
    ll p[2][2] = {{0,0},{0,0}};
};

mat Multi(mat A, mat B, ll mod){
    mat C;
    for(ll i = 0; i< 2; i++){
        for(ll k =0; k < 2; k++){
            for(ll j = 0; j < 2; j++){
                C.p[i][j] += A.p[i][k]*B.p[k][j];
                C.p[i][j] %= mod;
            }
        }
    }
    return C;
}

mat power_mod(mat A, ll N, ll mod){
    mat P = A;
    bool flag = false;
    mat Q;

    for(ll i = 0; i < 60; i++){
        if((N & 1LL << i) != 0LL){
            if(flag == false){
                flag = true;
                Q = P;
            }else{
                Q = Multi(Q, P, mod);
            }
        }
        P = Multi(P, P, mod);
    }
    return Q;
}

int main(){
    ll N;
    cin >> N;

    ll mod = 1000000007;

    mat A;
    A.p[0][0] = 2;
    A.p[0][1] = 1;
    A.p[1][0] = 1;

    A = power_mod(A, N - 1, mod);
    cout << (A.p[1][0] + A.p[1][1])%mod << endl;
    return 0;
}