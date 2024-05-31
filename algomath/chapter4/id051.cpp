#include <iostream>
using namespace std;
using ll  =long long;

ll mod_cal(ll X, ll mod){
    ll ans = 1;
    for(int i = 1; i <= X; i++){
        ans %= mod;
        ll p = i%mod;
        ans *= p;
        ans %= mod;
    }
    return ans;
}

ll modpow(ll a, ll b, ll mod){
    ll ans = 1;
    ll p = a;
    for(ll i = 0; i <= 50; i++){
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
    long long X, Y;
    cin >> X >> Y;

    long long mod = 1000000007; 

    //階乗で求められるので階乗を使って計算する
    ll above = mod_cal(X+Y, mod);
    ll below = (mod_cal(X, mod)*mod_cal(Y, mod))%mod;


    //フェルマーの小定理より，below^(M-1) = 1(modM)なのでabove/belowはもモジュラ逆数よりabove*below^(M-2)を考えれば良い
    ll ans = above*modpow(below, mod-2, mod);
    ans %= mod;
    cout << ans << endl;
    return 0;

}