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
    vector<pair<ll, ll> > G[N+1]; //先のノードと距離

    ll A[M+1], B[M+1], C[M+1], D[M+1];

    for(ll i = 1; i <= M; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        G[A[i]].push_back(make_pair(B[i], 10000*C[i] - D[i]));
        G[B[i]].push_back(make_pair(A[i], 10000*C[i] - D[i]));
    }

    //ダイクストラ法
    bool decided[N+1];
    ll value[N+1];

    for(ll i = 1; i <= N; i++){
        decided[i] = false;
        value[i] = 1e15;
    }

    //decided[1] = true;
    value[1] = 0;

    priority_queue<pair<ll, ll> , vector<pair<ll, ll> >, greater<pair<ll, ll> > > Q; //(距離，頂点番号)

    Q.push(make_pair(0, 1));

    while(!Q.empty()){
        pair<ll, ll> head = Q.top();
        Q.pop();

        ll pos = head.second;

        if(decided[pos]) continue;

        decided[pos] = true;
        for(ll i = 0; i < G[pos].size(); i++){
            ll nexpos = G[pos][i].first;
            ll nexdist = G[pos][i].second;

            if(value[nexpos] > nexdist + value[pos]){
            value[nexpos] = nexdist + value[pos];
            Q.push(make_pair(value[nexpos], nexpos));
            }
        }
    }

    ll ans = (value[N] + 9999)/10000;
    ll numtree = ans*10000 - value[N];

    cout << ans << " " << numtree << endl;
    return 0;
}