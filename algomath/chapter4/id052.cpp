#include <iostream>
using namespace std;
using ll  =long long;

ll kaijo_mod_cal(ll X, ll mod){
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
        p *= p;
        p %= mod;
    }
    return ans;
}

int main(){
    ll X, Y;
    cin >> X >> Y; //そもそもX+Yが3の倍数でないとその駒には進めない

    long long mod = 1000000007;
    ll a = (-X + 2*Y);
        ll b = (2*X - Y);

    if((a%3 != 0) ||  (b%3 != 0)) cout << 0 << endl;
    //コーナーケースとして，aとbの差が2倍より大きいと無理
    
    else if(b < 0 || a < 0) cout << 0 << endl;

    else{
        a /= 3;
        b /= 3;
        ll above = kaijo_mod_cal((X+Y)/3, mod);
        ll below = (kaijo_mod_cal(a, mod)*kaijo_mod_cal(b, mod))%mod;

        //フェルマーの小定理より
        ll below_inv = modpow(below, mod-2, mod);

        ll ans = (above*below_inv)%mod;
        cout << ans << endl;
    }

    return 0;
}
