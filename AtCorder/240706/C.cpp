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
    ll N, K;
    cin >> N >> K;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    sort(A+1, A+N+1);

    ll dp[K+1];

    ll start = 1;
    ll end = N;

    ll m = 1LL << 60;

    for(ll i = 1; i <= K+1; i++){
        ll val = abs(A[i] - A[N-K+i-1]);
        m = min(m, val);
        //cout << val << endl;
    }

    cout << m << endl;
    return 0;
}