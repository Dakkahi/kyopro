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
    ll Mg;
    cin >> Mg;
    vector<ll> G[N+1];
    for(ll i = 1; i <= Mg; i++){
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll Mh;
    cin >> Mh;
    vector<ll> H[N+1];
    for(ll i = 1; i <= Mh; i++){
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll A[N+1][N+1];
    for(ll i = 1; i <= N-1; i++){
        for(ll j = i+1; j <= N; j++) cin >> A[i][j];
    }

    

}