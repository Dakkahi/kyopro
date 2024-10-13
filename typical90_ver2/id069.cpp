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

ll mod = 1e9+7;

ll prod_mod(ll a, ll b){
    ll ans = 1;
    ll p = a;
    for(ll i = 0; i < 60; i++){
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
    ll N, K;
    cin >> N >> K;
    ll ans = 1;
    if(N >= 1){
        ans *= K;
        ans %= mod;
    }
    if(N >= 2){
        ans *= (K-1);
        ans %= mod;
    }
    if(N >= 3){
        ll prod = prod_mod(K-2, N-2);
        ans *= prod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}