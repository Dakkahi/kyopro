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
    ll p = a;
    for(ll i = 0; i <= 63; i++){
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
    ll a, b;
    cin >> a >> b;

    cout << pow_mod(a, b) << endl;
    return 0;
}