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
    ll N, M;
    cin >> N >> M;
    bool visited[N+1];
    vector<ll> G[N+1];
    ll a[M+1], b[M+1];

    for(ll i = 1; i <= M; i++){
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    for(ll i = 1; i <= N; i++) visited[i] = false;

    queue<ll> Q;
    ll pos = 1;
    visited[pos] = true;
    Q.push(pos);
    ll ans = 0;
    while(!Q.empty()){
        ll cnt = 0;
        pos = Q.front();
        Q.pop();
        visited[pos] = true;
        for(ll i : G[pos]){
            if(pos > i) cnt++;
            if(!visited[i]){
                Q.push(i);
                visited[i] = true;
            }
        }
        if(cnt == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}