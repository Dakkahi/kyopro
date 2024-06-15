#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll mod = 1000000007;

ll div_mod(ll a){
    return a%mod;
}

int main(){
    ll K;
    cin >> K;
    if(K%9 != 0){
        cout << 0 << endl;
        return 0;
    } 

    else{
        ll dp[K+1];
        for(ll i = 0; i <= K; i++) dp[i] = 0;
        dp[0] = 1;
        for(ll i = 1; i <= K; i++){
            ll b = min(i,(ll) 9);
            for(ll j = 1; j <= b; j++){
                dp[i] += div_mod(dp[i-j]);
                dp[i] = div_mod(dp[i]);
            }
        }
        cout << dp[K] << endl;
        return 0;
    }
    
}