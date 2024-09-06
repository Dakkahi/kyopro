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
    ll A, B;
    vector<ll> G[N+1];
    for(ll i = 1; i <= M; i++){
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    ll dist[N+1];
    for(ll i = 1; i<= N; i++) dist[i] = -1;

    dist[1] = 0;
    
    queue<ll> Q;
    Q.push(1);
    while(!Q.empty()){
        ll head = Q.front();
        Q.pop();
        for(ll i : G[head]){
            if(dist[i] == -1){
                Q.push(i);
                dist[i] = dist[head] + 1;
            }
        }
    }

    for(ll i = 1; i <= N; i++){
        cout << dist[i] << endl;
    }
    return 0;
}