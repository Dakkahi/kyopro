#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

ll div_mod(ll n, ll mod){
    return (n+mod)%mod;
}

int main(){
    ll mod = 10000;
    ll N;
    cin >> N;
    char T;
    ll A;
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> T >> A;
        if(T == '+'){
            ans = div_mod(ans + A, mod);
        }
        if(T == '*'){
            ans = div_mod(ans*A, mod);
        }
        if(T == '-'){
            ans = div_mod(ans-A, mod);
        }
        cout << ans << endl;
    }

    return 0;
}