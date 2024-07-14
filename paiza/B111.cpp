#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    ll sum = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    ll G[(1LL << N)+1];
    for(ll i = 1; i <= (1LL << N); i++){
        G[i] = 0;
        for(ll j = 0; j < N; j++){
            if((i & (1LL << j)) != 0) G[i] += A[j+1];
        }
    }

    ll M = sum;
    for(ll i = 1; i <= (1LL << N); i++){
        M = min(M, abs(sum - 2*G[i]));
    }
    cout << M << endl;
    return 0;
}