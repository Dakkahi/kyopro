#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

ll mod = 1e9+7;
ll pow_mod(ll a, ll b){
    ll ans = 1;
     ll p =  a;
     for(ll i = 0; i <= 60; i++){
        if((b & (1LL << i)) != 0LL){
            ans *= p;
            ans %= mod; 
        }
        p *= p;
        p %= mod;
     }
     return ans;
}

ll kaijo_mod(ll n){
    ll ans = 1;
    for(ll i = 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }
    return ans;
}

int main(){
    ll H, W;
    cin >> H >> W;
    ll bunshi = kaijo_mod(H+W-2);
    ll bunbo = (kaijo_mod(W-1)*kaijo_mod(H-1))%mod;

    ll ans = (bunshi*pow_mod(bunbo, mod-2))%mod;
    cout << ans << endl;
    return 0;
}