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
    ll siz[100001];
    ll par[100001];

    void init(ll N){
        for(ll i = 1; i <= N; i++){
            par[i] = -1;
            siz[i] = 1;
        }
    }

    ll root(ll x){
        while(1){
            if(par[x] == -1) break;
            else x = par[x];
        }
        return x;
    }

    void unite(ll u, ll v){
        ll ru = root(u);
        ll rv = root(v);

        if(ru == rv) return;
        else{
            if(siz[ru] < siz[rv]){
                par[ru] = rv;
                siz[rv] += siz[ru];
            }
            else{
                par[rv] = ru;
                siz[ru] += siz[rv];
            }
        }
    }

    string ans(ll u, ll v){
        if(root(u) == root(v)) return "Yes";
        else return "No"; 
    }
};

int main(){
    ll N, M;
    cin >> N >> M;
    ll A[M+1], B[M+1];
    bool canceled[M+1];
    for(ll i = 1; i<= M; i++) {
        cin >> A[i] >> B[i];
        canceled[i] = false;
    }

    

    ll Q;
    cin >> Q;
    ll q[Q+1];
    ll u[Q+1], v[Q+1];
    ll x[Q+1];
    for(ll i = 1; i <= Q; i++){
        cin >> q[i];
        if(q[i] == 1){
            cin >> x[i];
            canceled[x[i]] = true;
        }
        if(q[i] == 2){
            cin >> u[i] >> v[i];
        }
    }

    unionfind U;
    U.init(N);
    stack<string> S;

    for(ll i = 1; i <= M; i++){
        if(!canceled[i]) U.unite(A[i], B[i]);
    }

    for(ll i = Q; i >= 1; i--){
        if(q[i] == 2) S.push(U.ans(u[i], v[i]));
        if(q[i] == 1) U.unite(A[x[i]], B[x[i]]); 
    }

    while(!S.empty()){
        cout << S.top() << endl;
        S.pop();
    }
    return 0;
}

