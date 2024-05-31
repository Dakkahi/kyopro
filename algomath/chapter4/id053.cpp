#include <iostream>
using namespace std;
using ll  =long long;

ll modpow(ll a, ll b, ll mod){
    ll ans = 1;
    ll p = a;
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

int main(){
    ll N;
    cin >> N;
    ll mod = 1000000007;

    //等比数列の公式を使うと(4^(N+1)-1)/3となる
    ll above = (modpow(4, N+1, mod) - 1)%mod;
    ll below = 3;

    //フェルマーの小定理より
    ll below_inv = modpow(below, mod - 2, mod);

    ll ans = (above*below_inv)%mod;
    cout << ans << endl;
    return 0;
}