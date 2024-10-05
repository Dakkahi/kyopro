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
    ll N, L;
    cin >> N >> L;
    ll dp[N+1];
    ll mod = 1e9+7;
    dp[0] = 1;

    for(ll i = 1; i <= N; i++){
        dp[i] = dp[i-1];
        dp[i] %= mod;
        if(i >= L) {
            dp[i] += dp[i-L];
            dp[i] %= mod;
        }
    }
    cout << dp[N] << endl;
    return 0;
}