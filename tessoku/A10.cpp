#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;


int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    ll M[N+1];
    ll K[N+2];
    K[N+1] = 0; 
    K[0] = 0;
    M[0] = 0;
    A[0] = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        M[i] = max(M[i-1], A[i]);
        //cout << M[i] << endl;
    }

    for(ll i = N; i >= 1; i--) {
        K[i] = max(K[i+1], A[i]);
        //cout << K[i] << endl;
    }

    ll D;
    cin >> D;

    for(ll i = 1; i <= D; i++){
        ll L, R;
        cin >> L >> R;
        cout << max(M[L-1], K[R+1]) << endl;
    }
    return 0;
}