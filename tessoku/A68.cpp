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
    ll to, cap, rev; //先のノード，容量，逆流する辺のインデックス
};

class MaximumFlow{
    public:
    ll size_ = 0;
    bool used[401]; //dfsで訪問済みか調べる
    vector<Edge> G[401];

    void init(ll N){ //残余グラフの準備
        size_ = N;
        for(ll i = 0; i <= size_; i++) G[i].clear();
    }

    void add_edge(ll u, ll v, ll c){ //頂点uからvに向かう，上限cの辺を追加
        ll current_Gu = G[u].size(); //uからvへ向かう辺のインデックス
        ll current_Gv = G[v].size(); //vからuへ向かう辺(逆流辺)のインデックス
        G[u].push_back(Edge{ v, c, current_Gv }); //u->vの容量cの辺を追加
        G[v].push_back(Edge{ u, 0, current_Gu }); //逆流用の辺．初期は0
    }

    //ゴールの到着すればフローを流せる
    //返り値はフローの量
    ll dfs(ll pos, ll goal, ll F){
        if(pos == goal) return F;
        used[pos] = true;

        for(ll i = 0; i < G[pos].size(); i++){
            //容量0の辺は飛ばす
            if(G[pos][i].cap == 0) continue;

            //すでに訪問した頂点には行かない
            if(used[G[pos][i].to] == true) continue;

            //目的地までのパスを探す
            ll flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

            if(flow >= 1){
                G[pos][i].cap -= flow; //辺の容量を減らす
                G[G[pos][i].to][G[pos][i].rev].cap += flow; //逆辺の容量を減らす
                return flow;
            }
        }
        //全ての辺を探索しても見つからなかったとき
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
    ll N, M;
    cin >> N >> M;
    ll A[M+1], B[M+1], C[M+1];
    MaximumFlow Z;

    for(ll i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];

    //辺の追加
    Z.init(N);
    for(ll i = 1; i <= M; i++) Z.add_edge(A[i], B[i], C[i]);

    cout << Z.max_flow(1, N) << endl;
    return 0;
}