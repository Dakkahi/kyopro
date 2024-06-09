#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    ll mod = 998244353;

    ll sumA_mod = (A*(A+1)/2)%mod;
    ll sumB_mod = (B*(B+1)/2)%mod;
    ll sumC_mod = (C*(C+1)/2)%mod;

    ll ans = (sumA_mod*sumB_mod)%mod;
    ans = (ans*sumC_mod)%mod;
    cout << ans << endl;
    return 0;

}