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
    vector<pair<ll, ll> > G[N+1]; //(pos, distance)
    ll A[M+1], B[M+1], C[M+1];

    for(ll i = 1; i <= M; i++){
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > Q; //(distance, key)の組み合わせ

    bool decided[N+1];
    ll cur[N+1];

    for(ll i = 1; i <= N; i++){
        decided[i] = false;
        cur[i] = 2e9;
    }

    cur[1] = 0;
    Q.push(make_pair(cur[1], 1));

    while(!Q.empty()){
        pair<ll, ll> head = Q.top();
        Q.pop();
        ll pos = head.second;
        if(decided[pos] == true) continue; 
        decided[pos] = true;

        for(ll i = 0; i < G[pos].size(); i++){
            ll nex = G[pos][i].first;
            ll cost = G[pos][i].second;
            if(cur[pos] + cost < cur[nex]){
                cur[nex] = cur[pos] + cost;
                Q.push(make_pair(cur[nex], nex));
            }
        }
    }

    stack<ll> S;
    S.push(N);
    ll head = S.top();
    while(head != 1){
        for(ll i = 0; i < G[head].size(); i++){
            ll nex = G[head][i].first;
            ll cost = G[head][i].second;
            if(cur[nex] + cost == cur[head]){
                S.push(nex);
                break;
            }
        }
        head = S.top();
    }
    while(!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }
    return 0;
}