#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;


int main(){
    ll N, K;
    cin >> N >> K;
    ll a[N+1][N+1];
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++) cin >> a[i][j];
    }

    ll B[N/K][N/K];
    for(ll i = 0; i < N/K; i++){
        for(ll j = 0; j < N/K; j++) B[i][j] = 0;
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            B[i/K][j/K] += a[i][j];
        }
    }
    for(ll i = 0; i < N/K; i++){
        for(ll j = 0; j < N/K; j++){
            if((j+1)%(N/K) == 0) cout << B[i][j]/(K*K) << endl;
            else cout << B[i][j]/(K*K) << " ";
        }
    }
    return 0;
}