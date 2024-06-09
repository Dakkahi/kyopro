#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
struct edge{
    ll to;
    ll cost;
};
using Graph = vector<vector<edge>>;




int main(){
    ll N, M;
    cin >> N >> M;
    ll A[M+1], B[M+1], C[M+1];
    ll dist[N+1];
    Graph G(N+1);
    //vector<bool> visited;
    if(M == 0) cout << -1 << endl;
    else{
    for(ll i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back({B[i], C[i]});
        G[B[i]].push_back({A[i], C[i]});
    }
    for(ll i = 1; i <= N; i++) {
        dist[i] = (1LL << 60);
        //visited[i] = false;
    }
    
    //ここからダイクストラ法
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    dist[1] = 0;
    //visited[1] = true;
    Q.push({0, 1}); //第一要素が重み、第二要素が頂点の名前
    while(!Q.empty()){
        ll pos = Q.top().second;
        Q.pop();
        //visited[pos] = true;
        for(edge e : G[pos]){
            ll to = e.to;
            ll cost = e.cost + dist[pos];
            if(dist[to] > cost){
                dist[to] = cost;
                Q.push({cost, to});
            }
        }
    }
    if(dist[N] == (1LL << 60)) cout << -1 << endl;
    else cout << dist[N] << endl;
    }
    return 0;
}