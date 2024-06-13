#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;


int main(){
    ll N;
    cin >> N;
    ll mod = 1000000007;
    ll A[N*6+1];
    for(ll i = 1; i <= N*6; i++) cin >> A[i];

    ll S[N+1];
    for(ll i = 1; i <= N; i++) S[i] = 0;

    ll ans = 1;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= 6; j++){
            S[i] += A[(i-1)*6 + j];
            S[i] %= mod;
        }
        ans *= S[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}