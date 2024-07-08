#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N, M, S;
    cin >> N >> M;
    cin >> S;
    ll L = max(M, N);
    ll T[S+1], X[S+1], Y[S+1];
    for(ll i = 1; i <= S; i++) cin >> T[i] >> X[i] >> Y[i];

    ll F[3*L+1][3*L+1];
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++) F[L+i][L+j] = 0; //これで(i,j)成分の扱いとする
    }
    for(ll i = 1; i <= S; i++){
        ll len = (T[i] - 1)/2;
        if(T[i] > 1){
            for(ll j = 1; j <= T[i]; j++){
                F[L+Y[i]-len+j-1][L+X[i]-len] ++;
                F[L+Y[i]-len+j-1][L+X[i]+len] ++;
                F[L+Y[i]-len][L+X[i]-len+j-1] ++;
                F[L+Y[i]+len][L+X[i]-len+j-1] ++;
            }
            F[L+Y[i]-len][L+X[i]-len] --;
            F[L+Y[i]+len][L+X[i]-len] --;
            F[L+Y[i]-len][L+X[i]+len] --;
            F[L+Y[i]+len][L+X[i]+len] --;
        }else F[L+Y[i]][L+X[i]] ++;
    }
    for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= M; j++){
                if(j%M == 0) cout << F[L+i][L+j] << endl;
                else cout << F[L+i][L+j] << " ";
            }
    }
    return 0;



}