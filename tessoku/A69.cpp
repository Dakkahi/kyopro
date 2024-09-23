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

struct Edge{
    ll to, cap, rev;
};

class MaximumFlow{
    public:
    ll size_ = 0;
    bool used[901];
    vector<Edge> G[901];

    void init(ll N){
        size_ = 2*N+2;
        for(ll i = 0; i <= size_; i++) G[i].clear();
    }

    void add_edge(ll u, ll v, ll c){
        ll current_Gu = G[u].size();
        ll current_Gv = G[v].size();
        G[u].push_back(Edge{ v, c, current_Gv }); //u->vの容量cの辺を追加
        G[v].push_back(Edge{ u, 0, current_Gu }); //逆流用の辺．初期は0
    }

    ll dfs(ll pos, ll goal, ll F){
        if(pos == goal) return F;
        used[pos] = true;

        for(ll i = 0; i < G[pos].size(); i++){
            if(G[pos][i].cap == 0) continue;

            if(used[G[pos][i].to] == true) continue;

            ll flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

            if(flow >= 1){
                G[pos][i].cap -= flow; //辺の容量を減らす
                G[G[pos][i].to][G[pos][i].rev].cap += flow; //逆辺の容量を減らす
                return flow;
            }
        }

        return 0;
    }

   //頂点Sからtまでの最大フローを返す
    ll max_flow(ll s, ll t){
        ll total_flow = 0;
        while(1){
            for(ll i = 0; i <= size_; i++) used[i] = false;
            ll F = dfs(s, t, 1e9);

            //フローがなくなれば操作終了
            if(F == 0) break;
            total_flow += F;
        }
        return total_flow;
    }
};

int main(){
    ll N;
    cin >> N;
    char C[N+1][N+1];

    MaximumFlow Z;
    Z.init(N);

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++) {
            cin >> C[i][j];
            if(C[i][j] == '#') Z.add_edge(i, N+j, 1);
        }
    }

    for(ll i = 1; i <= N; i++){
        Z.add_edge(2*N+1, i, 1); //スタート地点は2N+1
        Z.add_edge(N+i, 2*N+2, 1); //ゴール地点は2N+2
    }

    cout << Z.max_flow(2*N+1, 2*N+2) << endl;
    return 0;
}