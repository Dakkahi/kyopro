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
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll L[N+1];
    ll dp[N+1];
    ll len = 0;

    for(ll i = 1; i <= N; i++){
        dp[i] = 0;
        L[i] = 1e9;
    }

    for(ll i = 1; i <= N; i++){
        ll x = lower_bound(L+1, L+len+1, A[i]) - L;
        dp[i] = x;

        L[x] = A[i];
        if(x > len) len ++;
        
    }

    cout << len << endl;
    return 0;
}