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

class unionfind{
    public:
    ll par[100001]; //親のキー
    ll siz[100001]; //各グループのサイズ

    void init(ll N){
        for(ll i  =1; i <= N; i++){
            par[i] = -1;
            siz[i] = 1;
        }
    }
    //根を返す
    ll root(ll x){
        while(1){
            if(par[x] == -1) break;
            else x = par[x];
        }
        return x;
    }

    void unite(ll u, ll v){
        ll rootU = root(u);
        ll rootV = root(v);

        if(rootU == rootV) return;
        if(siz[rootU] < siz[rootV]){
            par[rootU] = rootV;
            siz[rootV] += siz[rootU];
        }
        else{
            par[rootV] = rootU;
            siz[rootU] += siz[rootV];
        }
    }

    string same(ll u, ll v){
        if(root(u) == root(v)) return "Yes";
        else return "No";
    }
};

int main(){
    ll N, Q;
    cin >> N >> Q;

    unionfind U;
    U.init(N);

    for(ll i = 1; i <= Q; i++){
        ll q, u, v;
        cin >> q >> u >> v;
        if(q == 1) U.unite(u, v);
        if(q == 2){
            string ans = U.same(u, v);
            cout << ans << endl;
        }
    }
    return 0;
}