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
ll mod = 1e9 + 7;

int main(){
    ll N, W, L, R;
    cin >> N >> W >> L >> R;
    ll X[N+2];
    ll dp_sum[N+2];
    dp_sum[0] = 1;
    for(ll i = 1; i <= N; i++) {
        cin >> X[i];
    }
    X[0] = 0;
    X[N+1] = W;
    ll dp[N+2]; //dp[i]で足場iまでの行き方
    dp[0] = 1;

    for(ll i = 1; i <= N+1; i++){
        ll posR = lower_bound(X, X+N+2, X[i]-L+1) - X;
        posR -= 1;
        ll posL = lower_bound(X, X+N+2, X[i]- R) - X;
        
        if(posR == -1){
            dp[i] = 0;
        }
        else{
            if(posL >= 1)dp[i] = dp_sum[posR] - dp_sum[posL-1] + mod;
            else dp[i] = dp_sum[posR];
        }
        dp_sum[i] = (dp_sum[i-1] + dp[i])%mod;
        dp[i]%= mod;
    }

    cout << dp[N+1] << endl;
    return 0;
}