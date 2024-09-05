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

class SegTree{
    public:
    ll dat[300001];
    ll siz = 1;

    void init(ll N){
        while(N > siz) siz *= 2;
        for(ll i = 1; i < siz; i++) dat[i] = 0;
    }

    void update(ll pos, ll x){
        pos += siz - 1;
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = dat[2*pos] + dat[2*pos+1];
        }
    }

    ll query(ll l, ll r, ll a, ll b, ll u){
        if(b <= l || r <= a) return 0;
        if(l <= a && b <= r) return dat[u];
        ll m = (a+b)/2;
        ll ansL = query(l, r, a, m, u*2);
        ll ansR = query(l, r, m, b, u*2+1);
        return ansL + ansR;
    }
};

int main(){
    ll N, Q;
    cin >> N >> Q;
    SegTree Z;
    Z.init(N);
    for(ll i = 1; i <= Q; i++){
        ll q;
        cin >> q;
        if(q == 1){
            ll pos, x;
            cin >> pos >> x;
            Z.update(pos, x);
        }
        if(q == 2){
            ll l, r;
            cin >> l >> r;
            ll sum = Z.query(l, r, 1, Z.siz+1, 1);
            cout << sum << endl;
        }
    }
    return 0;
}