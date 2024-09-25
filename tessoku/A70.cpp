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
    ll A[N+1];
    ll start = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        start += A[i]*(1LL << (i-1));
    }

    ll X[M+1], Y[M+1], Z[M+1];
    for(ll i = 1; i <= M; i++) cin >> X[i] >> Y[i] >> Z[i];

    vector<ll> G[(1LL << N)]; //全部OFFで0, 全部ONで2^N-1

    for(ll i = 1; i <= M; i++){
        ll flipbit = (1LL << (X[i]-1)) + (1LL << (Y[i]-1)) + (1LL << (Z[i]-1));
        for(ll j = 0; j < (1LL << N); j++) {
            G[j].push_back((j ^ flipbit));
        }
    }

    //幅優先
    ll goal = (1LL << N) - 1;

    queue<ll> Q;
    Q.push(start);

    ll dist[(1LL << N)+1];
    bool visited[(1LL << N)+1];
    for(ll i = 0; i < (1LL << N); i++){
        dist[i] = -1;
        visited[i] = false;
    }

    dist[start] = 0;
    while(!Q.empty()){
        ll head = Q.front();
        Q.pop();
        visited[head] = true;

        for(ll i : G[head]){
            if(visited[i] == false){
                Q.push(i);
                dist[i] = dist[head] + 1;
            }
        }
    }
    cout << dist[goal] << endl;
    return 0;
}