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
            siz[i] = 1;
            par[i] = -1;
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
            if(ru < rv){
                par[ru] = rv;
                siz[rv] += siz[ru];
            }
            else{
                par[rv] = ru;
                siz[ru] += siz[rv];
            }
        }
    }

    bool isconnected(ll u, ll v){
        return root(u) == root(v);
    }

};

int main(){
    ll N, M;
    cin >> N >> M;
    
    priority_queue<pair<ll, pair<ll, ll> >, vector<pair<ll, pair<ll, ll> > > > Q;

    unionfind U;
    U.init(N);
    for(ll i = 1; i <= M; i++){
        ll A, B, C;
        cin >> A >> B >> C;
        Q.push(make_pair(C, make_pair(A, B)));
    }

    ll sum = 0;
    for(ll i = 1; i <= M; i++){
        pair<ll, pair<ll, ll> > head = Q.top();
        Q.pop();
        if(!U.isconnected(head.second.first, head.second.second)){
            U.unite(head.second.first, head.second.second);
            sum += head.first;
        }
    }
    cout << sum << endl;
    return 0;
}
