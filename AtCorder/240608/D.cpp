#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>
using namespace std;
using ll =  unsigned long long;

ll modpow(ll a, ll b, ll mod){
    ll ans = 1;
    ll p = a%mod;
    for(ll i = 0; i <= 60; i++){
        if((b & (1LL << i)) != 0LL){
            ans *= p;
            ans %= mod;
        }
        p  *= p;
        p %= mod;
    }
    return ans;
}

signed main(){
    ll N;
    cin >> N;

    ll mod = 998244353;
    ll k;
    if(N > mod){
        k = N%(mod-1);
    }
    else k = N;
    
    ll ans = modpow(10, k, mod);

    ll bunbo = modpow(9, mod-2, mod);

    ll bunshi = (ans-1)%mod;
    ll Ans = (bunshi*bunbo)%mod;

    ll prod = N%mod;

    ll kotae = (prod*Ans)%mod;
    

    cout << kotae << endl;
    return 0;
}