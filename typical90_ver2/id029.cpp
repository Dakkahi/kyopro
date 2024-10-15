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
    ll dat[500001];
    ll siz = 1;

    void init(ll N){
        while(N > siz) siz *= 2;
        for(ll i = 1; i <= 2*siz-1; i++) dat[i] = 0;
    }

    void update(ll pos, ll x){
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = max(dat[2*pos], dat[2*pos+1]);
        }
    }

    ll query(ll l, ll r, ll a, ll b, ll u){
        if(r <= a || b <= l) return -1000000;
        if(l <= a && b <= r) return dat[u];
        ll m = (a+b)/2;
        ll ansL = query(l, r, a, m, 2*u);
        ll ansR = query(l, r, m, b, 2*u+1);
        return max(ansL, ansR);
    }
};

int main(){
    ll W, N;
    cin >> W >> N;
    SegTree Z;
    Z.init(W);
    for(ll i = 1; i <= N; i++){
        ll L, R;
        cin >> L >> R;

    }
}