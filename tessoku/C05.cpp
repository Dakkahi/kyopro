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

int main(){
    ll N;
    cin >> N;

    ll n = N - 1;
    ll ans = 0;
    ll p = 1;
    for(ll i = 0; i < 10; i++){
        if((n & 1LL << i) != 0) ans += p*7;
        else ans += p*4;
        p *= 10;
    }
    cout << ans << endl;
    return 0;
}