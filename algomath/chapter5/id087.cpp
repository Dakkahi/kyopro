#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll mod = 1e9 + 7;
    ll ans = (N*(N+1)/2)%mod;
    ans = (ans*ans)%mod;
    cout << ans << endl;
    return 0;
}