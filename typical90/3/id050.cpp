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
    ll mod = 1000000007;
    ll N, L;
    cin >> N >> L;

    ll dp[N+1];
    dp[0] = 1;
    //for(ll i = 1; i <= N; i++) dp[i] = 0;
    for(ll i = 1; i <= N; i++){
        if(i < L) dp[i] = 1;
        else{
            dp[i] = (dp[i-1] + dp[i-L])%mod;
            dp[i] %= mod;
            
        }
    }
    cout << dp[N] << endl;
    return 0;
}