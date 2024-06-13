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
    ll N, Q;
    cin >> N >> Q;
    ll A[N+1], L[Q+1], R[Q+1], V[Q+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    for(ll i = 1; i <= Q; i++) cin >> L[i] >> R[i] >> V[i];

    ll diff[N+1];
    for(ll i = 2; i <= N; i++) {
        diff[i] = A[i] - A[i-1];
    }
    diff[1] = 0;

    ll sum = 0;
    for(ll i = 1; i <= Q; i++){
        if(i == 1){
            if(L[i] != 1) diff[L[i]] += V[i];
            if(R[i] != N) diff[R[i]+1] -= V[i];
        for(ll i = 2; i <= N; i++) sum += abs(diff[i]);
        cout << sum << endl;
        }
        else{
            sum -= (abs(diff[L[i]]) + abs(diff[R[i]+1]));
            if(L[i] != 1) diff[L[i]] += V[i];
            if(R[i] != N) diff[R[i]+1] -= V[i];
            sum += (abs(diff[L[i]]) + abs(diff[R[i]+1]));
            cout << sum << endl;
        }
    }
    return 0;
}