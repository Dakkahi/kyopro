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
    ll D, N;
    cin >> D >> N;
    ll L[N+1], R[N+1], H[N+1];
    ll work[D+1];
    for(ll i = 1; i <= D; i++) work[i] = 24;
    for(ll i = 1; i <=N; i++) {
        cin >> L[i] >> R[i] >> H[i];
    }

    for(ll i = 1; i <= N; i++){
        for(ll j = L[i]; j <= R[i]; j++) work[j] = min(work[j], H[i]);
    }

    ll sum = 0;
    for(ll i = 1; i <= D; i++){
        sum += work[i];
    }
    cout << sum << endl;
    return 0;
}