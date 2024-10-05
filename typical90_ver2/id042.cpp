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
    ll K;
    cin >> K;
    ll mod = 1e9+7;

    ll dp[K+1]; //dp[i]で各位の桁の和がiの倍数
    for(ll i = 0; i <= K; i++) dp[i] = 0;
    dp[0] = 1;

    if(K%9 != 0) cout << 0 << endl;
    else{
        for(ll i = 1; i <= K; i++){
            ll b = min(i, (ll) 9);
            for(ll j = 1; j <= b; j++) {
                dp[i] += dp[i-j];
                dp[i] %= mod;
            }
        }
        cout << dp[K] << endl;
    
    }
    return 0;
}