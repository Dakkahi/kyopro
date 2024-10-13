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
    ll N, M;
    cin >> N >> M;
    ll a[M+1], b[M+1];
    vector<ll> G[N+1];
    ll cnt[N+1];
    for(ll i = 1; i <= N; i++) cnt[i] = 0;
    for(ll i = 1; i <= M; i++) {
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        for(ll j : G[i]){
            if(i > j) cnt[i]++;
        }
        if(cnt[i] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}