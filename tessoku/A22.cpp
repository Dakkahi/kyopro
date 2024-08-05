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
    ll A[N], B[N];
    for(ll i = 1; i <= N-1; i++) cin >> A[i];
     for(ll i = 1; i <= N-1; i++) cin >> B[i];

    ll dp[N+1];
    for(ll i = 1; i <= N; i++) dp[i] = -1000000;
    for(ll i = 1; i <= N-1; i++){
        if(i == 1) dp[i] = 0;
        dp[A[i]] = max(dp[A[i]], dp[i] + 100);
        dp[B[i]] = max(dp[B[i]], dp[i] + 150);
    }
    cout << dp[N] << endl;
    return 0;
}