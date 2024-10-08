#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;


int main(){
    ll N, Q;
    cin >> N >> Q;
    ll A[N+1];
    ll diff[N+2];
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        
    }
    A[0] = 0;
    for(ll i = 0; i <= N; i++){
        if(i == 0) diff[i] = 0;
        else diff[i] = A[i] - A[i-1];
    }

    ll sum = 0;

    for(ll i = 2; i <= N; i++) sum += abs(diff[i]);

    //cout << sum << endl;

    for(ll i = 1; i <= Q; i++){
        ll L, R, V;
        cin >> L >> R >> V;
        if(L != 1) sum -= abs(diff[L]);
        if(R != N) sum -= abs(diff[R+1]);
        diff[L] += V;
        diff[R+1] -= V;
        if(L != 1)sum += abs(diff[L]);
        if(R != N) sum += abs(diff[R+1]);
        cout << sum << endl;
    }

    return 0;
    
}