#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

vector<ll> G[101];
bool visited[101];

void dfs(ll pos){
    visited[pos] = true;
    for(ll i : G[pos]){
        if(visited[i] == false) dfs(i);
    }
}

int main(){
    ll N, R;
     cin >> N >> R;

     ll x[N+1], y[N+1];
     for(ll i = 1; i <= N; i++) cin >> x[i] >> y[i];

     //N=100なので全探索で連結成分を形成していけば計算量的に間に合う
     for(ll i = 1; i <= N-1; i++){
        for(ll j = i+1; j <= N; j++){
            if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= 4*R*R){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
     }
     for(ll i = 1; i <= N; i++) visited[i] = false;

     ll cnt = 0;
     for(ll i = 1; i <= N; i++){
        if(visited[i] == false){
            cnt ++;
            dfs(i);
        }
     }
     cout << cnt << endl;
     return 0;
}