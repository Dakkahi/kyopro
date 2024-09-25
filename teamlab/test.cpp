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

ll mod = 1000000007;

ll prod_mod(ll a, ll b){ //a^bの計算を行う
    ll ans = 1;
    ll p = a;
    for(ll i = 0; i <= 60; i++){
        if((b & 1LL << i) != 0LL){
            ans *= p;
            ans %= mod;
        }
        p *= p;
        p %= mod;
    }
    return ans;
}

int main(){
    ll W;
    cin >> W;

    ll ans = (12*prod_mod(7, W-1))%mod;
    cout << ans << endl;
    return 0;

}